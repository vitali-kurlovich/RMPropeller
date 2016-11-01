//
// Created by Vitali Kurlovich on 10/31/16.
//

#ifndef RMPROPELLER_RMBUFFER_HPP
#define RMPROPELLER_RMBUFFER_HPP

#include "../../geometry_common.hpp"


namespace rmengine {

    namespace graphics {

        class RMBuffer : public RMObject {

        public:
            typedef enum : uint8 {
                RMUsageStaticDraw = 0,
                RMUsageDynamicDraw,
                RMUsageStreamDraw
            } RMUsage;
        protected:
            RMObjectPtr *_buffer{nullptr};
        public:
            const uint32 count{0};
            const RMUsage usage{RMUsageStaticDraw};

            RMBuffer(RMObjectPtr *buffer, uint32 count, RMUsage usage = RMUsageStaticDraw)
                    : _buffer(buffer), count(count), usage(usage) {
                if (_buffer) rmRetain(_buffer);
            }

            virtual ~RMBuffer() {
                if (_buffer) rmRelease(_buffer);
            }

            constexpr
            void* data() const noexcept {
                return _buffer ? _buffer->get() : nullptr;
            }
        };
    }
}

#endif //RMPROPELLER_RMBUFFER_HPP
