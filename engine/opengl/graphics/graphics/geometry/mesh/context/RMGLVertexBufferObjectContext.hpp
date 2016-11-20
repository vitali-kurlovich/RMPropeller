//
// Created by Vitali Kurlovich on 11/1/16.
//

#ifndef RMPROPELLER_RMGLVERTEXBUFFEROBJECTCONTEXT_HPP
#define RMPROPELLER_RMGLVERTEXBUFFEROBJECTCONTEXT_HPP

#include "../../../../../opengl_common.hpp"

#include "../../../../../../graphics/geometry/mesh/context/RMVertexBufferObjectContext.hpp"
#include "RMGLIndexBufferContext.hpp"
#include "RMGLVertexBufferContext.hpp"

namespace rmengine {

    namespace graphics {

        class RMGLVertexBufferObjectContext : RMVertexBufferObjectContext {

        protected:
            GLuint _vertexArrayId{0};
        public:
            RMGLVertexBufferObjectContext(RMVertexBufferContext *vertexBufferContext,
                                          RMIndexBufferContext *indexBufferContext,
                                          RMVertexBufferObject::RMDrawPrimitive primitive = RMDrawPrimitiveTriangles) noexcept
                    : RMVertexBufferObjectContext::RMVertexBufferObjectContext(vertexBufferContext, indexBufferContext,
                                                                               primitive) {

                genVertexArrays();
                bindVertexArray();

                vertexBufferContext->bindBuffer();
                vertexBufferContext->enableAttributes();
                vertexBufferContext->vertexAttribPointer();

                unbindVertexArray();
            }

            void genVertexArrays() {
                deleteVertexArrays();
                glGenVertexArrays(1, &_vertexArrayId);
            }

            void deleteVertexArrays() {
                if (_vertexArrayId != 0) {
                    glDeleteVertexArrays(1, &_vertexArrayId);
                    _vertexArrayId = 0;
                }
            }

            constexpr GLuint vertexArrayId() const noexcept {
                return _vertexArrayId;
            }

            void bindVertexArray() {
                glBindVertexArray(_vertexArrayId);
            }

            void unbindVertexArray() {
                glBindVertexArray(0);
            }


            virtual void bindVertexBufferObject() noexcept override {
                bindVertexArray();
            }

            constexpr
            RMGLIndexBufferContext *glIndexBufferContext() const {
                return static_cast<RMGLIndexBufferContext *>(indexBufferContext());
            }

            constexpr
            RMGLVertexBufferContext *glVertexBufferContext() const {
                return static_cast<RMGLVertexBufferContext *>(vertexBufferContext());
            }

        };
    }
}
#endif //RMPROPELLER_RMGLVERTEXBUFFEROBJECTCONTEXT_HPP
