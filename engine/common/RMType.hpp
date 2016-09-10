//
// Created by Vitali Kurlovich on 5/2/16.
//

#ifndef RMPROPELLER_RMTYPE_HPP
#define RMPROPELLER_RMTYPE_HPP

#include  "rmtypes.hpp"

namespace rmengine {

    static const uint8 __RMTypeUnsignedBitFlag = 1<<7;
    static const uint8 __RMTypeRealBitFlag = 1<<6;

    static const uint8 __RMTypeSize_1 = 0;
    static const uint8 __RMTypeSize_2 = 1;
    static const uint8 __RMTypeSize_4 = 2;
    static const uint8 __RMTypeSize_8 = 3;


    typedef enum : uint8 {
        RMType_Int8     =  __RMTypeSize_1,
        RMType_UInt8    = (__RMTypeSize_1 | __RMTypeUnsignedBitFlag),

        RMType_Int16    = __RMTypeSize_2,
        RMType_UInt16   = (__RMTypeSize_2 |__RMTypeUnsignedBitFlag),

        RMType_Int32    =  __RMTypeSize_4,
        RMType_UInt32   = (__RMTypeSize_4 | __RMTypeUnsignedBitFlag),

        RMType_Int64    =  __RMTypeSize_8,
        RMType_UInt64   = (__RMTypeSize_8 | __RMTypeUnsignedBitFlag),

        RMType_HalfFloat = (__RMTypeSize_2 | __RMTypeRealBitFlag),
        RMType_Float     = (__RMTypeSize_4 | __RMTypeRealBitFlag),
        RMType_Double    = (__RMTypeSize_8 | __RMTypeRealBitFlag)

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
