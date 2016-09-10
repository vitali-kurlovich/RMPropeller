//
// Created by Vitali Kurlovich on 8/26/16.
//

#ifndef RMPROPELLER_RMCAMERA3DUTILS_HPP
#define RMPROPELLER_RMCAMERA3DUTILS_HPP


#include "common/common.hpp"
#include <cmath>

namespace rmengine {

    namespace graphics {

        using namespace rmmath::vector;


        amat4x4 cameraOrthoProjectionRH(float left, float right, float bottom, float top, float zNear, float zFar ) {

            return amat4x4(
                    2.f / (right - left), 0, 0,
                    0, 2.f / (top - bottom), 0,
                    0, 0, -2.f / (zFar - zNear),

                    - (right + left) / (right - left),
                    - (top + bottom) / (top - bottom),
                    - (zFar + zNear) / (zFar - zNear)
            );
        }


        mat4x4 cameraPerspectiveProjection(float fovx, float fovy, float near, float far) {

            return mat4x4(
                    1.f/std::tan(fovx/2.f), 0, 0, 0,
                    0, 1.f/std::tan(fovy/2.f), 0, 0,
                    0, 0, -(far + near)/(far - near), -1,
                    0, 0, -2.f*(far*near)/(far - near), 0

            );
        }

        amat4x4 cameraOrthoProjection(const vec2 &viewsize, float near, float far) {

            return amat4x4(
                    1.f/viewsize.x, 0, 0,
                    0, 1.f/viewsize.y, 0,
                    0, 0, -2.f/(far-near),
                    0, 0, -(far+near)/(far-near)
            );

            return cameraOrthoProjectionRH(-viewsize.x/2, viewsize.x/2, -viewsize.y/2, viewsize.y/2, near, far);
        }


        amat4x4 cameraOrthoProjection(float left, float right, float bottom, float top, float zNear, float zFar ) {
            return cameraOrthoProjection(left, right, bottom, top, zNear, zFar);
        }


        amat4x4 cameraLookAtRH(const vec3 &eye, const vec3 &center, const vec3 &up ) {

            const auto f(normalize(eye - center));
            const auto s(normalize(cross(up, f)));
            const auto u(cross(f, s));

            return amat4x4
                    (
                            s.x, s.y, s.z,
                            u.x, u.y, u.z,
                            -f.x, -f.y, -f.z,
                            -dot(s, eye), -dot(u, eye), -dot(f, eye)
                    );
        }


        amat4x4 cameraLookAt(const vec3 &eye, const vec3 &center, const vec3 &up ) {
            return cameraLookAtRH(eye, center, up);
        }

        mat4x4 cameraPerspectiveProjectionRH() {
            return mat4x4::identity();
        }





    }
}

#endif //RMPROPELLER_RMCAMERA3DUTILS_HPP
