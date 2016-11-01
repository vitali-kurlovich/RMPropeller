//
// Created by Vitali Kurlovich on 10/31/16.
//

#ifndef RMPROPELLER_RMVERTEXBUFFERCONTEXT_HPP
#define RMPROPELLER_RMVERTEXBUFFERCONTEXT_HPP

#include "../../geometry_common.hpp"

#include "RMBufferContext.hpp"
#include "../buffer/RMVertexBuffer.hpp"


namespace rmengine {

    namespace graphics {

        class RMVertexBufferContext : public RMBufferContext {
        public:
            const RMVertexBufferHeader header;

            RMVertexBufferContext(RMVertexBuffer *buffer)
                    : RMBufferContext::RMBufferContext(buffer), header(buffer->header) {
            }
        }
    }
}

#endif //RMPROPELLER_RMVERTEXBUFFERCONTEXT_HPP
