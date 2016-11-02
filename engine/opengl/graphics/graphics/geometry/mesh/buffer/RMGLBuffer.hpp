//
// Created by Vitali Kurlovich on 11/1/16.
//

#ifndef RMPROPELLER_RMGLBUFFER_HPP
#define RMPROPELLER_RMGLBUFFER_HPP


#include "../../../../../opengl_common.hpp"
#include "../../../../../../graphics/geometry/mesh/buffer/RMBuffer.hpp"

namespace rmengine {

    namespace graphics {

        GLuint glEnum(RMBuffer::RMUsage usage) {
            switch (usage) {
                case RMBuffer::RMUsageStaticDraw :
                    return GL_STATIC_DRAW;

                case RMBuffer::RMUsageDynamicDraw :
                    return GL_DYNAMIC_DRAW;

                case RMBuffer::RMUsageStreamDraw :
                    return GL_STREAM_DRAW;
            }
            return GL_STATIC_DRAW;
        }
    }
}

#endif //RMPROPELLER_RMGLBUFFER_HPP
