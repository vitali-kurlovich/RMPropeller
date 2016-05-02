//
// Created by Vitali Kurlovich on 5/1/16.
//

#ifndef RMPROPELLER_RMVERTEXBUFFER_HPP
#define RMPROPELLER_RMVERTEXBUFFER_HPP

#include "graphics/geometry/geometry_common.hpp"

#include "graphics/geometry/mesh/attribute/RMVertexAttributes.hpp"


namespace rmengine {

    namespace graphics {

        template<typename T>
        class RMVertexBuffer {
        protected:
            RMVertexAttributes _attributes;
            T* _buffer;
            uint32 _bufferSize;

        public:

            RMVertexBuffer(const RMVertexBuffer<T>& other)
            : _attributes(other._attributes), _buffer(other._buffer), _bufferSize(other._bufferSize) {

            }

            RMVertexBuffer(const RMVertexAttributes& attributes, T* buffer, const uint32 bufferSize)
            :_attributes(attributes), _buffer(buffer), _bufferSize(bufferSize) {

            }


        public:
            const RMVertexAttributes& getAttributes() const {
                return _attributes;
            }

            const T* getBuffer() const {
                return _buffer;
            }

            const uint32 getBufferSize() const {
                return _bufferSize;
            }
        };
    }
}


#endif //RMPROPELLER_RMVERTEXBUFFER_HPP
