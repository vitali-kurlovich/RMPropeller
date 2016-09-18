//
// Created by Vitali Kurlovich on 9/11/16.
//

#ifndef RMPROPELLER_RMVERTEXBUFFERHEADER_HPP
#define RMPROPELLER_RMVERTEXBUFFERHEADER_HPP


#include <algorithm>

#include "graphics/geometry/geometry_common.hpp"
#include "RMVertexAttribute.hpp"

namespace rmengine {

    namespace graphics {

        class RMVertexBufferHeader final {
        private:
            RMVertexAttributeItem _attrs[13]{
                    RMVertexAttributeItem{RMVertexAttribute_None, RMAttributeElementSize_None, RMType_None},
                    RMVertexAttributeItem{RMVertexAttribute_None, RMAttributeElementSize_None, RMType_None},
                    RMVertexAttributeItem{RMVertexAttribute_None, RMAttributeElementSize_None, RMType_None},
                    RMVertexAttributeItem{RMVertexAttribute_None, RMAttributeElementSize_None, RMType_None},
                    RMVertexAttributeItem{RMVertexAttribute_None, RMAttributeElementSize_None, RMType_None},

                    RMVertexAttributeItem{RMVertexAttribute_None, RMAttributeElementSize_None, RMType_None},
                    RMVertexAttributeItem{RMVertexAttribute_None, RMAttributeElementSize_None, RMType_None},
                    RMVertexAttributeItem{RMVertexAttribute_None, RMAttributeElementSize_None, RMType_None},
                    RMVertexAttributeItem{RMVertexAttribute_None, RMAttributeElementSize_None, RMType_None},
                    RMVertexAttributeItem{RMVertexAttribute_None, RMAttributeElementSize_None, RMType_None},

                    RMVertexAttributeItem{RMVertexAttribute_None, RMAttributeElementSize_None, RMType_None},
                    RMVertexAttributeItem{RMVertexAttribute_None, RMAttributeElementSize_None, RMType_None},
                    RMVertexAttributeItem{RMVertexAttribute_None, RMAttributeElementSize_None, RMType_None}
            };
            uint16 _format{0};
            uint8 _count{0};
            uint8 _size{0};

        public:

            constexpr
            RMVertexBufferHeader() noexcept {}

            constexpr uint8 count() const noexcept {
                return _count;
            }

            constexpr uint8 format() const noexcept {
                return _format;
            }

            constexpr size_t size() const noexcept {
                return _size;
            }

            constexpr RMVertexAttributeItem operator[](std::size_t index) const noexcept {
                return _attrs[index];
            }

            void set(RMVertexAttribute attr, RMType type, RMAttributeElementSize size) noexcept {

                uint8 index = indexOf(attr);
                if (index != uint8_max) {
                       _attrs[index].type = type;
                       _attrs[index].size = size;
                } else {
                    _format |= attr;

                    _attrs[_count].attribute = attr;
                    _attrs[_count].type = type;
                    _attrs[_count].size = size;

                    ++_count;
                    std::sort(_attrs, _attrs + _count);
                }

                _size = 0;

                for (uint8 index = 0; index < _count; ++index) {
                    _attrs[index].offset = _size;
                    _size += sizeOfRMType(_attrs[index].type) * _attrs[index].size;
                }
            }

            void remove(RMVertexAttribute attr) noexcept {
                uint8 index = indexOf(attr);
                if (index != uint8_max) {

                    _format &= ~attr;
                    --_count;
                    _size = _attrs[index].offset;

                    for (; index < _count; ++index) {
                        _attrs[index] = _attrs[index + 1];
                        _attrs[index].offset = _size;
                        _size += sizeOfRMType(_attrs[index].type) * _attrs[index].size;
                    }
                }
            }

            constexpr
            uint8 indexOf(RMVertexAttribute attr) const noexcept {
                return (_format & attr) == 0 ? uint8_max :
                       (_attrs[0].attribute == attr ? 0 :
                        (_attrs[1].attribute == attr ? 1 :
                         (_attrs[2].attribute == attr ? 2 :
                          (_attrs[3].attribute == attr ? 3 :
                           (_attrs[4].attribute == attr ? 4 :
                            (_attrs[5].attribute == attr ? 5 :
                             (_attrs[6].attribute == attr ? 6 :
                              (_attrs[7].attribute == attr ? 7 :
                               (_attrs[8].attribute == attr ? 8 :
                                (_attrs[9].attribute == attr ? 9 :
                                 (_attrs[10].attribute == attr ? 10 :
                                  (_attrs[11].attribute == attr ? 11 : 12)
                                 )
                                )
                               )
                              )
                             )
                            )
                           )
                          )
                         )
                        )
                       );
            }


            bool operator == (const RMVertexBufferHeader &header) const noexcept {
                if (this == &header) return true;

                if (_format == header._format && _size == header._size && _count == header._count) {

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
