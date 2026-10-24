# proxima_description

Physical description (URDF/Xacro) of the Proxima rover: kinematics, visual and
collision meshes, and inertial parameters.

## File structure

| Directory          | Contents |
|--------------------|----------|
| [robots](robots)   | Top-level `.xacro` files, the entry points passed to `xacro`. The rover model is `proxima.urdf.xacro`. |
| [urdf](urdf)       | Macros and component descriptions (base, manipulators, cameras) included by the top-level files. |
| [meshes](meshes)   | Visual and collision meshes (`.stl`). |
| [config](config)   | Mechanical dimensions, inertial parameters and RViz configuration. |
| [launch](launch)   | Launch files. |

## Model arguments

`robots/proxima.urdf.xacro` takes two xacro arguments, which the launch files pass through:

| Argument           | Values          | Default | Description |
|--------------------|-----------------|---------|-------------|
| `manipulator`      | `none`, `6DOF`  | `none`  | Manipulator to attach to the base. |
| `manipulator_only` | `true`, `false` | `false` | Skip the base. The manipulator is attached to an empty `base_link`. |

## Building

```bash
cd ~/proxima
rosdep install --from-paths src/proxima_common/proxima_description --ignore-src -y
colcon build --symlink-install --packages-select proxima_description
source install/setup.bash
```

## Launching

### `proxima_description.launch.py`

Starts only `robot_state_publisher`, which publishes `/robot_description` and TF.
Use it as part of a larger bringup. Something else, such as `joint_state_broadcaster`,
has to publish the states of the movable joints.

```bash
ros2 launch proxima_description proxima_description.launch.py
ros2 launch proxima_description proxima_description.launch.py manipulator:=6DOF
ros2 launch proxima_description proxima_description.launch.py manipulator:=6DOF manipulator_only:=true
```

| Argument           | Default |
|--------------------|---------|
| `manipulator`      | `none`  |
| `manipulator_only` | `false` |

### `display.launch.py`

Visualizes the model in RViz. Starts `robot_state_publisher`, `joint_state_publisher_gui`
(sliders for moving the joints) and RViz with `config/manip_visualization.rviz`.

```bash
ros2 launch proxima_description display.launch.py
ros2 launch proxima_description display.launch.py manipulator:=6DOF
ros2 launch proxima_description display.launch.py manipulator:=6DOF manipulator_only:=true
ros2 launch proxima_description display.launch.py rviz_config:=/path/to/config.rviz
```

| Argument           | Default |
|--------------------|---------|
| `manipulator`      | `none`  |
| `manipulator_only` | `false` |
| `rviz_config`      | `config/manip_visualization.rviz` |

## Validating the model

```bash
xacro $(ros2 pkg prefix proxima_description)/share/proxima_description/robots/proxima.urdf.xacro manipulator:=6DOF > /tmp/proxima.urdf
check_urdf /tmp/proxima.urdf
```
