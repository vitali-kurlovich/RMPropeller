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
            RMVertexBufferHeader _header;
            uint32 _count{0};
            RMObjectPtr* _buffer{nullptr};

        public:

            RMVertexBuffer(const RMVertexBufferHeader& header, RMObjectPtr* buffer, uint32 count) noexcept
            : _header(header), _buffer(buffer), _count(count)
            {
                if (_buffer) rmRetain(_buffer);
            }

            virtual ~RMVertexBuffer() {
                if (_buffer) rmRelease(_buffer);
            }

            constexpr
            void* data() const noexcept {
                return _buffer->get();
            }

            constexpr
            size_t size() const noexcept {
                return _header.size()*_count;
            }

            constexpr
            RMVertexAttributeItem attr(size_t index) const noexcept {
                return _header[index];
            }

            constexpr
            RMVertexAttributeItem attr(RMVertexAttribute attr) const noexcept {
                return _header[attr];
            }

            constexpr uint8 attrCount() const noexcept {
                return _header.count();
            }
        };

    }
}

#endif //RMPROPELLER_RMVERTEXBUFFER_HPP
