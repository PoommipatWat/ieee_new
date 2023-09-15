from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='webcam_pkg',
            executable='webcam_node',
            output='screen',
        ),
        Node(
            package='ieee_pkg',
            executable='control_ieee_node',
            output='screen',
        ),
        # Node(
        #     package='xicro_pkg',
        #     namespace=None,
        #     executable='xicro_node_ieee_ID_1_esp.py',
        # ),
    ])