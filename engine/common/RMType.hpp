//
// Created by Vitali Kurlovich on 5/2/16.
//

#ifndef RMPROPELLER_RMTYPE_HPP
#define RMPROPELLER_RMTYPE_HPP

#include  "rmtypes.hpp"

namespace rmengine {

    static const uint8 __RMTypeUnsignedBitFlag = 1<<7;
    static const uint8 __RMTypeRealBitFlag = 1<<6;


    typedef enum : uint8 {
        RMType_Int8     =  0,
        RMType_UInt8    = (0 | __RMTypeUnsignedBitFlag),

        RMType_Int16    = 1,
        RMType_UInt16   = (1 |__RMTypeUnsignedBitFlag),

        RMType_Int32    =  2,
        RMType_UInt32   = (2 | __RMTypeUnsignedBitFlag),

        RMType_Int64    =  3,
        RMType_UInt64   = (3 | __RMTypeUnsignedBitFlag),

        RMType_Float    = (4 | __RMTypeRealBitFlag)

    } RMType;


    inline bool isUnsignedType(const RMType type) {
        return (type & __RMTypeUnsignedBitFlag) != 0;
    }

    inline bool isSignedType(const RMType type) {
        return (type & __RMTypeUnsignedBitFlag) == 0;
    }

    inline bool isIntegerType(const RMType type) {
        return (type & __RMTypeRealBitFlag) == 0;
    }

    inline bool isRealType(const RMType type) {
        return (type & __RMTypeRealBitFlag) != 0;
    }

}

#endif //RMPROPELLER_RMTYPE_HPP
