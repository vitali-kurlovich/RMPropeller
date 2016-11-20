//
// Created by Vitali Kurlovich on 11/2/16.
//

#ifndef RMPROPELLER_RMRENDER_HPP
#define RMPROPELLER_RMRENDER_HPP

#include "../graphics_common.hpp"

#include "RMRenderContext.hpp"
#include "../material/RMMaterial.hpp"

namespace rmengine {

    namespace graphics {

        class RMRender : public RMObject {

            RMMaterial* material;

            virtual void render(const RMRenderContext &context) = 0;

            virtual void preRender(const RMRenderContext &context) {}
            virtual void postRender(const RMRenderContext &context) {}
        };

        class RMRenderFactory {

            virtual const RMRender* vboRender(class RMVertexBufferObjectContext* vboContext) = 0;
        };

    }
}

#endif //RMPROPELLER_RMRENDER_HPP
