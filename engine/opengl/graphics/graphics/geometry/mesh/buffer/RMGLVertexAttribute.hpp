//
// Created by Vitali Kurlovich on 11/2/16.
//

#ifndef RMPROPELLER_RMGLVERTEXATTRIBUTE_HPP
#define RMPROPELLER_RMGLVERTEXATTRIBUTE_HPP


#include "../../../../../opengl_common.hpp"

#include "../../../../../../graphics/geometry/mesh/buffer/RMVertexAttribute.hpp"

namespace rmengine {

    namespace graphics {
        GLint glEnum(RMAttributeElementSize size) {
            return static_cast<GLint>(size);
        }
    }
}


#endif //RMPROPELLER_RMGLVERTEXATTRIBUTE_HPP
