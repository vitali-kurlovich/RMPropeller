//
// Created by Vitali Kurlovich on 9/20/16.
//

#ifndef RMPROPELLER_RMRENDERABLEFACTORY_HPP
#define RMPROPELLER_RMRENDERABLEFACTORY_HPP


#include "../graphics_common.hpp"

#include "RMRenderable.hpp"

namespace rmengine {

    namespace graphics {

        class RMRenderableFactory {

        public:
            virtual RMRenderable* renderableVBO(class RMVertexBufferObject* vbo) = 0;

            //virtual void render(RMRenderContext &context) = 0;
        };
    }
}


#endif //RMPROPELLER_RMRENDERABLEFACTORY_HPP
