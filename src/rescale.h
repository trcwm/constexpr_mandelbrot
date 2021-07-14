#pragma once
#include <array>

static constexpr float absolute(float v)
{
    if (v < 0)
        return -v;

    return v;
}

// rescale by taking the square root
// premultiply by 256 so the output range
// will be 0 .. 255
static constexpr float mysqrt(float x)
{
    int maxiter = 20;
    float guess = x;

    float eps = absolute(guess*guess - x);
    while(eps > 1e-10f)
    {
        guess = (guess + x/guess)/2.0f;
        maxiter--;
        
        if (maxiter == 0)
            return guess;

        eps = absolute(guess*guess - x);
    }
    
    return guess;
}

static constexpr std::array<uint8_t, 256> mktable()
{
    std::array<uint8_t, 256> tbl{};

    for(int i=0; i<tbl.size(); i++)
    {
        tbl.at(i) = static_cast<uint8_t>(mysqrt(i*255));
    }

    return tbl;
}

static constexpr uint8_t rescale(const uint8_t v)
{
    const constexpr auto rescale_tbl = mktable();
    return rescale_tbl[v];
}
