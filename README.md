# Syskos

A utility library focused on working with the Windows console host (conhost), providing APIs to extract display-related environment information and to control a console application's window in a consistent manner across systems. The library offers compact utilities for querying screens, work areas, and display sizes, as well as for manipulating the position and dimensions of the console window itself.

## Features

* Move the console window to predefined screen positions or custom coordinates
* Resize the console window by pixels or by character columns and rows
* Get the console window position and size
* Enable or disable console window resizing
* Support both visual (shadow-aware) and legacy window handling

## Requirements

* Operating System: Windows
* C++ compiler with C++20 support or later (MSVC, MinGW, Clang)
* CMake 3.25+

## Getting Started

### Integration (Recommended: FetchContent)

Syskos is designed to be easily consumed via CMake’s `FetchContent` module.

Add the following to your project’s `CMakeLists.txt`:

```cmake
include(FetchContent)

FetchContent_Declare(
    syskos
    GIT_REPOSITORY https://github.com/GeMiNiOranGe/Syskos.git
    GIT_TAG main # or a specific release/tag
)

FetchContent_MakeAvailable(syskos)
```

Then link Syskos to your target:

```cmake
target_link_libraries(<your_target> PRIVATE syskos)
```

Include the header in your source code:

```cpp
#include <Syskos/Syskos.hpp>
```

### Building Syskos Standalone (Optional)

If you want to build Syskos by itself:

```bash
cmake -S . -B build
cmake --build build
```

The output will be placed in the `build` directory.

## Examples

Syskos provides a set of example programs demonstrating how to use the library.

### Enable examples

Examples are **disabled by default**. To build them, enable the corresponding CMake option:

```bash
cmake -S . -B build -DSYSKOS_BUILD_EXAMPLES=ON
```

### Build

```bash
# Build all examples
cmake --build build

# Or just one
cmake --build build --target 00_PrintVersion
```

### Run examples

After building, example executables will be located in:

```
build/examples/
```

You can run them directly, for example:

```bash
./build/examples/00_PrintVersion.exe
# OR
./build/examples/Debug/00_PrintVersion.exe
```

> NOTE: On Windows, you may need to run the examples from a console window (cmd or PowerShell) to see the expected behavior.

## License

*Not available*
