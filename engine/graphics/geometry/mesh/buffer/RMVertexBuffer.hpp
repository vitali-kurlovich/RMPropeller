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
            size_t _size{0};
            RMObjectPtr* _buffer{nullptr};
        public:

            virtual ~RMVertexBuffer() {
                if (_buffer) rmRelease(_buffer);
            }

            constexpr
            void* data() const noexcept {
                return _buffer->get();
            }



        };

    }
}

#endif //RMPROPELLER_RMVERTEXBUFFER_HPP
