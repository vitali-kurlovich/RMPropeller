//
// Created by Vitali Kurlovich on 10/31/16.
//

#ifndef RMPROPELLER_RMGLINDEXBUFFERCONTEXT_HPP
#define RMPROPELLER_RMGLINDEXBUFFERCONTEXT_HPP

#include "../../../../../opengl_common.hpp"

#include "../../../../../../graphics/geometry/mesh/context/RMIndexBufferContext.hpp"
//#include "../../../../../../graphics/geometry/mesh/context/RMVertexBufferContext.hpp"


namespace rmengine {

    namespace graphics {

        class RMGLIndexBufferContext : public RMIndexBufferContext {

        protected:
            GLuint bufferId{0};
        public:

            RMGLIndexBufferContext(RMIndexBuffer* buffer)
                    : RMIndexBufferContext::RMIndexBufferContext(buffer) {
            }


        };
    }
}


#endif //RMPROPELLER_RMGLINDEXBUFFERCONTEXT_HPP
