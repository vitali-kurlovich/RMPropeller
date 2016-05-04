//
// Created by Vitali Kurlovich on 5/1/16.
//

#ifndef RMPROPELLER_RMVERTEXATTRIBUTES_HPP
#define RMPROPELLER_RMVERTEXATTRIBUTES_HPP


#include <vector>

#include "common/common.hpp"
#include "RMVertexAttribute.hpp"


namespace rmengine {
    namespace graphics {

        struct RMVertexAttributes final {
            uint16 type;
            std::vector<RMVertexAttribute> attributes;

        public:

            RMVertexAttributes(const RMVertexAttributes& other)
                    : type(other.type),
                      attributes(other.attributes) {
            }

            RMVertexAttributes(const std::vector<RMVertexAttribute> &attrs)

            : attributes(attrs),
              type(0) {
                for (RMVertexAttribute attr : attributes) {
                    type |= attr.type;
                }
            }

            RMVertexAttributes(const std::initializer_list<RMVertexAttribute> &attrs)
                    : attributes(attrs),
                      type(0) {
                for (RMVertexAttribute attr : attributes) {
                    type |= attr.type;
                }
            }

        };


        inline bool operator == (const RMVertexAttributes &a, const RMVertexAttributes &b) {
            return  &a == &b || (a.type == b.type && a.attributes == b.attributes);
        }

        inline bool operator != (const RMVertexAttributes &a, const RMVertexAttributes &b) {
            return !(a == b);
        }

    }
}


#endif //RMPROPELLER_RMVERTEXATTRIBUTES_HPP
