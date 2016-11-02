//
// Created by Vitali Kurlovich on 10/31/16.
//

#ifndef RMPROPELLER_RMGLINDEXBUFFERCONTEXT_HPP
#define RMPROPELLER_RMGLINDEXBUFFERCONTEXT_HPP

#include "../../../../../opengl_common.hpp"

#include "../../../../../../graphics/geometry/mesh/context/RMIndexBufferContext.hpp"
//#include "../../../../../../graphics/geometry/mesh/context/RMVertexBufferContext.hpp"
#include "../buffer/RMGLBuffer.hpp"
#include "../buffer/RMGLBufferContext.hpp"

namespace rmengine {

    namespace graphics {

        class RMGLIndexBufferContext : public RMIndexBufferContext {

        protected:
            RMGLBufferContext _glBufferContext;

        public:

            RMGLIndexBufferContext(const RMIndexBuffer* buffer)
                    : RMIndexBufferContext::RMIndexBufferContext(buffer),
                      _glBufferContext(buffer, GL_ELEMENT_ARRAY_BUFFER) {
                genBuffer();
                bindBuffer();
                bufferData(buffer);
            }

            virtual void genBuffer() override {
                _glBufferContext.genBuffer();
            }

            virtual void bindBuffer() override {
                _glBufferContext.bindBuffer();
            }

            virtual void bufferData(const RMBuffer* buffer) override {
                _glBufferContext.bufferData(buffer);
            }

            virtual void deleteBuffer() override {
                _glBufferContext.deleteBuffer();
            }
        };
    }
}


#endif //RMPROPELLER_RMGLINDEXBUFFERCONTEXT_HPP
