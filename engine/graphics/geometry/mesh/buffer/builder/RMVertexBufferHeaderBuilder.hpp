//
// Created by Vitali Kurlovich on 10/29/16.
//

#ifndef RMPROPELLER_RMVERTEXBUFFERHEADERBUILDER_HPP
#define RMPROPELLER_RMVERTEXBUFFERHEADERBUILDER_HPP

#include "graphics/geometry/geometry_common.hpp"
#include <algorithm>

#include "../RMVertexAttribute.hpp"
#include "../RMVertexBufferHeader.hpp"

namespace rmengine {

    namespace graphics {

        class RMVertexBufferHeaderBuilder final {
            std::vector<RMVertexAttributeItem> _attrsBuffer;
            uint16 _format{0};
            uint8 _offset{0};

        public:
            RMVertexBufferHeaderBuilder() {
                _attrsBuffer.reserve(16);
            }

            void clear() {
                _attrsBuffer.clear();
                _format = 0;
                _offset = 0;
            }

            RMVertexBufferHeaderBuilder& append(RMVertexAttribute attr, RMAttributeElementSize size, RMType type) {
#ifndef NDEBUG
                if (!_attrsBuffer.empty()) {
                    assert(_attrsBuffer.back().attribute < attr);
                }
#endif
                assert((_format & attr) == 0);
                _format |= attr;

                _attrsBuffer.push_back(RMVertexAttributeItem(attr, size, type, _offset));
                _offset += sizeOfRMType(type)*size;
                return *this;
            }

            RMVertexBufferHeader build() {
                return RMVertexBufferHeader(_attrsBuffer);
            }
        };

    }
}


#endif //RMPROPELLER_RMVERTEXBUFFERHEADERBUILDER_HPP
