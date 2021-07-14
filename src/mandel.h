#pragma once

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

static constexpr int8_t sqrt(const int v)
{
    if (v >= 15*15) return 15;
    if (v >= 14*14) return 14;
    if (v >= 13*13) return 13;
    if (v >= 12*12) return 12;
    if (v >= 11*11) return 11;
    if (v >= 10*10) return 10;
    if (v >= 9*9) return 9;
    if (v >= 8*8) return 8;
    if (v >= 7*7) return 7;
    if (v >= 6*6) return 6;
    if (v >= 5*5) return 5;    
    if (v >= 4*4) return 4;
    if (v >= 3*3) return 3;
    if (v >= 2*2) return 2;
    if (v >= 1) return 1;
    return 0;
}

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
            bitmap.at(x+width*(y-ystart)) = sqrt(iteration)*17;
        }
    }

    return bitmap;
}

extern const std::array<uint8_t, width*deltah> bitmap1;
extern const std::array<uint8_t, width*deltah> bitmap2;
extern const std::array<uint8_t, width*deltah> bitmap3;
extern const std::array<uint8_t, width*deltah> bitmap4;
