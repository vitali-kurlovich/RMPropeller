//
// Created by Vitali Kurlovich on 9/13/16.
//

#ifndef RMPROPELLER_RMOBJECTPTR_HPP
#define RMPROPELLER_RMOBJECTPTR_HPP


#include "../common/common.hpp"



namespace rmengine {


        class RMObjectPtr final : public RMObject  {
            void* _ptr{nullptr};

        public:
            constexpr
            RMObjectPtr(void* ptr) noexcept
            :_ptr(ptr)
            {
            }

            ~RMObjectPtr() {
                if (_ptr) delete _ptr;
            }


        };


    class RMObjectArrayPtr final : public RMObject {
        void* _ptr{nullptr};

    public:
        constexpr
        RMObjectArrayPtr(void* ptr) noexcept
                :_ptr(ptr)
        {

        }

        ~RMObjectArrayPtr() {
            if (_ptr) delete[] _ptr;
        }
    };
}

#endif //RMPROPELLER_RMOBJECTPTR_HPP
