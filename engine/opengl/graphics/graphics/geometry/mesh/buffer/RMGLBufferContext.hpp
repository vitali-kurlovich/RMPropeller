//
// Created by Vitali Kurlovich on 11/1/16.
//

#ifndef RMPROPELLER_RMGLBUFFERCONTEXT_HPP
#define RMPROPELLER_RMGLBUFFERCONTEXT_HPP

#include "../../../../../opengl_common.hpp"

#include "RMGLBuffer.hpp"
#include "../../../../../../graphics/geometry/mesh/context/RMBufferContext.hpp"

namespace rmengine {

    namespace graphics {

        class RMGLBufferContext : public RMBufferContext {
        protected:
            GLuint _bufferId{0};
            const GLenum _target;
        public:

            RMGLBufferContext(const RMBuffer *buffer, GLenum target)
            :  RMBufferContext::RMBufferContext(buffer), _target(target){

            }

            virtual void genBuffer() override {
                deleteBuffer();
                glGenBuffers(1, &_bufferId);
            }

            virtual void bindBuffer() override {
                glBindBuffer(_target, _bufferId);
            }

            virtual void bufferData(const RMBuffer* buffer) override {
                glBufferData(_target, buffer->size(), buffer->data(), glEnum(buffer->usage));
            }

            virtual void deleteBuffer() override {
                if (_bufferId != 0) {
                    glDeleteBuffers(1, &_bufferId);
                    _bufferId = 0;
                }
            }

            constexpr GLuint bufferId() const noexcept {
                return _bufferId;
            }

            constexpr GLenum glTarget() const {
                return _target;
            }
        };

    }
}

#endif //RMPROPELLER_RMGLBUFFERCONTEXT_HPP
