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
            const RMUsage usage{RMUsageStaticDraw};

            RMBufferContext(RMBuffer *buffer)
                    : count(buffer->count), usage(buffer->usage) {

            }
        }
    }
}

#endif //RMPROPELLER_RMBUFFERCONTEXT_HPP
