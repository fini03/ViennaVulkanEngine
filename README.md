# The Vienna Vulkan Engine (VVE)
The Vienna Vulkan Engine (VVVE) is a Vulkan based render engine meant for learning and teaching the Vulkan API. It is open source under the MIT license. The VVE has been started as basis for game based courses at the Faculty of Computer Science of the University of Vienna, held by Prof. Helmut Hlavacs:

- https://ufind.univie.ac.at/de/course.html?lv=052212&semester=2023W
- https://ufind.univie.ac.at/de/course.html?lv=052211&semester=2023S
- https://ufind.univie.ac.at/de/course.html?lv=052214&semester=2023S

VVE's main contributor is Prof. Helmut Hlavacs (http://entertain.univie.ac.at/~hlavacs/). However, VVE will be heavily involved in the aforementioned courses, and other courses as well, and many students are already working on VVE extensions, porting, debugging etc.

VVE features are:
- 100% Vulkan, C++20
- Windowing through GLFW, other systems are possible.
- Multiplatform (almost) out of the box: Win 10, Linux, MacOS (using MoltenVK). See instructions below.
- Separation between the engine itself and an independent Vulkan helper layer below. The engine usually does not call Vulkan functions directly, but rather only helper functions, acting like macros. This reduces complexity.
- Simple callback usage through event listeners.
- Uses several OSS libraries and  - if-possible - single-header libraries for loading assets, multithreading, etc.
- Documentation with Doxygen
- Multiplatform (almost) out of the box: Win 11, Linux, MacOS (using MoltenVK). See instructions below.
- Separation between the engine itself and an independent Vulkan helper layer below. The engine usually does not call Vulkan functions directly, but rather only helper functions, acting like macros. This reduces complexity.
- Simple callback usage through event listeners.
- Uses several OSS libraries and - if possible - single-header libraries for loading assets, multithreading, etc.
- Simple GUI based on the Nuklear library, other libraries like ImGUI are possible.
- Uses AMD's VMA Library for memory allocation.


# Set up for Windows 11

The VVE must be compiled into a static link library, under Windows 11 this is a lib file. Do the following:
- Make sure you have an up to date CMake, MS Visual Studio 22 and the Vulkan SDK installed.
- Clone both projects Vienna Vulkan Engine and Vienna Physics Engine, into the same directory, next to each other.
- Cd into Vienna Vulkan Engine and run CMake. Alternatively run the msvc bat file. CMake creates an sln project file.
- Open the sln file and compile the project. Sometimes compile it twice to make sure everything is done correctly.
- You might also manually compile the doxyfile subproject to create the documentation. For this you must have Doxygen installed.

The project will be updated regularly, so it makes sense to pull the newest version regularly.

# Set up for Linux

The engine has been tested on archlinux with wayland and the Intel driver. First to install vulkan follow the installation guide from [archlinux](https://wiki.archlinux.org/title/Vulkan). Afterwards the following dependencies are needed for building:
```
pacman -S base-devel cmake assimp glfw-wayland glm stb vulkan-devel
```
For X11 users install `glfw-x11` instead of `glfw-wayland`.

### Building
- Clone both projects Vienna Vulkan Engine and Vienna Physics Engine, into the same directory, next to each other
- Cd into Vienna Vulkan Engine and create a build folder and run CMake there
- Run make
- Go back to the root folder and cd into `/bin/Release` where the binary is located
- Execute the binary

List of commands:
```
cd ViennaVulkanEngine
mkdir build
cd build
cmake ..
make
cd ..
cd bin/Release
./simplegame
```

P.S.: Incase the binary crashes while using the newest `vulkan-intel` driver, download the following driver `vulkan-intel-23.1.4-2-x86_64.pkg.tar.zst 23-Jul-2023 00:06` from [here](https://archive.archlinux.org/packages/v/vulkan-intel/). Execute the following command then:
```
sudo pacman -U /path/to/vulkan-intel-23.1.4-2-x86_64.pkg.tar.zst
```

# How to use Vienna Vulkan Engine

VVE lets you load assets from disk, create arbitrary scene graphs, and render objects with shadows. See the examples folder for a simple example game.
