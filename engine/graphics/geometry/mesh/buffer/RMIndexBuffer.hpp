//
// Created by Vitali Kurlovich on 9/12/16.
//

#ifndef RMPROPELLER_RMINDEXBUFFER_HPP
#define RMPROPELLER_RMINDEXBUFFER_HPP


#include "../../geometry_common.hpp"


namespace rmengine {

    namespace graphics {

        class RMIndexBuffer : public RMObject {
            RMObjectPtr *_buffer{nullptr};
        public:
            const uint32 count{0};
            const RMIntegerType type{RMIntegerType_U8};

            RMIndexBuffer(RMObjectPtr *buffer, uint32 count, RMIntegerType type) noexcept
                    : _buffer(buffer), count(count), type(type) {
                if (_buffer) rmRetain(_buffer);
            }

            virtual ~RMIndexBuffer() {
                if (_buffer) rmRelease(_buffer);
            }

            constexpr
            void* data() const noexcept {
                return _buffer ? _buffer->get() : nullptr;
            }

            constexpr
            size_t size() const noexcept {
                return count * sizeOfRMType(type);
            }


        };

    }
}


#endif //RMPROPELLER_RMINDEXBUFFER_HPP
