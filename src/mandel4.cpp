#include <stdint.h>
#include <array>
#include "mandel.h"

const std::array<uint8_t, width*deltah> bitmap4 = mandelbrot( 3*deltah, 4*deltah);
