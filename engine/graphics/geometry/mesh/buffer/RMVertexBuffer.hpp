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
            void* _vertexData{nullptr};

        public:
            constexpr
            void* data() const noexcept {
                return _vertexData;
            }
        };

    }
}

#endif //RMPROPELLER_RMVERTEXBUFFER_HPP
