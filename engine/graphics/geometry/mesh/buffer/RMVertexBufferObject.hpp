//
// Created by Vitali Kurlovich on 9/13/16.
//

#ifndef RMPROPELLER_RMVERTEXBUFFEROBJECT_HPP
#define RMPROPELLER_RMVERTEXBUFFEROBJECT_HPP


#include "../../geometry_common.hpp"

#include "RMVertexBuffer.hpp"
#include "RMSubIndexBuffer.hpp"


namespace rmengine {

    namespace graphics {

        class RMVertexBufferObject : public RMObject {

            RMVertexBuffer* _vertexBuffer{nullptr};
            RMSubIndexBuffer* _indexBuffer{nullptr};

        public:
            virtual ~RMVertexBufferObject() {
                if (_vertexBuffer) {
                    rmRelease(_vertexBuffer);
                }
                if (_indexBuffer) {
                    rmRelease(_indexBuffer);
                }
            }

        };
    }
}
#endif //RMPROPELLER_RMVERTEXBUFFEROBJECT_HPP
