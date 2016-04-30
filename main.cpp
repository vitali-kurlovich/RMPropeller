//
// Created by Vitali Kurlovich on 4/21/16.
//

#include "engine/graphics/material/pass/RMBlend.hpp"

#include "engine/graphics/opengl/shader/program/RMGLVertexProgram.hpp"

#include <graphics/material/pass/RMPass.hpp>

#include <iostream>

int main(int argc, char **argv) {

    rmengine::graphics::RMBlend blend;
    rmengine::graphics::RMBlend blendA(rmengine::graphics::RMBlendFunc_SrcColor);

    rmengine::graphics::RMBlend blendC;
    blendC = blendA;

    std::cout << "sizeof RMPass: " << sizeof( rmengine::graphics::RMPass) << std::endl;

    std::cout << static_cast<rmengine::uint32>(blend.blendFunc) << std::endl;

    rmengine::graphics::RMGLVertexProgram program;

    std::cout << (program.isCompiled() ? "Compiled yes" : "Compiled no") << std::endl;
    std::cout << (program.hasError() ? "hasError yes" : "hasError no") << std::endl;

    program.compile();


    std::cout << (program.isCompiled() ? "Compiled yes" : "Compiled no") << std::endl;
    std::cout << (program.hasError() ? "hasError yes" : "hasError no") << std::endl;

    return 0;
}