//
// Created by Vitali Kurlovich on 4/24/16.
//

#ifndef RMPROPELLER_RMGLPIXELPROGRAM_HPP
#define RMPROPELLER_RMGLPIXELPROGRAM_HPP

#include "../../../material/shader/program/RMPixelProgram.hpp"

namespace rmengine {
    namespace graphics {

        class RMGLPixelProgram : public RMPixelProgram {

        public:
            RMGLPixelProgram()
                    : RMPixelProgram() {
            }

            RMGLPixelProgram(const RMGLPixelProgram &other)
                    : RMPixelProgram(other) {
            }

        protected:
            virtual bool compileProgram() override {
                return true;
            }

        public:
            virtual bool useProgram() override {
                return true;
            }

        };
    }
}

#endif //RMPROPELLER_RMGLPIXELPROGRAM_HPP
