#include <stdint.h>
#include <array>
#include "mandel.h"

const std::array<uint8_t, width*deltah> bitmap2 = mandelbrot( deltah, 2*deltah);
