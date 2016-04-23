//
// Created by Vitali Kurlovich on 4/21/16.
//

#include "engine/graphics/pass/RMBlend.hpp"

#include <iostream>

int main(int argc, char **argv) {

    RMBlend blend;
    RMBlend blendA(RMBlendFunc_SrcColor);

    RMBlend blendC;
    blendC = blendA;

    std::cout << static_cast<rm_uint32>(blend.blendFunc);

    return 0;
}