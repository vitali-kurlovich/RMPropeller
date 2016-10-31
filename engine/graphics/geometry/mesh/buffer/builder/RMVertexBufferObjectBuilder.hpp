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

            uint32 _maxIndexValue{uint32_max};

            void *_vertexBuffer{nullptr};
            uint32 *_indexBuffer{nullptr};

            constexpr
            RMIntegerType integerTypeForCount(uint32 count) const noexcept {
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

            void rebaseVertexBuffer(uint32 vertexCount) noexcept;
            void rebaseIndexBuffer(uint32 vertexCount) noexcept;


        public:
            RMVertexBufferObjectBuilder(const RMVertexBufferHeader &header, uint32 vertexCount)
                    : _header(header), _vertexCount(vertexCount), _indexCount(vertexCount*3 - 6) {

                _vertexBuffer = std::malloc(_header.size() * _vertexCount);
                std::memset(_vertexBuffer, 0, _header.size() * _vertexCount);

                size_t indexBufferSize = sizeof(uint32) * _indexCount;
                _indexBuffer = static_cast<uint32*>(std::malloc(indexBufferSize));
                std::memset(_indexBuffer, 0, indexBufferSize);
            }

            ~RMVertexBufferObjectBuilder() {
                if (_vertexBuffer) free(_vertexBuffer);
                if (_indexBuffer) free(_indexBuffer);
            }

            const RMVertexBufferObject *build() {

                void *vertexBuffer = nullptr;
                RMVertexBuffer *vb = nullptr;
                if (_maxVertexPosition != uint32_max && _maxIndexPosition != uint32_max) {
                    size_t buffer_size = _header.size() * (_maxIndexValue + 1);
                    vertexBuffer = std::malloc(buffer_size);
                    std::memcpy(vertexBuffer, _vertexBuffer, buffer_size);
                    vb = new RMVertexBuffer(_header, new RMObjectPtr(vertexBuffer), _maxIndexValue + 1);
                }

                void* indexBuffer = nullptr;
                RMIndexBuffer* ib = nullptr;

                if (_maxIndexPosition != uint32_max) {

                    auto type = integerTypeForCount(_maxIndexValue);
                    const uint32 indexCount((_maxIndexPosition + 1));

                    size_t buffer_size = sizeOfRMType(type) * indexCount;

                    indexBuffer = std::malloc(buffer_size);

                    switch (type) {
                        case RMIntegerType_U8:
                            memory::cpsmemcpy(static_cast<uint8*>(indexBuffer), _indexBuffer, indexCount);
                            break;

                        case RMIntegerType_U16:
                            memory::cpsmemcpy(static_cast<uint16*>(indexBuffer), _indexBuffer, indexCount);
                            break;

                        default:
                            std::memcpy(indexBuffer, _indexBuffer, buffer_size);
                            break;
                    }

                    ib = new RMIndexBuffer(new RMObjectPtr(indexBuffer), indexCount, type);
                }

                return new RMVertexBufferObject(vb, ib);
            }

            constexpr
            uint32 vertexCount() const noexcept {
                return _maxVertexPosition == uint32_max ? 0 : (_maxVertexPosition + 1);
            }

            constexpr
            uint32 indexesCount() const noexcept {
                return _maxIndexPosition == uint32_max ? 0 : (_maxIndexPosition + 1);
            }

            constexpr
            uint32 lastVertexPosition() const noexcept {
                return vertexCount() > 0 ? _lastVertexPosition : uint32_max;
            }

            constexpr
            uint32 lastIndexPosition() const noexcept {
                return indexesCount() > 0 ? _lastIndexPosition : uint32_max ;
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

            RMVertexBufferObjectBuilder& setIndex(uint32 position, uint32 index) {

                assert(_maxVertexPosition >= index);

                if (position >= _indexCount) {
                    rebaseIndexBuffer(position*16/9);
                }

                _indexBuffer[position] = index;

                _lastIndexPosition = position;

                if (_maxIndexPosition == uint32_max) {
                    _maxIndexPosition = position;
                } else if (_maxIndexPosition < position) {
                    _maxIndexPosition = position;
                }

                if (_maxIndexValue == uint32_max) {
                    _maxIndexValue = index;
                } else if (index > _maxIndexValue) {
                    _maxIndexValue = index;
                }
                return *this;
            }

            RMVertexBufferObjectBuilder& appendIndex(uint32 index) {
                auto pos = lastIndexPosition();
                if (pos == uint32_max) {
                    pos = 0;
                } else {
                    ++pos;
                }
                return setIndex(pos, index);
            }

            RMVertexBufferObjectBuilder& appendPolygon(uint32 a, uint32 b, uint32 c) {
                return appendIndex(a).appendIndex(b).appendIndex(c);
            }

        };

        RMVertexBufferObjectBuilder &
        RMVertexBufferObjectBuilder::setVertex(size_t index, RMVertexAttribute attr, float x, float y, float z,
                                               float w) noexcept {

            _lastVertexPosition = index;

            if (_header.supportAttribute(attr)) {

                if (index >= _vertexCount) {
                    rebaseVertexBuffer(index*16/9);
                }

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


            _lastVertexPosition = index;

            if (_header.supportAttribute(attr)) {

                if (index >= _vertexCount) {
                    rebaseVertexBuffer(index*16/9);
                }

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

            _lastVertexPosition = index;

            if (_header.supportAttribute(attr)) {

                if (index >= _vertexCount) {
                    rebaseVertexBuffer(index*16/9);
                }

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

        void RMVertexBufferObjectBuilder::rebaseVertexBuffer(uint32 vertexCount) noexcept {
            if (_vertexCount < vertexCount) {

                size_t bufferSize(_header.size() * vertexCount);
                auto buffer = std::malloc(bufferSize);

                std::memset(buffer, 0, bufferSize);
                std::memcpy(buffer, _vertexBuffer, _header.size() * (_maxVertexPosition + 1));

                std::swap(buffer, _vertexBuffer);
                free(buffer);

                _vertexCount = vertexCount;
            }
        }

        void RMVertexBufferObjectBuilder::rebaseIndexBuffer(uint32 indexCount) noexcept {
          if (_indexCount < indexCount) {
              size_t bufferSize(sizeof(uint32) * indexCount);

              auto buffer = static_cast<uint32*>(std::malloc(bufferSize));

              std::memset(buffer, 0, bufferSize);
              std::memcpy(buffer, _indexBuffer, sizeof(uint32) *  (_maxIndexPosition + 1));

              std::swap(buffer, _indexBuffer);

              _indexCount = indexCount;
          }
        }
    }
}


#endif //RMPROPELLER_RMVERTEXBUFFEROBJECTBUILDER_HPP
