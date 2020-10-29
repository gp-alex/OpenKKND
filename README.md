# OpenKKND
KKND eXtreme remake based on original exe decompilation.
Code refactoring is underway.

# Build
1. Install & configure vcpkg (https://github.com/Microsoft/vcpkg)
2. Make sure VCPKG_ROOT env variable is set to vcpkg folder
3. Make sure dumpbin.exe (part of the Visual Studio installation) is on the PATH (windows-only) to copy dependant libraries dlls via applocal.ps1
4. Install sdl2 with vcpkg (vcpkg install sdl2:x86-windows, sdl2:x64-linux etc)
5. Set poject output to your KKnD installation folder
6. Build using any CMake-compatible IDE or command line (Visual Studio will do)
7. Run

# Status badges
[![Coverity Status](https://scan.coverity.com/projects/16433/badge.svg)](https://scan.coverity.com/projects/openkknd)
