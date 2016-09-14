//
// Created by Vitali Kurlovich on 9/12/16.
//

#ifndef RMPROPELLER_RMSUBINDEXBUFFER_HPP
#define RMPROPELLER_RMSUBINDEXBUFFER_HPP


#include "../../geometry_common.hpp"

#include "RMIndexBuffer.hpp"

namespace rmengine {

    namespace graphics {

        class RMSubIndexBuffer : public RMObject {
            RMIndexBuffer* _indexBuffer{nullptr};
            uint32 _count{0};
            uint32 _location{0};
            size_t _size{0};


        public:
            constexpr
            void* data() const noexcept {
                return _indexBuffer->data();
            }

            constexpr
            uint32 count() const noexcept {
                return _count;
            }

            constexpr
            RMIntegerType type() const noexcept {
                return _indexBuffer->type();
            }

            constexpr
            uint32 location() const noexcept {
                return _location;
            }

            constexpr
            size_t size() const noexcept {
                return _size;
            }

        };
    }
}

#endif //RMPROPELLER_RMSUBINDEXBUFFER_HPP
