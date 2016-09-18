//
// Created by Vitali Kurlovich on 9/13/16.
//

#ifndef RMPROPELLER_RMVERTEXBUFFEROBJECT_HPP
#define RMPROPELLER_RMVERTEXBUFFEROBJECT_HPP


#include "../../geometry_common.hpp"

#include "RMVertexBuffer.hpp"
#include "RMIndexBuffer.hpp"


namespace rmengine {

    namespace graphics {

        class RMVertexBufferObject : public RMObject {

            RMVertexBuffer* _vertexBuffer{nullptr};
            RMIndexBuffer* _indexBuffer{nullptr};

        public:
            constexpr
            RMVertexBufferObject(RMVertexBuffer* vertexBuffer, RMIndexBuffer* indexBuffer) noexcept
            : _vertexBuffer(vertexBuffer), _indexBuffer(indexBuffer)
            {
            }

            virtual ~RMVertexBufferObject() {
                if (_vertexBuffer) {
                    rmRelease(_vertexBuffer);
                }
                if (_indexBuffer) {
                    rmRelease(_indexBuffer);
                }
            }

            constexpr
            RMVertexBuffer* vertexBuffer() const noexcept {
                return _vertexBuffer;
            }

            constexpr
            RMIndexBuffer* indexBuffer() const noexcept {
                return _indexBuffer;
            }
        };
    }
}
#endif //RMPROPELLER_RMVERTEXBUFFEROBJECT_HPP
