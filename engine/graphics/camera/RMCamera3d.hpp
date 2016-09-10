//
// Created by Vitali Kurlovich on 8/22/16.
//

#ifndef RMPROPELLER_RMCAMERA3D_HPP
#define RMPROPELLER_RMCAMERA3D_HPP

#include "common/common.hpp"

#include "../transform/TTransform3d.hpp"

namespace rmengine {

    using namespace transform;
    namespace graphics {

        class RMCamera3d {

            TTransform3d _transform;
            TTransform3d _aim;
            TTransform3d _up;

            amat4x4 getViewMatrix() {
                return amat4x4::identity();
            }
        };

    }
}

#endif //RMPROPELLER_RMCAMERA3D_HPP
