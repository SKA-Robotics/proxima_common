#include "proxima_manip_controller/dynamixel_system.hpp"

namespace proxima_manip_controller
{

hardware_interface::CallbackReturn DynamixelSystem::on_init(
  const hardware_interface::HardwareInfo & info)
{
  if (hardware_interface::SystemInterface::on_init(info) !=
    hardware_interface::CallbackReturn::SUCCESS)
  {
    return hardware_interface::CallbackReturn::ERROR;
  }

  // TODO: implement
  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::CallbackReturn DynamixelSystem::on_configure(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  // TODO: implement
  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::CallbackReturn DynamixelSystem::on_activate(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  // TODO: implement
  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::CallbackReturn DynamixelSystem::on_deactivate(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  // TODO: implement
  return hardware_interface::CallbackReturn::SUCCESS;
}

std::vector<hardware_interface::StateInterface> DynamixelSystem::export_state_interfaces()
{
  // TODO: implement
  return {};
}

std::vector<hardware_interface::CommandInterface> DynamixelSystem::export_command_interfaces()
{
  // TODO: implement
  return {};
}

hardware_interface::return_type DynamixelSystem::read(
  const rclcpp::Time & /*time*/, const rclcpp::Duration & /*period*/)
{
  // TODO: implement
  return hardware_interface::return_type::OK;
}

hardware_interface::return_type DynamixelSystem::write(
  const rclcpp::Time & /*time*/, const rclcpp::Duration & /*period*/)
{
  // TODO: implement
  return hardware_interface::return_type::OK;
}

}  // namespace proxima_manip_controller

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
  proxima_manip_controller::DynamixelSystem, hardware_interface::SystemInterface)
