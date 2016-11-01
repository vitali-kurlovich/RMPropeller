//
// Created by Vitali Kurlovich on 10/31/16.
//

#ifndef RMPROPELLER_RMVERTEXBUFFEROBJECTCONTEXT_HPP
#define RMPROPELLER_RMVERTEXBUFFEROBJECTCONTEXT_HPP

#include "../../geometry_common.hpp"

#include "RMVertexBufferContext.hpp"
#include "RMIndexBufferContext.hpp"

#include "../../../render/RMRenderable.hpp"


namespace rmengine {

    namespace graphics {

        class RMVertexBufferObjectContext : public RMObject, RMRenderable {
        protected:
            RMVertexBufferContext* _vertexBufferContext{nullptr};
            RMIndexBufferContext* _indexBufferContext{nullptr};

        public:

            const RMVertexBufferObject::RMDrawPrimitive primitive{RMDrawPrimitiveTriangles};

            RMVertexBufferObjectContext(RMVertexBufferContext* vertexBufferContext, RMIndexBufferContext* indexBufferContext, RMVertexBufferObject::RMDrawPrimitive primitive = RMDrawPrimitiveTriangles) noexcept
            : _vertexBufferContext(vertexBufferContext), _indexBufferContext(indexBufferContext), primitive(primitive)
            {
                if (_vertexBufferContext) {
                    rmRetain(_vertexBufferContext);
                }
                if (_indexBufferContext) {
                    rmRetain(_indexBufferContext);
                }
            }

            virtual ~RMVertexBufferObjectContext() {
                if (_vertexBufferContext) {
                    rmRelease(_vertexBufferContext);
                }
                if (_indexBufferContext) {
                    rmRelease(_indexBufferContext);
                }
            }

        };
    }
}

#endif //RMPROPELLER_RMVERTEXBUFFEROBJECTCONTEXT_HPP
