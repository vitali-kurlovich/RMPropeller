//
// Created by Vitali Kurlovich on 4/24/16.
//

#ifndef RMPROPELLER_RMSHADER_HPP
#define RMPROPELLER_RMSHADER_HPP


#include "program/RMShaderProgram.hpp"

#include "../material_common.hpp"

namespace rmengine {
    namespace graphics {

        class RMShader {
        protected:
            RMShaderProgram *_program;

        public:

            RMShader(const RMShaderProgram* program)
            : _program(program) {
            }

            RMShader(const RMShader& other)
            : _program(other._program) {

            }

            const RMShaderProgram* program() const {
                return _program;
            }

        };
    }
}



#endif //RMPROPELLER_RMSHADER_HPP
