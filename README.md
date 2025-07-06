# Moo もう

Moo is used for complex math calculations in a simple way. A library with millions of different formulars.

# Installation

## Windows 64bit

### Installation

1. Select the desire programming language you want to use.
2. Download the latest released api from the [Moo もう Releases]()
3. Extract the downloaded file.
4. Copy the .dll and the .* to your project.
5. Ensure that the .dll is in the same directory as your executable or in a directory that is included in your system's
   PATH environment variable.

### For C++/C

You have two options to use Moo もう in C++/C:

1. Use the provided .dll file and include the `moo_dll.hpp` header file in your project.
2. Use the source code directly by including the `moo.hpp` header file and linking against the provided .lib file.

Download the latest release from the [Moo もう Releases](https://github.com/DevKiDCosmo/Moo/releases)

## Linux 64bit

### Installation

1. Select the desire programming language you want to use.
2. Download the latest released api from the [Moo もう Releases]()
3. Extract the downloaded file.
4. Copy the .so and the .* to your project. Pay attention to the architecture of your system (x86_64, arm64, etc.) and
   the prefix of the file. It should be `UNIX` for the code files for Linux.
5. Ensure that the .so is in the same directory as your executable or in a directory that is included in your system's
   LD_LIBRARY_PATH environment variable.

### For C++/C

You have two options to use Moo もう in C++/C:

1. Use the provided .so file and include the `UNIX-moo_dll.hpp` header file in your project.
2. Use the source code directly by including the `UNIX-moo.hpp` header file and linking against the provided .a file.

# Export

- .dll, .so, .a, .lib
- Python, C, C++, C#, Java, Go, Rust, Ruby, PHP, Perl, Lua, Swift, Kotlin, Dart, JavaScript, TypeScript

Source Code for C++/C and Python is available on GitHub: [Moo もう](https://github.com/DevKiDCosmo/Moo).

# Building from Source

Moo もう supports multiple build systems for cross-platform compilation:

## Prerequisites

- C++23 compatible compiler (GCC 13+, Clang 16+, MSVC 19.30+)
- Either Meson + Ninja or CMake
- Python 3.6+ (for Python bindings)

## Using Meson (Recommended)

Meson provides excellent cross-platform support and automatic dependency detection.

### Installation

```bash
pip install meson ninja
```

### Building

```bash
# Debug build
meson setup builddir
meson compile -C builddir

# Release build
meson setup builddir-release --buildtype=release
meson compile -C builddir-release
```

### Supported Platforms

- **Windows**: Generates `.dll` files with MSVC, MinGW, or Clang
- **Linux**: Generates `.so` files with GCC or Clang
- **macOS**: Generates `.dylib` files with Clang
- **BSD variants**: FreeBSD, OpenBSD, NetBSD, DragonFly BSD
- **Solaris**: Native and GNU toolchains
- **Cygwin/MSYS2**: Windows POSIX environment

The build system automatically detects your platform and configures appropriate compiler flags and library export mechanisms.

## Using CMake

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Testing

After building, you can test the library functionality:

```bash
# Run Python tests (works with both build systems)
python3 test/dllst.py  # Original test for Windows
# or create a cross-platform test
```

## Output Files

- **Debug builds**: `libMoo.so` / `moo.dll` / `libMoo.dylib`
- **Release builds**: `libMooMeson.so` / `MooMeson.dll` / `libMooMeson.dylib`

The libraries are built with proper symbol visibility for optimal performance and reduced binary size on Unix-based systems.

## Cross-Platform Example

A complete cross-platform example demonstrating library usage is available in [`example_usage.cpp`](example_usage.cpp). This example shows how to:

- Load the library dynamically on different platforms
- Access mathematical functions through the C API
- Handle platform-specific library loading mechanisms

To build and run the example:

```bash
# Build the library first
meson setup builddir && meson compile -C builddir

# Compile the example
g++ -std=c++17 -o example_usage example_usage.cpp -ldl  # Linux/Unix
# or
cl example_usage.cpp  # Windows with MSVC

# Copy library to current directory and run
cp builddir/libMoo.so ./  # Linux
# or copy builddir\Moo.dll .\  # Windows

./example_usage  # Linux/Unix
# or example_usage.exe  # Windows
```

# DOCS

Documentation is available on the GitHub Wiki: [Moo もう Wiki](https://github.com/DevKiDCosmo/Moo/wiki) or under the `docs` folder.

# Features

- Calculation by GPU and CPU
- NPU compatible
- Multi-threading support


- Complex math calculations
- Millions of different formulas
- Easy to use
- Fast calculations
- Supports large numbers with Kazu 数
- Cross-platform compatibility
- Extensive documentation
- Active community support
- Open-source and free to use
- Regular updates and improvements
- Integration with other libraries
- Customizable for specific needs
- Supports various mathematical operations
- User-friendly interface
- Extensible with plugins
