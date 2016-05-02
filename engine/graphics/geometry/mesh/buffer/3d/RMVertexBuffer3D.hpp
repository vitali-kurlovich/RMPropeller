//
// Created by Vitali Kurlovich on 5/2/16.
//

#ifndef RMPROPELLER_RMVERTEXBUFFER3D_HPP
#define RMPROPELLER_RMVERTEXBUFFER3D_HPP


#include "common/common.hpp"

#include "../RMVertexBuffer.hpp"


namespace rmengine {

    namespace graphics {

        typedef struct  {
            pos3 pos;
            vec3 normal;
            vec4 color;
            vec2 uv0;
            vec2 uv1;
        } RMVertex_Pf3_Nf3_Cf4_U0f2_U1f2;

        typedef struct  {
            pos3 pos;
            vec3 normal;
            vec3 color;
            vec2 uv0;
            vec2 uv1;
        } RMVertex_Pf3_Nf3_Cf3_U0f2_U1f2;

        typedef struct  {
            pos3 pos;
            vec3 normal;
            vec2 uv0;
            vec2 uv1;
        } RMVertex_Pf3_Nf3_U0f2_U1f2;

        typedef struct  {
            pos3 pos;
            vec3 normal;
            vec2 uv0;
        } RMVertex_Pf3_Nf3_U0f2;


    }
}

#endif //RMPROPELLER_RMVERTEXBUFFER3D_HPP
