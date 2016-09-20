//
// Created by Vitali Kurlovich on 9/20/16.
//

#ifndef RMPROPELLER_MEMORY_HPP
#define RMPROPELLER_MEMORY_HPP

#include "../../common/rmtypes.hpp"

namespace rmengine {

    namespace memory {
        inline
        uint8* cpsmemcpy( uint8* dst, const uint32* source, size_t num ) {
            for (size_t index = 0; index < num; ++index) {
                assert(source[index] <= uint8_max);
                dst[index] = static_cast<uint8>(source[index]);
            }
            return dst;
        }

        inline
        uint16* cpsmemcpy( uint16* dst, const uint32* source, size_t num ) {
            for (size_t index = 0; index < num; ++index) {
                assert(source[index] <= uint16_max);
                dst[index] = static_cast<uint16>(source[index]);
            }
            return dst;
        }
    }
}

#endif //RMPROPELLER_MEMORY_HPP
