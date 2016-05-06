//
// Created by Vitali Kurlovich on 5/2/16.
//

#ifndef RMPROPELLER_RMVERTEXBUFFER3D_HPP
#define RMPROPELLER_RMVERTEXBUFFER3D_HPP


#include "common/common.hpp"

#include "graphics/geometry/VBO/buffer/RMVertexBuffer.hpp"


namespace rmengine {

    namespace graphics {

        typedef struct final {
            pos3 pos;
            vec3 normal;
            vec4 color;
            vec2 uv0;
            vec2 uv1;
        } RMVertex_Pf3_Nf3_Cf4_U0f2_U1f2;

        class RMVertexBuffer_P3_N3_C4_U0_U1 : public RMVertexBuffer<RMVertex_Pf3_Nf3_Cf4_U0f2_U1f2> {

        public:
            RMVertexBuffer_P3_N3_C4_U0_U1(const RMVertexBuffer_P3_N3_C4_U0_U1 &other)
                    : RMVertexBuffer<RMVertex_Pf3_Nf3_Cf4_U0f2_U1f2>(other) {

            }

            RMVertexBuffer_P3_N3_C4_U0_U1(RMVertex_Pf3_Nf3_Cf4_U0f2_U1f2 *buffer, const uint32 bufferSize)
                    : RMVertexBuffer<RMVertex_Pf3_Nf3_Cf4_U0f2_U1f2>
                              (
                                      RMVertexAttributes(
                                              {RMVertexAttribute(RMVertexAttributeType_Position, RMAttributeElementSize_3),
                                               RMVertexAttribute(RMVertexAttributeType_Normal, RMAttributeElementSize_3),
                                               RMVertexAttribute(RMVertexAttributeType_Color, RMAttributeElementSize_4),
                                               RMVertexAttribute(RMVertexAttributeType_UV0, RMAttributeElementSize_2),
                                               RMVertexAttribute(RMVertexAttributeType_UV1, RMAttributeElementSize_2),
                                              }),
                                      buffer, bufferSize) {
            }
        };


        typedef struct {
            pos3 pos;
            vec3 normal;
            vec3 color;
            vec2 uv0;
            vec2 uv1;
        } RMVertex_Pf3_Nf3_Cf3_U0f2_U1f2;

        typedef struct {
            pos3 pos;
            vec3 normal;
            vec2 uv0;
            vec2 uv1;
        } RMVertex_Pf3_Nf3_U0f2_U1f2;

        typedef struct {
            pos3 pos;
            vec3 normal;
            vec2 uv0;
        } RMVertex_Pf3_Nf3_U0f2;


    }
}

#endif //RMPROPELLER_RMVERTEXBUFFER3D_HPP
