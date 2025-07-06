# Moo もう

A versatile, cross-platform math framework A high-performance mathematical library designed for seamless integration with nearly every programming language I enjoy, optimized for compatibility across all major operating systems. Whether you’re crunching numbers, modeling equations, or building something groundbreaking, this framework delivers the tools you need—fast, reliable, and everywhere.

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



# Reading a Shared Library
- Windows: `dumpbin /exports moo.dll > exports.txt` 
- Linux: `nm -D moo.so > exports.txt` or `readelf -s moo.so > exports.txt`
- macOS: `nm -gU moo.dylib > exports.txt`