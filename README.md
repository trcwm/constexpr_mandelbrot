# constexpr_mandelbrot

Rendering the Mandelbrot set at compile time, a.k.a. compiler abuse.
Tested using GCC 9.3.0 on a Ryzen5 3600 with 16GB RAM.

# Building
Run bootstrap.sh at top level.
Execute Ninja -j1 in the build directory.
Note: compiling takes a while and probably requires a minimum of 16GB of RAM.

# Running
* Run 'constexpr_mandelbrot'
* It should produce a mandelbrot.pgm file
* Open the .pgm file using Gimp or eog or convert using Imagemagick to png.

# Dependencies
* GCC
* CMake
* Ninja build
