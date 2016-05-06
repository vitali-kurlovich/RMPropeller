//
// Created by Vitali Kurlovich on 5/2/16.
//

#ifndef RMPROPELLER_RMVERTEXBUFFER2D_HPP
#define RMPROPELLER_RMVERTEXBUFFER2D_HPP


#include "common/common.hpp"

#include "graphics/geometry/VBO/buffer/RMVertexBuffer.hpp"


namespace rmengine {

    namespace graphics {

        typedef struct  {
            pos2 pos;
            vec4 color;
            vec2 uv0;
            vec2 uv1;
        } RMVertex_Pf2_Cf4_U0f2_U1f2;

        typedef struct  {
            pos2 pos;
            vec3 color;
            vec2 uv0;
            vec2 uv1;
        } RMVertex_Pf2_Cf3_U0f2_U1f2;

        typedef struct  {
            pos2 pos;
            vec2 uv0;
            vec2 uv1;
        } RMVertex_Pf2_U0f2_U1f2;

        typedef struct  {
            pos2 pos;
            vec2 uv0;
        } RMVertex_Pf2_U0f2;

    }
}


#endif //RMPROPELLER_RMVERTEXBUFFER2D_HPP
