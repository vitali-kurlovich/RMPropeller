//
// Created by Vitali Kurlovich on 8/21/16.
//

#ifndef RMPROPELLER_RMGLVIEWPORT_HPP
#define RMPROPELLER_RMGLVIEWPORT_HPP


#include "../../opengl_common.hpp"


namespace rmengine {

    namespace graphics {

        class RMGLViewport : public RMViewport {


        public:
            RMGLViewport() = default;
            RMGLViewport(const RMGLViewport& viewport) = default;


            RMGLViewport(const vec2& size)
                    : RMViewport(size)
            {}

            RMGLViewport(const vec2& size, const vec2& origin)
                    : RMViewport(size, origin)
            {}

            void update() const noexcept override final {
                GLbitfield mask = 0;

                if (isNeedClearColor()) {
                    const rgbaf color(getClearColor());
                    glClearColor(color.r, color.g, color.b, color.a);
                    mask |= GL_COLOR_BUFFER_BIT;
                }

                if (isNeedClearDepth()) {
                    mask |= GL_DEPTH_BUFFER_BIT;
                }

                if (isNeedClearStencil()) {
                    mask |= GL_STENCIL_BUFFER_BIT;
                }

                if (mask != 0) {
                    glClear(mask);
                }
            }

        };
    }
}

#endif //RMPROPELLER_RMGLVIEWPORT_HPP
