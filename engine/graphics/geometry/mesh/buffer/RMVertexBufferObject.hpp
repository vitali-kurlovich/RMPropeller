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

        public:
            typedef enum : uint8 {
                RMDrawPrimitivePoints = 0,
                RMDrawPrimitiveLines,
                RMDrawPrimitiveLineStrip,
                RMDrawPrimitiveLineLoop,
                RMDrawPrimitiveTriangles,
                RMDrawPrimitiveTriangleStrip,
                RMDrawPrimitiveTriangleFan
            } RMDrawPrimitive;

        protected:
            RMVertexBuffer* _vertexBuffer{nullptr};
            RMIndexBuffer* _indexBuffer{nullptr};

        public:

            const RMDrawPrimitive primitive{RMDrawPrimitiveTriangles};

            RMVertexBufferObject(RMVertexBuffer* vertexBuffer, RMIndexBuffer* indexBuffer, RMDrawPrimitive primitive = RMDrawPrimitiveTriangles) noexcept
            : _vertexBuffer(vertexBuffer), _indexBuffer(indexBuffer), primitive(primitive)
            {
                if (_vertexBuffer) {
                    rmRetain(_vertexBuffer);
                }
                if (_indexBuffer) {
                    rmRetain(_indexBuffer);
                }
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
