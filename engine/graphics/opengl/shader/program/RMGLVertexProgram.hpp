//
// Created by Vitali Kurlovich on 4/24/16.
//

#ifndef RMPROPELLER_RMGLVERTEXPROGRAM_HPP
#define RMPROPELLER_RMGLVERTEXPROGRAM_HPP


#include "../../../material/shader/program/RMVertexProgram.hpp"

namespace rmengine {
    namespace graphics {

        class RMGLVertexProgram : public RMVertexProgram {

        public:
            RMGLVertexProgram()
                    : RMVertexProgram() {
            }

            RMGLVertexProgram(const RMGLVertexProgram &other)
                    : RMVertexProgram(other) {
            }

        protected:
            virtual bool compileProgram() override {
                return false;
            }

        public:
            virtual bool useProgram() override {
                return true;
            }
        };
    }
}



#endif //RMPROPELLER_RMGLVERTEXPROGRAM_HPP
