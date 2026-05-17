import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import Command, LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue

def generate_launch_description():
    package_name = 'proxima_description'
    xacro_file_name = 'proxima.urdf.xacro' 
    
    pkg_path = get_package_share_directory(package_name)
    # Make sure this matches where your file actually is (urdf vs robots)
    xacro_path = os.path.join(pkg_path, 'robots', xacro_file_name)

    manipulator_version_arg = DeclareLaunchArgument(
        'manipulator',
        default_value='none',
        description='Manipulator version'
    )

    robot_description = ParameterValue(
        Command(['xacro ', xacro_path, ' manipulator:=', LaunchConfiguration('manipulator')]),
        value_type=str
    )

    # 1. The Core Publisher (You already had this)
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': robot_description}]
    )

    # 2. The Slider GUI for moving joints
    joint_state_publisher_gui_node = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        name='joint_state_publisher_gui'
    )

    # 3. RViz2 for 3D visualization
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen'
    )

    return LaunchDescription([
        manipulator_version_arg,
        robot_state_publisher_node,
        joint_state_publisher_gui_node,
        rviz_node
    ])