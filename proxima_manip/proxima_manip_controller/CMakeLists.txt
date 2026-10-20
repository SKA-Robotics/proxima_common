cmake_minimum_required(VERSION 3.16)
project(proxima_manip_controller)

find_package(ament_cmake_auto REQUIRED)

ament_auto_find_build_dependencies()

include(FetchContent)
FetchContent_Declare(
  moteus
  GIT_REPOSITORY https://github.com/mjbots/moteus.git
  GIT_TAG        release/cpp-1.0.x
)
FetchContent_MakeAvailable(moteus)

ament_auto_add_library(${PROJECT_NAME} SHARED
  src/moteus_system.cpp
  src/dynamixel_system.cpp
)

target_link_libraries(${PROJECT_NAME} moteus::cpp)

pluginlib_export_plugin_description_file(hardware_interface proxima_manip_controller.xml)

ament_auto_package()
