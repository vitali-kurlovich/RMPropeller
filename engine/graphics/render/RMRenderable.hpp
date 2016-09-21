//
// Created by Vitali Kurlovich on 9/20/16.
//

#ifndef RMPROPELLER_RMRENDERABLE_HPP
#define RMPROPELLER_RMRENDERABLE_HPP


#include "../graphics_common.hpp"

#include "RMRenderContext.hpp"

namespace rmengine {

    namespace graphics {

        class RMRenderable {

            virtual void render(RMRenderContext &context) = 0;

            virtual void preRender(RMRenderContext &context) {}
            virtual void postRender(RMRenderContext &context) {}
        };
    }
}

#endif //RMPROPELLER_RMRENDERABLE_HPP
