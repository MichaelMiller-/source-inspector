# source-inspector

[![GCC](https://github.com/MichaelMiller-/source-inspector/actions/workflows/gcc.yml/badge.svg)](https://github.com/MichaelMiller-/source-inspector/actions/workflows/gcc.yml) [![Clang](https://github.com/MichaelMiller-/source-inspector/actions/workflows/clang.yml/badge.svg)](https://github.com/MichaelMiller-/source-inspector/actions/workflows/clang.yml) [![MSVC 2019](https://github.com/MichaelMiller-/source-inspector/actions/workflows/msvc2019.yml/badge.svg)](https://github.com/MichaelMiller-/source-inspector/actions/workflows/msvc2019.yml)

## Build instructions
```bash
git clone https://github.com/MichaelMiller-/source-inspector
cd source-inspector
mkdir _build
cd _build
```
If [vcpkg](https://github.com/microsoft/vcpkg) is used for dependency management you have to tell cmake where to find the libraries.
```bash
cmake .. -DCMAKE_TOOLCHAIN_FILE=PATH_TO_VCPKG/vcpkg/scripts/buildsystems/vcpkg.cmake
```

## Dependencies
- Catch2
- Qt
- Boost
- tinyxml
- sqlite3
- Clang Tooling