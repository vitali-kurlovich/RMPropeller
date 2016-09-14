//
// Created by Vitali Kurlovich on 9/11/16.
//

#ifndef RMPROPELLER_RMVERTEXBUFFERHEADER_HPP
#define RMPROPELLER_RMVERTEXBUFFERHEADER_HPP


#include "graphics/geometry/geometry_common.hpp"
#include "graphics/geometry/mesh/RMVertexAttribute.hpp"

namespace rmengine {

    namespace graphics {

        class RMVertexBufferHeader final {
        private:
            RMVertexAttributeItem _attrs[13]{
                    RMVertexAttributeItem{},
                    RMVertexAttributeItem{},
                    RMVertexAttributeItem{},
                    RMVertexAttributeItem{},
                    RMVertexAttributeItem{},

                    RMVertexAttributeItem{},
                    RMVertexAttributeItem{},
                    RMVertexAttributeItem{},
                    RMVertexAttributeItem{},
                    RMVertexAttributeItem{},

                    RMVertexAttributeItem{},
                    RMVertexAttributeItem{},
                    RMVertexAttributeItem{}
            };
            uint16 _format{0};
            uint8 _count{0};
            uint8 _size{0};

        public:

            constexpr
            RMVertexBufferHeader() noexcept
            {}

            constexpr uint8 count() const noexcept  {
                return _count;
            }

            constexpr uint8 format() const noexcept {
                return _format;
            }

            constexpr size_t size() const noexcept {
                return _size;
            }

            constexpr RMVertexAttributeItem operator [] (std::size_t index) const noexcept {
                return _attrs[index];
            }

            void append(RMVertexAttribute attr, RMType type, RMAttributeElementSize size) noexcept {
                //assert(_count < 13);
                _attrs[_count] = RMVertexAttributeItem(attr, size, type, _size);
                _size += sizeOfRMType(type)*size;
                _count++;

                _format |= attr;
            }

            bool operator == (const RMVertexBufferHeader &header) const noexcept {
                if (this == &header) return true;

                if ( _format == header._format && _size == header._size && _count == header._count  ) {

                    for (uint8 index = 0; index < _count; ++index) {
                        if (_attrs[index] != header._attrs[index]) {
                            return false;
                        }
                    }

                    return true;
                }
                return false;
            }

            bool operator != (const RMVertexBufferHeader &header) const noexcept {
                return !(*this == header);
            }
        };
    }
}

#endif //RMPROPELLER_RMVERTEXBUFFERHEADER_HPP
