//
// Created by Vitali Kurlovich on 5/1/16.
//

#ifndef RMPROPELLER_RMMESH_HPP
#define RMPROPELLER_RMMESH_HPP


#include "../geometry_common.hpp"

#include "buffer/RMVertexBufferObject.hpp"
#include "../../render/RMRenderable.hpp"

namespace rmengine {

    namespace graphics {

        typedef enum : uint8 {
            RMMeshType_Static = 0,
            RMMeshType_Dynamic = 1
        } RMMeshType;

        class RMMesh : public RMObject {
            RMVertexBufferObject* _vbo;
            RMMeshType _type{RMMeshType_Static};
        public:

            virtual const RMVertexBufferObject* vbo() noexcept const {
                return _vbo;
            }


        };
    }
}

#endif //RMPROPELLER_RMMESH_HPP
