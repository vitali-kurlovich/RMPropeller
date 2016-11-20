//
// Created by Vitali Kurlovich on 11/7/16.
//

#ifndef RMPROPELLER_RMSHADER_HPP
#define RMPROPELLER_RMSHADER_HPP

#include "graphics/material/material_common.hpp"



namespace rmengine {

    namespace graphics {

        class RMShader : public RMObject {
        public:
            typedef enum : uint8 {
                RMShaderTypeNone = 0,
                RMShaderTypeVertex,
                RMShaderTypeFragment
#ifdef GL_GEOMETRY_SHADER
                ,RMShaderTypeGeometry
#endif
            } RMShaderType;

            const RMShaderType type{RMShaderTypeNone};

            RMShader(RMShaderType type)
                    : type(type)
                    {
            }

            virtual bool compile() noexcept = 0;
        };



    }
}

#endif //RMPROPELLER_RMSHADER_HPP
