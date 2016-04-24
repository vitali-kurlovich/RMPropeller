//
// Created by Vitali Kurlovich on 4/24/16.
//

#ifndef RMPROPELLER_RMPIXELPROGRAM_HPP
#define RMPROPELLER_RMPIXELPROGRAM_HPP


#include "RMProgram.hpp"

#include "../material_common.hpp"

namespace rmengine {
    namespace graphics {

        class RMPixelProgram : public RMProgram {

        public:
            RMPixelProgram()
                    : RMProgram() {
            }

            RMPixelProgram(const RMPixelProgram &other)
                    : RMProgram(other) {
            }
        };
    }
}

#endif //RMPROPELLER_RMPIXELPROGRAM_HPP
