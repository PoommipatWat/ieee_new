from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()

    node_microros = Node(package="micro_ros_agent", executable="micro_ros_agent",
                         output='screen', arguments=['serial', '--dev', '/dev/ttyUSB0'])
    node_control = Node(package="ieee_pkg", executable="control_node")
    node_robot_core = Node(package="ieee_pkg", executable="robot_core_node")
    node_camera = Node(package="ieee_pkg", executable="camera_node")
    node_imu = Node(package="ieee_pkg", executable="imu_node")

    ld.add_action(node_microros)
    ld.add_action(node_control)
    ld.add_action(node_robot_core)
    # ld.add_action(node_camera)
    # ld.add_action(node_imu)

    return ld
