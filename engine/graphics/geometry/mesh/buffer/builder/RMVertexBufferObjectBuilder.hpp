//
// Created by Vitali Kurlovich on 9/18/16.
//

#ifndef RMPROPELLER_RMVERTEXBUFFEROBJECTBUILDER_HPP
#define RMPROPELLER_RMVERTEXBUFFEROBJECTBUILDER_HPP

#include <cstdlib>

#include "../RMVertexBufferHeader.hpp"
#include "../RMVertexBufferObject.hpp"

namespace rmengine {

    namespace graphics {

        namespace __utils {
            template<typename T>
            void setBufferValues(T *buffer, RMAttributeElementSize size, T x = 0, T y = 0, T z = 0, T w = 0) {
                if (size >= RMAttributeElementSize_1) buffer[0] = x;
                if (size >= RMAttributeElementSize_2) buffer[1] = y;
                if (size >= RMAttributeElementSize_3) buffer[2] = z;
                if (size >= RMAttributeElementSize_4) buffer[3] = w;
            }
        }

        class RMVertexBufferObjectBuilder {

            RMVertexBufferHeader _header{};
            uint32 _vertexCount{0};
            uint32 _indexCount{0};

            uint32 _lastVertexPosition{0};
            uint32 _lastIndexPosition{0};
            uint32 _maxVertexPosition{uint32_max};
            uint32 _maxIndexPosition{uint32_max};

            void *_vertexBuffer{nullptr};
            void *_indexBuffer{nullptr};
            RMIntegerType _indexType{RMIntegerType_U16};

            constexpr RMIntegerType integerTypeForCount(uint32 count) const noexcept {
                return count <= uint8_max ? RMIntegerType_U8 :
                       (count <= uint16_max ? RMIntegerType_U16 :
                        (count <= uint32_max ? RMIntegerType_U32 : RMIntegerType_U64));
            }

            inline
            void *buffer_ptr(size_t index, const RMVertexAttributeItem &item) {
                auto buffer = static_cast<uint8 *>(_vertexBuffer);
                buffer += _header.size() * index + item.offset;
                return static_cast<void *>(buffer);
            }

        public:
            RMVertexBufferObjectBuilder(const RMVertexBufferHeader &header, uint32 vertexCount, uint32 indexCount)
                    : _header(header), _vertexCount(vertexCount), _indexCount(indexCount),
                      _indexType(integerTypeForCount(indexCount)) {

                _vertexBuffer = std::malloc(_header.size() * _vertexCount);
                std::memset(_vertexBuffer, 0, _header.size() * _vertexCount);

                _indexBuffer = std::malloc(sizeOfRMType(_indexType) * _indexCount);
                std::memset(_indexBuffer, 0, sizeOfRMType(_indexType) * _indexCount);
            }

            ~RMVertexBufferObjectBuilder() {
                if (_vertexBuffer) free(_vertexBuffer);
                if (_indexBuffer) free(_indexBuffer);
            }

            const RMVertexBufferObject *build() {
                void *vertexBuffer = nullptr;
                RMVertexBuffer *vb = nullptr;
                if (_maxVertexPosition != uint32_max) {
                    size_t buffer_size = _header.size() * (_maxVertexPosition + 1);
                    vertexBuffer = std::malloc(buffer_size);
                    std::memcpy(vertexBuffer, _vertexBuffer, buffer_size);
                    vb = new RMVertexBuffer(_header, new RMObjectPtr(vertexBuffer), _maxVertexPosition + 1);
                }


                ;
                auto ib = new RMIndexBuffer(new RMObjectPtr(_indexBuffer), _indexCount, _indexType);
                //_vertexBuffer = nullptr;
                //_indexBuffer = nullptr;

                return new RMVertexBufferObject(vb, ib);
            }

            RMVertexBufferObjectBuilder &
            setVertex(size_t index, RMVertexAttribute attr, float x = 0, float y = 0, float z = 0,
                      float w = 0) noexcept;

            RMVertexBufferObjectBuilder &
            setVertex(size_t index, RMVertexAttribute attr, uint32 x = 0, uint32 y = 0, uint32 z = 0,
                      uint32 w = 0) noexcept;

            RMVertexBufferObjectBuilder &
            setVertex(size_t index, RMVertexAttribute attr, int32 x = 0, int32 y = 0, int32 z = 0,
                      int32 w = 0) noexcept;

            RMVertexBufferObjectBuilder &setVertex(size_t index, RMVertexAttribute attr, const vec4 &v) noexcept {
                return setVertex(index, attr, v.x, v.y, v.z, v.w);
            }

            RMVertexBufferObjectBuilder &setVertex(size_t index, RMVertexAttribute attr, const vec3 &v) noexcept {
                return setVertex(index, attr, v.x, v.y, v.z);
            }

            RMVertexBufferObjectBuilder &setVertex(size_t index, RMVertexAttribute attr, const vec2 &v) noexcept {
                return setVertex(index, attr, v.x, v.y);
            }


            RMVertexBufferObjectBuilder &
            setVertex(RMVertexAttribute attr, float x = 0, float y = 0, float z = 0,
                      float w = 0) noexcept {
                return setVertex(_lastVertexPosition, attr, x, y, z, w);
            }

            RMVertexBufferObjectBuilder &
            setVertex(RMVertexAttribute attr, uint32 x = 0, uint32 y = 0, uint32 z = 0,
                      uint32 w = 0) noexcept {
                return setVertex(_lastVertexPosition, attr, x, y, z, w);
            }

            RMVertexBufferObjectBuilder &
            setVertex(RMVertexAttribute attr, int32 x = 0, int32 y = 0, int32 z = 0,
                      int32 w = 0) noexcept {
                return setVertex(_lastVertexPosition, attr, x, y, z, w);
            }

            RMVertexBufferObjectBuilder &setVertex(RMVertexAttribute attr, const vec4 &v) noexcept {
                return setVertex(_lastVertexPosition, attr, v);
            }

            RMVertexBufferObjectBuilder &setVertex(RMVertexAttribute attr, const vec3 &v) noexcept {
                return setVertex(_lastVertexPosition, attr, v);
            }

            RMVertexBufferObjectBuilder &setVertex(RMVertexAttribute attr, const vec2 &v) noexcept {
                return setVertex(_lastVertexPosition, attr, v);
            }

            void setIndex(uint32 position, uint32 index) {

            }

        };

        RMVertexBufferObjectBuilder &
        RMVertexBufferObjectBuilder::setVertex(size_t index, RMVertexAttribute attr, float x, float y, float z,
                                               float w) noexcept {
            if (_header.supportAttribute(attr)) {
                auto item = _header[attr];

                if (isRealType(item.type)) {
                    switch (item.type) {
                        case RMType_Float:
                            __utils::setBufferValues<float>(static_cast<float *>(buffer_ptr(index, item)), item.size, x,
                                                            y, z, w);
                            break;

                        case RMType_HalfFloat:
                            // TODO
                            // __utils::setBufferValues<float>(static_cast<float *>(buffer_ptr(index, item)), item.size, x, y, z, w);
                            break;
                        default:
                            break;
                    }

                    _lastVertexPosition = index;
                    if (_maxVertexPosition == uint32_max) {
                        _maxVertexPosition = index;
                    } else if (_maxVertexPosition < index) {
                        _maxVertexPosition = index;
                    }

                } else {

                    if (isSignedType(item.type)) {
                        setVertex(index, attr,
                                  static_cast<int32>(x),
                                  static_cast<int32>(y),
                                  static_cast<int32>(z),
                                  static_cast<int32>(w));
                    } else {
                        setVertex(index, attr,
                                  static_cast<uint32>(x),
                                  static_cast<uint32>(y),
                                  static_cast<uint32>(z),
                                  static_cast<uint32>(w));
                    }
                }
            }
            return *this;
        }


        RMVertexBufferObjectBuilder &
        RMVertexBufferObjectBuilder::setVertex(size_t index, RMVertexAttribute attr, uint32 x, uint32 y, uint32 z,
                                               uint32 w) noexcept {

            if (_header.supportAttribute(attr)) {
                auto item = _header[attr];

                if (isIntegerType(item.type)) {
                    if (isUnsignedType(item.type)) {

                        switch (item.type) {
                            case RMType_UInt8:
                                __utils::setBufferValues<uint8>(static_cast<uint8 *>(buffer_ptr(index, item)),
                                                                item.size,
                                                                static_cast<uint8>(x),
                                                                static_cast<uint8>(y),
                                                                static_cast<uint8>(z),
                                                                static_cast<uint8>(w));
                                break;

                            case RMType_UInt16:
                                __utils::setBufferValues<uint16>(static_cast<uint16 *>(buffer_ptr(index, item)),
                                                                 item.size,
                                                                 static_cast<uint16>(x),
                                                                 static_cast<uint16>(y),
                                                                 static_cast<uint16>(z),
                                                                 static_cast<uint16>(w));
                                break;

                            case RMType_UInt32:
                                __utils::setBufferValues<uint32>(static_cast<uint32 *>(buffer_ptr(index, item)),
                                                                 item.size,
                                                                 static_cast<uint32>(x),
                                                                 static_cast<uint32>(y),
                                                                 static_cast<uint32>(z),
                                                                 static_cast<uint32>(w));
                                break;
                            default:
                                break;
                        }

                        _lastVertexPosition = index;
                        if (_maxVertexPosition == uint32_max) {
                            _maxVertexPosition = index;
                        } else if (_maxVertexPosition < index) {
                            _maxVertexPosition = index;
                        }

                    } else {
                        setVertex(index, attr,
                                  static_cast<int32>(x),
                                  static_cast<int32>(y),
                                  static_cast<int32>(z),
                                  static_cast<int32>(w));
                    }
                } else {
                    setVertex(index, attr,
                              static_cast<float>(x),
                              static_cast<float>(y),
                              static_cast<float>(z),
                              static_cast<float>(w));
                }
            }
            return *this;
        }

        RMVertexBufferObjectBuilder &
        RMVertexBufferObjectBuilder::setVertex(size_t index, RMVertexAttribute attr, int32 x, int32 y, int32 z,
                                               int32 w) noexcept {

            if (_header.supportAttribute(attr)) {
                auto item = _header[attr];

                if (isIntegerType(item.type)) {
                    if (isSignedType(item.type)) {

                        switch (item.type) {
                            case RMType_Int8:
                                __utils::setBufferValues<int8>(static_cast<int8 *>(buffer_ptr(index, item)), item.size,
                                                               static_cast<int8>(x),
                                                               static_cast<int8>(y),
                                                               static_cast<int8>(z),
                                                               static_cast<int8>(w));
                                break;

                            case RMType_Int16:
                                __utils::setBufferValues<int16>(static_cast<int16 *>(buffer_ptr(index, item)),
                                                                item.size,
                                                                static_cast<int16>(x),
                                                                static_cast<int16>(y),
                                                                static_cast<int16>(z),
                                                                static_cast<int16>(w));
                                break;

                            case RMType_Int32:
                                __utils::setBufferValues<int32>(static_cast<int32 *>(buffer_ptr(index, item)),
                                                                item.size,
                                                                static_cast<int32>(x),
                                                                static_cast<int32>(y),
                                                                static_cast<int32>(z),
                                                                static_cast<int32>(w));
                                break;
                            default:
                                break;
                        }

                        _lastVertexPosition = index;
                        if (_maxVertexPosition == uint32_max) {
                            _maxVertexPosition = index;
                        } else if (_maxVertexPosition < index) {
                            _maxVertexPosition = index;
                        }

                    } else {
                        return setVertex(index, attr,
                                         static_cast<uint32>(x),
                                         static_cast<uint32>(y),
                                         static_cast<uint32>(z),
                                         static_cast<uint32>(w));
                    }
                } else {
                    return setVertex(index, attr,
                                     static_cast<float>(x),
                                     static_cast<float>(y),
                                     static_cast<float>(z),
                                     static_cast<float>(w));
                }

            }
            return *this;
        }
    }
}


#endif //RMPROPELLER_RMVERTEXBUFFEROBJECTBUILDER_HPP
