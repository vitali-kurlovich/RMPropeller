//
// Created by Vitali Kurlovich on 10/31/16.
//

#ifndef RMPROPELLER_RMINDEXBUFFERCONTEXT_HPP
#define RMPROPELLER_RMINDEXBUFFERCONTEXT_HPP

#include "../../geometry_common.hpp"

#include "RMBufferContext.hpp"
#include "../buffer/RMIndexBuffer.hpp"

namespace rmengine {

    namespace graphics {

        class RMIndexBufferContext : public RMBufferContext {
        public:

            const RMIndexBufferHeader header;

            RMIndexBufferContext(const RMIndexBuffer* buffer)
                    : RMBufferContext::RMBufferContext(buffer), header(buffer->header) {
            }

        };
    }
}

#endif //RMPROPELLER_RMINDEXBUFFERCONTEXT_HPP
