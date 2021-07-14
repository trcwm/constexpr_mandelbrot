#include <stdint.h>
#include <array>
#include "mandel.h"

const std::array<uint8_t, width*deltah> bitmap1 = mandelbrot(  0, deltah);
