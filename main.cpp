//
// Created by Vitali Kurlovich on 4/21/16.
//


#include <graphics/material/technique/RMTechnique.hpp>

#include <graphics/geometry/mesh/attribute/RMVertexAttribute.hpp>
#include <graphics/material/technique/shader/program/RMShaderProgram.hpp>

#include <graphics/texture/RMTexture.hpp>

#include <iostream>

int main(int argc, char **argv) {



    std::cout << "sizeof RMTexture: " << sizeof( rmengine::graphics::RMTexture) << std::endl;

    return 0;
}