//
// Created by Vitali Kurlovich on 5/1/16.
//

#ifndef RMPROPELLER_RMMESH_HPP
#define RMPROPELLER_RMMESH_HPP


#include "../geometry_common.hpp"
#include "RMVertexAttribute.hpp"
#include "graphics/geometry/mesh/buffer/RMVertexBufferHeader.hpp"

namespace rmengine {

    namespace graphics {

        typedef enum : uint8 {
            RMMeshType_Static = 0,
            RMMeshType_Dynamic = 1
        } RMMeshType;

        class RMMesh {
            RMMeshHeader _header{};
            void* _meshData{nullptr};
            RMMeshType _type{RMMeshType_Static};

        };
    }
}

#endif //RMPROPELLER_RMMESH_HPP
