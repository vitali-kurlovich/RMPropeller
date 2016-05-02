//
// Created by Vitali Kurlovich on 5/1/16.
//

#ifndef RMPROPELLER_RMVERTEXATTRIBUTE_HPP
#define RMPROPELLER_RMVERTEXATTRIBUTE_HPP


#include "../../geometry_common.hpp"

namespace rmengine {
    namespace graphics {


        typedef enum : uint16 {

            RMVertexAttributeType_Position   = 1 << 0,
            RMVertexAttributeType_Normal     = 1 << 1,
            RMVertexAttributeType_Color      = 1 << 2,

            RMVertexAttributeType_UV0        = 1 << 3,
            RMVertexAttributeType_UV1        = 1 << 4,
            RMVertexAttributeType_UV2        = 1 << 5,
            RMVertexAttributeType_UV3        = 1 << 6,
            RMVertexAttributeType_UV4        = 1 << 7,
            RMVertexAttributeType_UV5        = 1 << 8,
            RMVertexAttributeType_UV6        = 1 << 9,
            RMVertexAttributeType_UV7        = 1 << 10,

        } RMVertexAttributeType;

        typedef enum : uint8 {
            RMAttributeElementSize_1 = 1,
            RMAttributeElementSize_2 = 2,
            RMAttributeElementSize_3 = 3,
            RMAttributeElementSize_4 = 4,

        } RMAttributeElementSize;

        struct RMVertexAttribute final {
            union {
                struct {
                    RMVertexAttributeType type:13;
                    RMAttributeElementSize size:3;
                    RMType elementType;
                    uint8 offset;
                };
                uint32 _attr;
            };

        public:

            RMVertexAttribute(const RMVertexAttributeType type,
                              const RMAttributeElementSize size,
                              const RMType elementType = RMType_Float,
                              const uint8 offset = 0)
            : type(type), size(size), elementType(elementType), offset(offset) {

            }

            RMVertexAttribute(const RMVertexAttribute& other)
                    : _attr(other._attr)
                    {
            }

        };

        inline bool operator == (const RMVertexAttribute &a, const RMVertexAttribute &b) {
            return a._attr == b._attr ;
        }

        inline bool operator != (const RMVertexAttribute &a, const RMVertexAttribute &b) {
            return !(a == b);
        }

    }
}



#endif //RMPROPELLER_RMVERTEXATTRIBUTE_HPP
