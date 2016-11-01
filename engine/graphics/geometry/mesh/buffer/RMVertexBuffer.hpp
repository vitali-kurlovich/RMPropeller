//
// Created by Vitali Kurlovich on 9/12/16.
//

#ifndef RMPROPELLER_RMVERTEXBUFFER_HPP
#define RMPROPELLER_RMVERTEXBUFFER_HPP


#include "../../geometry_common.hpp"
#include "RMBuffer.hpp"
#include "RMVertexBufferHeader.hpp"

namespace rmengine {

    namespace graphics {

        class RMVertexBuffer : public RMBuffer {
        public:
            const RMVertexBufferHeader header;
        public:
            RMVertexBuffer(const RMVertexBufferHeader& header, RMObjectPtr* buffer, uint32 count,  RMUsage usage = RMUsageStaticDraw) noexcept
                    : RMBuffer::RMBuffer(buffer, count, usage), header(header) {
            }

            constexpr
            size_t size() const noexcept {
                return header.size()*count;
            }
        };

    }
}

#endif //RMPROPELLER_RMVERTEXBUFFER_HPP
