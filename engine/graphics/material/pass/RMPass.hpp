//
// Created by Vitali Kurlovich on 4/23/16.
//

#ifndef RMPROPELLER_RMPASS_HPP
#define RMPROPELLER_RMPASS_HPP

#include "RMAlpha.hpp"
#include "RMBlend.hpp"
#include "RMDepth.hpp"

#include "../shader/RMShader.hpp"
#include "../material_common.hpp"

namespace rmengine {
    namespace graphics {

        class RMPass {
        protected:
            RMAlpha alpha;
            RMDepth depth;
            RMBlend blend;


            RMShader *shader;
        public:
        };
    }
}


#endif //RMPROPELLER_RMPASS_HPP
