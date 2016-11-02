//
// Created by Vitali Kurlovich on 9/13/16.
//

#ifndef RMPROPELLER_RMOBJECTPTR_HPP
#define RMPROPELLER_RMOBJECTPTR_HPP

#include <cstdlib>

#include "RMObject.hpp"

namespace rmengine {

    class RMObjectPtr final : public RMObject {
        void *_ptr{nullptr};
        size_t _size{0};

    public:

        constexpr
        RMObjectPtr() noexcept {
        }

        constexpr
        RMObjectPtr(size_t size) noexcept
                : _size(size) {
        }

        ~RMObjectPtr() {
            if (_ptr) free(_ptr);
        }

        void memcopy(const void* src, size_t copysize) {
            if (_size == 0) {
                _size = copysize;
            }
            if (_ptr == nullptr) {
                _ptr = malloc(_size);
            }
            assert(copysize <= _size);
            std::memcpy(_ptr, src, copysize);
        }

        void* get()  noexcept {
            if (_ptr == nullptr && _size > 0) {
                _ptr =  malloc(_size);
            }
            return _ptr;
        }
    };
}

#endif //RMPROPELLER_RMOBJECTPTR_HPP
