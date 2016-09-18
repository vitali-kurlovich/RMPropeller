//
// Created by Vitali Kurlovich on 9/13/16.
//

#ifndef RMPROPELLER_RMOBJECTPTR_HPP
#define RMPROPELLER_RMOBJECTPTR_HPP


#include "RMObject.hpp"

namespace rmengine {

    class RMObjectPtr final : public RMObject {
        void *_ptr{nullptr};

    public:
        constexpr
        RMObjectPtr(void *ptr) noexcept
                : _ptr(ptr) {
        }

        ~RMObjectPtr() {
            if (_ptr) free(_ptr);
        }

        constexpr void* get() const noexcept {
            return _ptr;
        }



    };
}

#endif //RMPROPELLER_RMOBJECTPTR_HPP
