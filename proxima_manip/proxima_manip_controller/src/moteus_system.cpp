#include "proxima_manip_controller/moteus_system.hpp"

namespace proxima_manip_controller
{

hardware_interface::CallbackReturn MoteusSystem::on_init(
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

hardware_interface::CallbackReturn MoteusSystem::on_configure(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  // TODO: implement
  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::CallbackReturn MoteusSystem::on_activate(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  // TODO: implement
  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::CallbackReturn MoteusSystem::on_deactivate(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  // TODO: implement
  return hardware_interface::CallbackReturn::SUCCESS;
}

std::vector<hardware_interface::StateInterface> MoteusSystem::export_state_interfaces()
{
  // TODO: implement
  return {};
}

std::vector<hardware_interface::CommandInterface> MoteusSystem::export_command_interfaces()
{
  // TODO: implement
  return {};
}

hardware_interface::return_type MoteusSystem::read(
  const rclcpp::Time & /*time*/, const rclcpp::Duration & /*period*/)
{
  // TODO: implement
  return hardware_interface::return_type::OK;
}

hardware_interface::return_type MoteusSystem::write(
  const rclcpp::Time & /*time*/, const rclcpp::Duration & /*period*/)
{
  // TODO: implement
  return hardware_interface::return_type::OK;
}

}  // namespace proxima_manip_controller

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
  proxima_manip_controller::MoteusSystem, hardware_interface::SystemInterface)
