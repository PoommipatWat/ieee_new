#include <micro_ros_arduino.h>

#include <stdio.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <rmw_microros/rmw_microros.h>
#include <rcl/init_options.h> 

#include <std_msgs/msg/int32.h>
#include <geometry_msgs/msg/twist.h>

#include "encoder.h"
Encoder Encoder;

#include "imu.h"
Imu Imu;

#include "drive.h"
Drive Drive;

#define LED_PIN -1
#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){return false;}}
#define EXECUTE_EVERY_N_MS(MS, X)  do { \
  static volatile int64_t init = -1; \
  if (init == -1) { init = uxr_millis();} \
  if (uxr_millis() - init > MS) { X; init = uxr_millis();} \
} while (0)\

rclc_support_t support;
rcl_node_t node;
rcl_allocator_t allocator;

rcl_timer_t timer;
rclc_executor_t executor_pub;
rcl_publisher_t publisher_encoder;
rcl_publisher_t publisher_imu;
geometry_msgs__msg__Twist msg_encoder;
geometry_msgs__msg__Twist msg_imu;

rcl_subscription_t subscriber_drive;
geometry_msgs__msg__Twist msg_drive;
rclc_executor_t executor_sub;

bool micro_ros_init_successful;

enum states {
  WAITING_AGENT,
  AGENT_AVAILABLE,
  AGENT_CONNECTED,
  AGENT_DISCONNECTED
} state;

void timer_callback(rcl_timer_t * timer, int64_t last_call_time)
{
  (void) last_call_time;
  if (timer != NULL) {
    msg_encoder.linear.x = Encoder.get_encoder_left();
    msg_encoder.angular.x = Encoder.get_encoder_right();
    msg_encoder.linear.y = Encoder.get_rpm_left();
    msg_encoder.angular.y = Encoder.get_rpm_right();
    rcl_publish(&publisher_encoder, &msg_encoder, NULL);

    msg_imu.linear.x = Imu.get_roll();
    msg_imu.linear.y = Imu.get_pitch();
    msg_imu.linear.z = Imu.get_yaw();
    msg_imu.angular.x = Imu.get_g_x();
    msg_imu.angular.y = Imu.get_g_y();
    msg_imu.angular.z = Imu.get_g_z();    
    rcl_publish(&publisher_imu, &msg_imu, NULL);
  }
}

void subscription_callback(const void *msgin) {
  const geometry_msgs__msg__Twist * msg_drive = (const geometry_msgs__msg__Twist *)msgin;
  Drive.set_drive_left(msg_drive->linear.x, msg_drive->linear.y, msg_drive->linear.z);
  Drive.set_drive_right(msg_drive->angular.x, msg_drive->angular.y, msg_drive->angular.z);
}

bool create_entities()
{
  allocator = rcl_get_default_allocator();

  // Create and configure init_options with domain ID 10
  rcl_init_options_t init_options = rcl_get_zero_initialized_init_options();
  RCCHECK(rcl_init_options_init(&init_options, allocator));
  RCCHECK(rcl_init_options_set_domain_id(&init_options, 10));

  // create init_options
  RCCHECK(rclc_support_init_with_options(&support, 0, NULL, &init_options, &allocator));

  rcl_init_options_fini(&init_options); // Clean up init_options

  // create node
  RCCHECK(rclc_node_init_default(&node, "encoder_node", "", &support));

  // create publisher
  RCCHECK(rclc_publisher_init_best_effort(
    &publisher_encoder,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
    "encoder_topic"));

  // create publisher
  RCCHECK(rclc_publisher_init_best_effort(
    &publisher_imu,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
    "imu_topic"));

  // create timer,
  const unsigned int timer_timeout = 10;
  RCCHECK(rclc_timer_init_default(
    &timer,
    &support,
    RCL_MS_TO_NS(timer_timeout),
    timer_callback));

  // create executor
  executor_pub = rclc_executor_get_zero_initialized_executor();
  RCCHECK(rclc_executor_init(&executor_pub, &support.context, 1, &allocator));
  RCCHECK(rclc_executor_add_timer(&executor_pub, &timer));

  // create subscriber
  RCCHECK(rclc_subscription_init_default(
    &subscriber_drive,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
    "control_drive_topic"));

  // create executor
  executor_sub = rclc_executor_get_zero_initialized_executor();
  RCCHECK(rclc_executor_init(&executor_sub, &support.context, 1, &allocator));
  RCCHECK(rclc_executor_add_subscription(&executor_sub, &subscriber_drive, &msg_drive, &subscription_callback, ON_NEW_DATA));

  return true;
}

void destroy_entities()
{
  rmw_context_t * rmw_context = rcl_context_get_rmw_context(&support.context);
  (void) rmw_uros_set_context_entity_destroy_session_timeout(rmw_context, 0);

  rcl_publisher_fini(&publisher_encoder, &node);
  rcl_publisher_fini(&publisher_imu, &node);
  rcl_timer_fini(&timer);
  rclc_executor_fini(&executor_pub);
  rcl_subscription_fini(&subscriber_drive, &node);
  rclc_executor_fini(&executor_sub);
  rcl_node_fini(&node);
  rclc_support_fini(&support);
}

void setup() {
  set_microros_transports();
  pinMode(LED_PIN, OUTPUT);

  state = WAITING_AGENT;

  Encoder.setup();
  Imu.setup();
}

void loop() {
  switch (state) {
    case WAITING_AGENT:
      EXECUTE_EVERY_N_MS(500, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_AVAILABLE : WAITING_AGENT;);
      break;
    case AGENT_AVAILABLE:
      state = (true == create_entities()) ? AGENT_CONNECTED : WAITING_AGENT;
      if (state == WAITING_AGENT) {
        destroy_entities();
      };
      break;
    case AGENT_CONNECTED:
      EXECUTE_EVERY_N_MS(200, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_CONNECTED : AGENT_DISCONNECTED;);
      if (state == AGENT_CONNECTED) {
        Encoder.loop();
        Imu.loop();
        rclc_executor_spin_some(&executor_pub, RCL_MS_TO_NS(5));
        rclc_executor_spin_some(&executor_sub, RCL_MS_TO_NS(5));
      }
      break;
    case AGENT_DISCONNECTED:
      destroy_entities();
      state = WAITING_AGENT;
      break;
    default:
      break;
  }

  if (state == AGENT_CONNECTED) {
    digitalWrite(LED_PIN, 1);
  } else {
    digitalWrite(LED_PIN, 0);
  }

}
