# Raytracing in one weekend

Raytracing in one weekend follow along.

[_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html)

## Building

This project uses CMake and builds with any C++17 compiler (Clang, GCC, or
MSVC), so it works the same way on macOS, Linux, and Windows.

### VS Code (recommended, any OS)

1. Install the [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
   and [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
   extensions (VS Code will prompt you to install these via the workspace
   recommendations in `.vscode/extensions.json`).
2. Open this folder in VS Code. CMake Tools will configure the project
   automatically; pick a kit (compiler) if prompted.
3. Build with the status bar "Build" button or `Ctrl+Shift+B` / `Cmd+Shift+B`.
4. Run or debug with the status bar "Run"/"Debug" buttons, or press `F5`.

The program writes the rendered image as PPM to stdout. The "Render to
image.ppm" task (`Terminal > Run Task...`) builds and redirects the output to
`image.ppm` in the project root.

### Command line (macOS/Linux)

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
./build/raytracingweekend > image.ppm
```

### Command line (Windows)

```powershell
cmake -S . -B build
cmake --build build --config Release
.\build\Release\raytracingweekend.exe > image.ppm
```

### Visual Studio

The original `raytracingweekend.sln` / `.vcxproj` files are still included
for anyone who prefers Visual Studio on Windows.
