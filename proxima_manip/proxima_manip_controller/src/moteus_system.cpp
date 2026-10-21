#include "proxima_manip_controller/moteus_system.hpp"

#include <exception>

#include "hardware_interface/types/hardware_interface_type_values.hpp"


namespace proxima_manip_controller
{

hardware_interface::CallbackReturn MoteusSystem::on_init(
  const hardware_interface::HardwareComponentInterfaceParams & params)
{
  if (hardware_interface::SystemInterface::on_init(params) !=
    hardware_interface::CallbackReturn::SUCCESS)
  {
    return hardware_interface::CallbackReturn::ERROR;
  }

  if(info_.joints.size() != 3)
  {
    RCLCPP_ERROR(rclcpp::get_logger(""), "Invalid number of Moteus joints.");
    return hardware_interface::CallbackReturn::ERROR;
  }

  joints_.clear();
  for(const auto& joint : info_.joints)
  {
    MoteusJoint new_joint = MoteusJoint();

    int can_id = std::stoi(joint.parameters.at("can_id"));
    double effort_max = std::stod(joint.parameters.at("effort_max"));

    if(joint.command_interfaces.size() != 1)
    {
      RCLCPP_FATAL(
        get_logger(), "Joint '%s' has %zu command interfaces found. 1 expected.",
        joint.name.c_str(), joint.command_interfaces.size());
      return hardware_interface::CallbackReturn::ERROR;
    }

    if(joint.command_interfaces[0].name != hardware_interface::HW_IF_POSITION)
    {
      RCLCPP_FATAL(
        get_logger(), "Joint '%s' have %s command interface. '%s' expected.", joint.name.c_str(),
        joint.command_interfaces[0].name.c_str(), hardware_interface::HW_IF_POSITION);
      return hardware_interface::CallbackReturn::ERROR;
    }

    if(joint.state_interfaces.size() != 3)
    {
      {
        RCLCPP_FATAL(
          get_logger(), "Joint '%s' has %zu state interfaces found. 3 expected.",
          joint.name.c_str(), joint.state_interfaces.size());
        return hardware_interface::CallbackReturn::ERROR;
      }
    }

    if(joint.state_interfaces[0].name != hardware_interface::HW_IF_POSITION)
    {
      RCLCPP_FATAL(
        get_logger(), "Joint '%s' have %s state interface. '%s' expected.", joint.name.c_str(),
        joint.state_interfaces[0].name.c_str(), hardware_interface::HW_IF_POSITION);
      return hardware_interface::CallbackReturn::ERROR;
    }

    if(joint.state_interfaces[1].name != hardware_interface::HW_IF_VELOCITY)
    {
      RCLCPP_FATAL(
        get_logger(), "Joint '%s' have %s state interface. '%s' expected.", joint.name.c_str(),
        joint.state_interfaces[1].name.c_str(), hardware_interface::HW_IF_VELOCITY);
      return hardware_interface::CallbackReturn::ERROR;
    }

    if(joint.state_interfaces[2].name != hardware_interface::HW_IF_EFFORT)
    {
      RCLCPP_FATAL(
        get_logger(), "Joint '%s' have %s state interface. '%s' expected.", joint.name.c_str(),
        joint.state_interfaces[2].name.c_str(), hardware_interface::HW_IF_EFFORT);
      return hardware_interface::CallbackReturn::ERROR;
    }

    new_joint.joint_position_interface = joint.name + "/" + hardware_interface::HW_IF_POSITION;
    new_joint.joint_velocity_interface = joint.name + "/" + hardware_interface::HW_IF_VELOCITY;
    new_joint.joint_effort_interface = joint.name + "/" + hardware_interface::HW_IF_EFFORT;
    new_joint.can_id = can_id;
    new_joint.effort_max = effort_max;

    joints_.push_back(new_joint);
  }

  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::CallbackReturn MoteusSystem::on_configure(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  // TODO: implement

  try
  {
    transport_ = mjbots::moteus::Controller::MakeSingletonTransport({});
  }
  catch(const std::exception& e)
  {
    RCLCPP_ERROR(
      get_logger(), e.what()
    );
    return hardware_interface::CallbackReturn::ERROR;
  }

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

hardware_interface::CallbackReturn MoteusSystem::on_cleanup(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  // TODO: implement
  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::CallbackReturn MoteusSystem::on_shutdown(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  // TODO: implement
  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::CallbackReturn MoteusSystem::on_error(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  // TODO: implement
  return hardware_interface::CallbackReturn::SUCCESS;
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