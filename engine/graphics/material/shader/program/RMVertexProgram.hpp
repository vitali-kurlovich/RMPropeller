//
// Created by Vitali Kurlovich on 4/24/16.
//

#ifndef RMPROPELLER_RMVERTEXPROGRAM_HPP
#define RMPROPELLER_RMVERTEXPROGRAM_HPP


#include "RMProgram.hpp"

#include "../../material_common.hpp"

namespace rmengine {
    namespace graphics {

        class RMVertexProgram : public RMProgram {

        public:
            RMVertexProgram()
                    : RMProgram() {
            }

            RMVertexProgram(const RMVertexProgram &other)
                    : RMProgram(other) {
            }
        };
    }
}

#endif //RMPROPELLER_RMVERTEXPROGRAM_HPP
