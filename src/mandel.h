#pragma once

#include "rescale.h"

static constexpr int width  = 400;
static constexpr int height = 300;
static constexpr int deltah = height/4;

struct MyComplex
{
    constexpr MyComplex operator+(const MyComplex &other) const noexcept
    {
        return MyComplex{m_x + other.m_x, m_y + other.m_y};
    }

    constexpr MyComplex operator-(const MyComplex &other) const noexcept
    {
        return MyComplex{m_x - other.m_x, m_y - other.m_y};
    }

    constexpr MyComplex operator*(const MyComplex &other) const noexcept
    {
        return MyComplex{
            m_x*other.m_x - m_y*other.m_y, 
            m_x*other.m_y + m_y*other.m_x};
    }

    constexpr float mag2() const noexcept
    {
        return m_x*m_x + m_y*m_y;
    }

    float m_x, m_y;
};

static constexpr auto mandelbrot(const int ystart, const int yend)
{
    constexpr int maxiter = 255;
    std::array<uint8_t, width*deltah> bitmap{};

    for(int y=ystart; y<yend; y++)
    {
        for(int x=0; x<width; x++)
        {
            MyComplex c = {
                -1.5f + 2.0f*x / static_cast<float>(width), 
                -1.0f + 2.0f*y / static_cast<float>(height)};

            int iteration = 0;
            MyComplex z = {0.0f,0.0f};
            while(iteration < maxiter)
            {
                z = z*z + c;
                if (z.mag2() >= 4.0f)
                {
                    break;  // exit the loop
                }
                iteration++;
            }
            bitmap[x+width*(y-ystart)] = rescale(iteration);
            //bitmap.at(x+width*(y-ystart)) = iteration;
        }
    }

    return bitmap;
}

extern const std::array<uint8_t, width*deltah> bitmap1;
extern const std::array<uint8_t, width*deltah> bitmap2;
extern const std::array<uint8_t, width*deltah> bitmap3;
extern const std::array<uint8_t, width*deltah> bitmap4;
