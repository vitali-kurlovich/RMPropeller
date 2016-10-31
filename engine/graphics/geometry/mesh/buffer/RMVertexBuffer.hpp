//
// Created by Vitali Kurlovich on 9/12/16.
//

#ifndef RMPROPELLER_RMVERTEXBUFFER_HPP
#define RMPROPELLER_RMVERTEXBUFFER_HPP


#include "../../geometry_common.hpp"

#include "RMVertexBufferHeader.hpp"

namespace rmengine {

    namespace graphics {

        class RMVertexBuffer : public RMObject {
        protected:
            RMObjectPtr* _buffer{nullptr};

        public:
            const RMVertexBufferHeader header;
            const uint32 count{0};

            RMVertexBuffer(const RMVertexBufferHeader& header, RMObjectPtr* buffer, uint32 count) noexcept
            :  _buffer(buffer), header(header), count(count)
            {
                if (_buffer) rmRetain(_buffer);
            }

            virtual ~RMVertexBuffer() {
                if (_buffer) rmRelease(_buffer);
            }

            constexpr
            void* data() const noexcept {
                return  _buffer ? _buffer->get() : nullptr;
            }

            constexpr
            size_t size() const noexcept {
                return header.size()*count;
            }
        };

    }
}

#endif //RMPROPELLER_RMVERTEXBUFFER_HPP
