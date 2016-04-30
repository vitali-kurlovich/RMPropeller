//
// Created by Vitali Kurlovich on 4/23/16.
//

#ifndef RMPROPELLER_RMPASS_HPP
#define RMPROPELLER_RMPASS_HPP

#include "RMBlend.hpp"
#include "RMDepth.hpp"

#include "../shader/RMShader.hpp"
#include "../material_common.hpp"

namespace rmengine {
    namespace graphics {

        class RMPass {
        protected:
            RMDepth _depth;
            RMBlend _blend;

            RMShader *_shader;
        public:




        };
    }
}


#endif //RMPROPELLER_RMPASS_HPP
