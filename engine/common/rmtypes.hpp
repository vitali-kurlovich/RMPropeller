//
// Created by Vitali Kurlovich on 4/23/16.
//

#ifndef RMPROPELLER_RMTYPES_HPP
#define RMPROPELLER_RMTYPES_HPP

#include <cstdint>
#include <string>

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

    typedef rmmath::fvec2 vec2;
    typedef rmmath::fvec3 vec3;
    typedef rmmath::fvec4 vec4;

    typedef rmmath::favec3 pos2;
    typedef rmmath::favec4 pos3;


    typedef rmmath::fquat quat;

    typedef rmmath::famt4x4 amat4x4;
    typedef rmmath::fmt4x4 mat4x4;

}



#endif //RMPROPELLER_RMTYPES_HPP
