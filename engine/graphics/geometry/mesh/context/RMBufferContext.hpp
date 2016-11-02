//
// Created by Vitali Kurlovich on 10/31/16.
//

#ifndef RMPROPELLER_RMBUFFERCONTEXT_HPP
#define RMPROPELLER_RMBUFFERCONTEXT_HPP


#include "../../geometry_common.hpp"
#include "../buffer/RMBuffer.hpp"

namespace rmengine {

    namespace graphics {

        class RMBufferContext : public RMObject {

        public:
            const uint32 count{0};
            const RMBuffer::RMUsage usage{RMBuffer::RMUsageStaticDraw};

            RMBufferContext(const RMBuffer *buffer)
                    : count(buffer->count), usage(buffer->usage) {

            }

            virtual ~RMGLBufferContext() {
                deleteBuffer();
            }

            virtual void genBuffer() = 0;

            virtual void void deleteBuffer() = 0;

            virtual void void bindBuffer() = 0;

            virtual void bufferData(const RMBuffer *buffer) = 0;
        }
    }
}

#endif //RMPROPELLER_RMBUFFERCONTEXT_HPP
