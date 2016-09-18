//
// Created by Vitali Kurlovich on 8/24/16.
//

#ifndef RMPROPELLER_RMOBJECT_HPP
#define RMPROPELLER_RMOBJECT_HPP

#include "../common/RMType.hpp"

namespace rmengine {

    class RMObject {
    private:
        int32 _refCount{1};
        //uint32 _uid{0};

    public:
        inline
        friend void rmRetain(RMObject** object) noexcept {
            (*object)->_refCount++;
        }

        inline
        friend void rmRetain(RMObject* object) noexcept {
            object->_refCount++;
        }

        inline
        friend void rmRelease(RMObject** object) {
            if ((*object)->_refCount != 1) {
                (*object)->_refCount--;
            } else {
                delete (*object);
                (*object) = nullptr;
            }
        }

        inline
        friend void rmRelease(RMObject* object) {
            if ((object)->_refCount != 1) {
                (object)->_refCount--;
            } else {
                delete (object);
            }
        }

        constexpr
        friend uint32 rmRetainCount(const RMObject* object) noexcept {
            return object->_refCount;
        }
    };
}


#endif //RMPROPELLER_RMOBJECT_HPP
