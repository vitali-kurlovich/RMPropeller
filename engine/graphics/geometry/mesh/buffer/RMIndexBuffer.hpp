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
            uint32 _count{0};
            RMIntegerType _type{RMIntegerType_U8};
        public:

            RMIndexBuffer(RMObjectPtr *buffer, uint32 count, RMIntegerType type)  noexcept
                    : _buffer(buffer), _count(count), _type(type) {
                if (_buffer) rmRetain(_buffer);
            }

            virtual ~RMIndexBuffer() {
                if (_buffer) rmRelease(_buffer);
            }

            constexpr
            void *data() const noexcept {
                return _buffer->get();
            }

            constexpr
            uint32 count() const noexcept {
                return _count;
            }

            constexpr
            size_t size() const noexcept {
                return _count * sizeOfRMType(_type);
            }

            constexpr
            RMIntegerType type() const noexcept {
                return _type;
            }
        };

    }
}


#endif //RMPROPELLER_RMINDEXBUFFER_HPP
