//
// Created by Vitali Kurlovich on 11/1/16.
//

#ifndef RMPROPELLER_RMGLVERTEXBUFFERCONTEXT_HPP
#define RMPROPELLER_RMGLVERTEXBUFFERCONTEXT_HPP

#include "../../../../../opengl_common.hpp"
#include "../../../../../../graphics/geometry/mesh/context/RMVertexBufferContext.hpp"

#include "../buffer/RMGLBuffer.hpp"
#include "../buffer/RMGLBufferContext.hpp"

#include "../buffer/RMGLVertexAttribute.hpp"

namespace rmengine {

    namespace graphics {

        class RMGLVertexBufferContext : public RMVertexBufferContext {
        protected:
            RMGLBufferContext _glBufferContext;
        public:
            RMGLVertexBufferContext(const RMVertexBuffer* buffer)
                    : RMVertexBufferContext::RMVertexBufferContext(buffer),
                      _glBufferContext(buffer, GL_ARRAY_BUFFER)
            {
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

            void enableAttributes() {
                const GLuint count = header.count();
                for (GLuint index = 0; index < count; ++index) {
                    glEnableVertexAttribArray(index);
                }
            }

            void disableAttributes() {
                const GLuint count = header.count();
                for (GLuint index = 0; index < count; ++index) {
                    glDisableVertexAttribArray(index);
                }
            }

            void vertexAttribPointer() {
                const GLuint count = header.count();

                for (GLuint index = 0; index < count; ++index) {
                    auto attr = header[index];
                    if (isIntegerType(attr.type)) {
                        glVertexAttribPointer(index, glEnum(attr.size), glEnum(attr.type), GL_FALSE, 0, (GLubyte *)NULL + (attr.offset));
                    } else {
                        glVertexAttribIPointer(index, glEnum(attr.size), glEnum(attr.type), 0, (GLubyte *)NULL + (attr.offset));
                    }
                }

            }
        };
    }
}





#endif //RMPROPELLER_RMGLVERTEXBUFFERCONTEXT_HPP
