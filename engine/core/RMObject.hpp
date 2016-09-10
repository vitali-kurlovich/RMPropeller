//
// Created by Vitali Kurlovich on 8/24/16.
//

#ifndef RMPROPELLER_RMOBJECT_HPP
#define RMPROPELLER_RMOBJECT_HPP

#include "../common/common.hpp"

namespace rmengine {

    class RMObject {
    private:
        uint32 _refCount{1};

        friend void retainRef(const RMObject* object) {
            _refCount++;
        }

        friend void releaseRef(const RMObject* object) {

            if (object->_refCount == 1) {

            }
        }
    };
}

#endif //RMPROPELLER_RMOBJECT_HPP
