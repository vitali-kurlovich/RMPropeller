//
// Created by Vitali Kurlovich on 5/1/16.
//

#ifndef RMPROPELLER_RMVERTEXBUFFER_HPP
#define RMPROPELLER_RMVERTEXBUFFER_HPP

#include "../geometry_common.hpp"

#include "attribute/RMVertexAttributes.hpp"

namespace rmengine {
    namespace graphics {

        class RMVertexBuffer {
        protected:
            RMVertexAttributes _attributes;
            uint32 _bufferSize;
        };
    }
}


#endif //RMPROPELLER_RMVERTEXBUFFER_HPP
