# proxima_description package
This package provides the physical description (URDF/Xacro) of the Proxima rover.

## Launching

TODO

## File structure
The package is organized into the following directories:
- [config](config) - Configuration files (inertia, weights, and ros2_control interfaces).
- [meshes](meshes) - Visual and collision files (.stl).
- [robots](robots) - Main top-level .xacro file for the Proxima rover.
- [urdf](urdf) - Macro definitions and component descriptions (submodules).
- [launch](launch) - Launch files.