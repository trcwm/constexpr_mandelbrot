#include <cstdlib>
#include <array>
#include <iostream>
#include <fstream>
#include <array>

#include "mandel.h"

int main(int argc, char *argv[])
{
    // write bitmap to file
    // see: http://paulbourke.net/dataformats/ppm/

    const char *filename = "mandelbrot.pgm";
    std::ofstream ofile(filename, std::ios::binary);
    if (!ofile.good())
    {
        std::cerr << "Cannot open " << filename << " for writing\n";
        return EXIT_FAILURE;
    }

    ofile << "P5 " << width << " " << height << " 255\n";
    ofile.write((const char*)&bitmap1[0], bitmap1.size());
    ofile.write((const char*)&bitmap2[0], bitmap2.size());
    ofile.write((const char*)&bitmap3[0], bitmap3.size());
    ofile.write((const char*)&bitmap4[0], bitmap4.size());

    return EXIT_SUCCESS;
}
