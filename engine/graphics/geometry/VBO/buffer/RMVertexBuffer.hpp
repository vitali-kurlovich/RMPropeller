//
// Created by Vitali Kurlovich on 5/1/16.
//

#ifndef RMPROPELLER_RMVERTEXBUFFER_HPP
#define RMPROPELLER_RMVERTEXBUFFER_HPP

#include "common/common.hpp"

#include "graphics/geometry/VBO/buffer/attribute/RMVertexAttributes.hpp"


namespace rmengine {

    namespace graphics {

        class RMVertexBufferBase {
        protected:
            RMVertexAttributes _attributes;
            uint32 _bufferSize;
            void* _buffer;

        public:

            RMVertexBufferBase(const RMVertexBufferBase& other)
                    : _attributes(other._attributes), _buffer(other._buffer), _bufferSize(other._bufferSize) {

            }

            RMVertexBufferBase(const RMVertexAttributes& attributes, void* buffer, const uint32 bufferSize)
                    :_attributes(attributes), _buffer(buffer), _bufferSize(bufferSize) {

            }


            const RMVertexAttributes& getAttributes() const {
                return _attributes;
            }

            const void* getBuffer() const {
                return _buffer;
            }

            const uint32 getBufferSize() const {
                return _bufferSize;
            }
        };


        template<typename T>
        class RMVertexBuffer : public RMVertexBufferBase {

        public:

            RMVertexBuffer(const RMVertexBuffer<T>& other)
            : RMVertexBufferBase(other) {

            }

            RMVertexBuffer(const RMVertexAttributes& attributes, T* buffer, const uint32 bufferSize)
            : RMVertexBufferBase(attributes, buffer, bufferSize) {

            }

        public:

            const T* getVertexBuffer() const {
                return (T*)_buffer;
            }

        };
    }
}


#endif //RMPROPELLER_RMVERTEXBUFFER_HPP
