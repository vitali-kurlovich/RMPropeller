//
// Created by Vitali Kurlovich on 8/20/16.
//

#ifndef RMPROPELLER_RMCOLORTYPE_HPP
#define RMPROPELLER_RMCOLORTYPE_HPP

#include <cmath>

#include "RMType.hpp"

namespace rmengine {

    struct RMColorRGB {
        uint8 r{0};
        uint8 g{0};
        uint8 b{0};

        constexpr RMColorRGB(uint8 red = 0, uint8 green = 0, uint8 blue = 0) noexcept
        : r(red), g(green), b(blue)
        {}

        RMColorRGB(const RMColorRGB &color) = default;

        constexpr RMColorRGB(const struct RMColorRGB_F &color) noexcept;
    };

    struct RMColorRGBA {
        union {
            struct {
                uint8 r;
                uint8 g;
                uint8 b;
                uint8 a;
            };

            RMColorRGB rgb;
            uint32 value{0};
        };

        constexpr RMColorRGBA(uint8 red, uint8 green, uint8 blue, uint8 alpha = 255) noexcept
        : r(red), g(green), b(blue), a(alpha)
        {}

        constexpr RMColorRGBA(const RMColorRGB& color, uint8 alpha = 255) noexcept
        : r(color.r), g(color.g), b(color.b), a(alpha)
        {}

        RMColorRGBA(const RMColorRGBA& color) = default;

        constexpr RMColorRGBA(const struct RMColorRGBA_F &color) noexcept;
    };


    constexpr bool operator == (const RMColorRGBA &a, const RMColorRGBA &b) {
        return a.value == b.value;
    }

    constexpr bool operator == (const RMColorRGB &a, const RMColorRGB &b) {
        return a.r == b.r && a.g == b.g && a.b == b.b;
    }

    constexpr bool operator == (const RMColorRGBA &a, const RMColorRGB &b) {
        return a.a == 255 && a.r == b.r && a.g == b.g && a.b == b.b;
    }

    constexpr bool operator == (const RMColorRGB &a, const RMColorRGBA &b) {
        return b.a == 255 && a.r == b.r && a.g == b.g && a.b == b.b;
    }


    struct RMColorRGB_F {
        float r{0.f};
        float g{0.f};
        float b{0.f};

        constexpr RMColorRGB_F(float red = 0, float green = 0, float blue = 0) noexcept
        : r(red), g(green), b(blue)
        {}

        RMColorRGB_F(const RMColorRGB_F &color) = default;

        constexpr RMColorRGB_F(const RMColorRGB &color) noexcept
        : r(color.r/255.f), g(color.g/255.f), b(color.b/255.f)
        {}
    };


    struct RMColorRGBA_F {
        union {
            struct {
                float r{0.f};
                float g{0.f};
                float b{0.f};
                float a{1.f};
            };

            RMColorRGB_F rgb;
        };

        constexpr RMColorRGBA_F(const float red = 0.f,
                                const float green = 0.f,
                                const float blue = 0.f,
                                const float alpha = 1.f) noexcept
                : r(red), g(green), b(blue), a(alpha)
        {}

        RMColorRGBA_F(const RMColorRGBA_F &color) = default;

        constexpr RMColorRGBA_F(const RMColorRGBA &color) noexcept
                : r(color.r/255.f), g(color.g/255.f), b(color.b/255.f), a(color.a/255.f)
        {}

        constexpr RMColorRGBA_F(const RMColorRGB_F &color, float alpha = 1.f) noexcept
                : r(color.r), g(color.g), b(color.b), a(alpha)
        {}

        constexpr RMColorRGBA_F(const RMColorRGB& color, uint8 alpha = 255) noexcept
                : r(color.r/255.f), g(color.g/255.f), b(color.b/255.f), a(alpha/255.f)
        {}
    };


    constexpr RMColorRGB::RMColorRGB(const struct RMColorRGB_F &color) noexcept
            :r(color.r*255.f),
             g(color.g*255.f),
             b(color.b*255.f)
    {}

    constexpr RMColorRGBA::RMColorRGBA(const struct RMColorRGBA_F &color) noexcept
            :r(color.r*255.f),
             g(color.g*255.f),
             b(color.b*255.f),
             a(color.a*255.f)
    {}

    typedef RMColorRGBA rgba;
    typedef RMColorRGBA rgb;

    typedef RMColorRGBA_F rgbaf;
    typedef RMColorRGBA_F rgbf;

}


#endif //RMPROPELLER_RMCOLORTYPE_HPP
