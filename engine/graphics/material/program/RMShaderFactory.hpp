//
// Created by Vitali Kurlovich on 11/13/16.
//

#ifndef RMPROPELLER_RMSHADERFACTORY_HPP
#define RMPROPELLER_RMSHADERFACTORY_HPP

#include "RMShader.hpp"
#include "RMShaderProgram.hpp"

#include "core/resorce/RMResource.hpp"

class RMShaderFactory {
    virtual RMShader* shader(RMResource* resource) = 0;
    virtual RMShaderProgram* shaderProgram(RMResource* resource) = 0;
};


#endif //RMPROPELLER_RMSHADERFACTORY_HPP
