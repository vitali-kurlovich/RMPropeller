//
// Created by Vitali Kurlovich on 9/12/16.
//

#ifndef RMPROPELLER_RMINDEXBUFFER_HPP
#define RMPROPELLER_RMINDEXBUFFER_HPP


#include "../../geometry_common.hpp"
#include "RMBuffer.hpp"
#include "RMIndexBufferHeader.hpp"

namespace rmengine {

    namespace graphics {

        class RMIndexBuffer : public RMBuffer {
        public:

            const RMIndexBufferHeader header;

            RMIndexBuffer(RMObjectPtr *buffer, uint32 count, const RMIndexBufferHeader& header, RMUsage usage = RMUsageStaticDraw) noexcept
                    :  RMBuffer::RMBuffer( buffer, count, usage), header(header) {
            }

            constexpr
            size_t size() const noexcept {
                return count * sizeOfRMType(header.type);
            }

        };

    }
}


#endif //RMPROPELLER_RMINDEXBUFFER_HPP
