//
// Created by Vitali Kurlovich on 5/4/16.
//

#ifndef RMPROPELLER_RMVBOBUFFER_HPP
#define RMPROPELLER_RMVBOBUFFER_HPP

#include "common/common.hpp"

namespace rmengine {

    namespace graphics {

        typedef enum : uint8 {

            RMDrawBufferType_Static     = 0,
            RMDrawBufferType_Dynamic    = 1,
            RMDrawBufferType_Stream     = 2

        } RMDrawBufferType;

        class RMDrawBuffer {
        protected:
            RMDrawBufferType _type:2;
        public:
            RMDrawBuffer(const RMDrawBuffer& other)
            : _type(other._type) {

            }

        };
    }
}

#endif //RMPROPELLER_RMVBOBUFFER_HPP
