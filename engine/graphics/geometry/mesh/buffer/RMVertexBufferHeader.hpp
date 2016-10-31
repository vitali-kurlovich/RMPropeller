//
// Created by Vitali Kurlovich on 9/11/16.
//

#ifndef RMPROPELLER_RMVERTEXBUFFERHEADER_HPP
#define RMPROPELLER_RMVERTEXBUFFERHEADER_HPP


#include <algorithm>
#include <assert.h>

#include "graphics/geometry/geometry_common.hpp"
#include "RMVertexAttribute.hpp"

namespace rmengine {

    namespace graphics {

        class RMVertexBufferHeader final {
        private:
            std::vector<RMVertexAttributeItem> attrs;
            uint16 _format{0};
            uint8 _size{0};

        public:

            RMVertexBufferHeader(std::initializer_list<RMVertexAttributeItem> list)
#ifdef NDEBUG
            noexcept
#endif
                : attrs(list), _format(0), _size(0)
                {
                    for(auto &item: attrs) {

                        assert((_format & item.attribute) == 0);
                        _format |= item.attribute;

                        assert(item.offset == _size);
                        _size += sizeOfRMType(item.type)*item.size;
                    }
                }

            RMVertexBufferHeader(const std::vector<RMVertexAttributeItem>& items)
#ifdef NDEBUG
            noexcept
#endif
            : attrs(items), _format(0), _size(0)
            {
                for(auto &item: attrs) {
                    _format |= item.attribute;

                    assert(item.offset == _size);
                    _size += sizeOfRMType(item.type)*item.size;
                }
            }

            RMVertexBufferHeader(const RMVertexBufferHeader& header) noexcept
            : attrs(header.attrs), _format(header._format), _size(header._size)
            {

            }

            constexpr
            uint8 count() const noexcept {
                return attrs.size();
            }

            constexpr
            uint8 format() const noexcept {
                return _format;
            }

            constexpr
            size_t size() const noexcept {
                return _size;
            }

            constexpr
            bool supportAttribute(RMVertexAttribute attr) const noexcept {
                return (_format & attr) != 0;
            }

            constexpr
            RMVertexAttributeItem operator[](std::size_t index) const noexcept {
                return attrs[index];
            }


            RMVertexAttributeItem operator[](RMVertexAttribute attr) const noexcept {
                if ((_format & attr) != 0 ) {
                    for (auto &item : attrs) {
                        if (item.attribute == attr) return item;
                    }
                }
                return  RMVertexAttributeItem::none();
            }

            bool operator == (const RMVertexBufferHeader &header) const noexcept {
                return _format == header._format && _size == header._size && attrs == header.attrs;
            }

            bool operator != (const RMVertexBufferHeader &header) const noexcept {
                return !(*this == header);
            }
        };
    }
}

#endif //RMPROPELLER_RMVERTEXBUFFERHEADER_HPP
