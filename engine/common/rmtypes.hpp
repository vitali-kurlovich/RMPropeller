//
// Created by Vitali Kurlovich on 4/23/16.
//

#ifndef RMPROPELLER_RMTYPES_HPP
#define RMPROPELLER_RMTYPES_HPP

#include <cstdint>
#include <string>
#include <limits>
#include <libs/glm/glm/vec2.hpp>
#include <libs/glm/glm/vec3.hpp>
#include <libs/glm/glm/vec4.hpp>

#include "../../libs/math/rmvmath/types/float.h"



namespace rmengine {

    typedef std::uint8_t uint8;
    typedef std::int8_t int8;

    typedef std::uint16_t uint16;
    typedef std::int16_t int16;

    typedef std::uint32_t uint32;
    typedef std::int32_t int32;

    typedef std::uint64_t uint64;
    typedef std::int64_t int64;

    typedef std::string string;

    typedef glm::mediump_vec2 vec2;
    typedef glm::mediump_vec3 vec3;
    typedef glm::mediump_vec4 vec4;

    typedef rmmath::favec3 pos2;
    typedef rmmath::favec4 pos3;

    typedef rmmath::fquat quat;

    typedef rmmath::famt4x4 amat4x4;
    typedef rmmath::famt3x3 amat3x3;

    typedef rmmath::fmt4x4 mat4x4;
    typedef rmmath::fmt3x3 mat3x3;
    typedef rmmath::fmt2x2 mat2x2;

    constexpr int8 int8_min = -128;
    constexpr int8 int8_max = 127;

    constexpr uint8 uint8_min = 0;
    constexpr uint8 uint8_max = 255U;

    constexpr int16 int16_min = -32768;
    constexpr int16 int16_max = 32767;

    constexpr uint16 uint16_max = 65535U;
    constexpr uint16 uint16_min = 0;

    constexpr int32 int32_min = -2147483647;
    constexpr int32 int32_max = 2147483647;

    constexpr uint32 uint32_min = 0;
    constexpr uint32 uint32_max = 4294967295U;

    constexpr uint64 uint64_min = 0;
    constexpr uint64 uint64_max = 18446744073709551615U;

    constexpr int64 int64_min = -9223372036854775807;
    constexpr int64 int64_max = 9223372036854775807;
}



#endif //RMPROPELLER_RMTYPES_HPP
