//
// Created by Vitali Kurlovich on 5/1/16.
//

#ifndef RMPROPELLER_RMVERTEXATTRIBUTE_HPP
#define RMPROPELLER_RMVERTEXATTRIBUTE_HPP


#include "common/common.hpp"

namespace rmengine {
    namespace graphics {

        typedef enum : uint16 {

            RMVertexAttribute_None = 0,
            RMVertexAttribute_Position = 1 << 0,

            RMVertexAttribute_Normal = 1 << 1,
            RMVertexAttribute_Tangent = 1 << 2,

            RMVertexAttribute_Color = 1 << 3,

            RMVertexAttribute_UV0 = 1 << 4,
            RMVertexAttribute_UV1 = 1 << 5,
            RMVertexAttribute_UV2 = 1 << 6,
            RMVertexAttribute_UV3 = 1 << 7,

            RMVertexAttribute_BoneWeight = 1 << 8,
            RMVertexAttribute_BoneIndex = 1 << 9,

            RMVertexAttribute_EX0 = 1 << 10,
            RMVertexAttribute_EX1 = 1 << 11,
            RMVertexAttribute_EX2 = 1 << 12

        } RMVertexAttribute;

        typedef enum : uint8 {
            RMAttributeElementSize_None = 0,
            RMAttributeElementSize_1 = 1,
            RMAttributeElementSize_2 = 2,
            RMAttributeElementSize_3 = 3,
            RMAttributeElementSize_4 = 4,

        } RMAttributeElementSize;

        struct RMVertexAttributeItem final {
            union {
                struct {
                    RMVertexAttribute attribute:13;
                    RMAttributeElementSize size:3;
                    RMType type;
                    uint8 offset;
                };
                uint32 _attrs;
            };

        public:

            constexpr
            RMVertexAttributeItem(const RMVertexAttribute attribute = RMVertexAttribute_Position,
                                  const RMAttributeElementSize size = RMAttributeElementSize_3,
                                  const RMType type = RMType_Float,
                                  const uint8 offset = 0) noexcept
                    : attribute(attribute), size(size), type(type), offset(offset) {

            }

        };

        constexpr bool operator == (const RMVertexAttributeItem &a, const RMVertexAttributeItem &b) {
            return a._attrs == b._attrs;
        }

        constexpr bool operator!=(const RMVertexAttributeItem &a, const RMVertexAttributeItem &b) {
            return !(a == b);
        }


        constexpr bool operator < (const RMVertexAttributeItem &a, const RMVertexAttributeItem &b) {
            return a._attrs != b._attrs &&
                    (a.attribute == b.attribute ? (a.size == b.size ? (a.offset == b.offset ? (a.type == b.type ? false : a.type < b.type) : a.offset < b.offset) : a.size < b.size) : a.attribute < b.attribute);
        }

        constexpr bool operator > (const RMVertexAttributeItem &a, const RMVertexAttributeItem &b) {
            return a._attrs != b._attrs &&
                   (a.attribute == b.attribute ? (a.size == b.size ? (a.offset == b.offset ? (a.type == b.type ? false : a.type > b.type) : a.offset > b.offset) : a.size > b.size) : a.attribute > b.attribute);
        }
    }
}


#endif //RMPROPELLER_RMVERTEXATTRIBUTE_HPP
