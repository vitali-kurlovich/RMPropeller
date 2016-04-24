//
// Created by Vitali Kurlovich on 4/21/16.
//

#include "engine/graphics/material/pass/RMBlend.hpp"

#include "engine/graphics/opengl/shader/program/RMGLVertexProgram.hpp"

#include <iostream>

int main(int argc, char **argv) {

    rmengine::graphics::RMBlend blend;
    rmengine::graphics::RMBlend blendA(rmengine::graphics::RMBlendFunc_SrcColor);

    rmengine::graphics::RMBlend blendC;
    blendC = blendA;

    std::cout << static_cast<rmengine::rm_uint32>(blend.blendFunc) << std::endl;

    rmengine::graphics::RMGLVertexProgram program;

    std::cout << (program.isCompiled() ? "Compiled yes" : "Compiled no") << std::endl;
    std::cout << (program.hasError() ? "hasError yes" : "hasError no") << std::endl;

    program.compile();


    std::cout << (program.isCompiled() ? "Compiled yes" : "Compiled no") << std::endl;
    std::cout << (program.hasError() ? "hasError yes" : "hasError no") << std::endl;

    return 0;
}