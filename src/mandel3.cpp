#include <stdint.h>
#include <array>
#include "mandel.h"

const std::array<uint8_t, width*deltah> bitmap3 = mandelbrot( 2*deltah, 3*deltah);
