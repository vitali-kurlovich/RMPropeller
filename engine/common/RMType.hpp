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
        RMType_None     = 0,
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


    typedef enum : uint8 {
        RMIntegerType_8 = RMType_Int8,
        RMIntegerType_U8 = RMType_UInt8,

        RMIntegerType_16 = RMType_Int16,
        RMIntegerType_U16 = RMType_UInt16,

        RMIntegerType_32 = RMType_Int32,
        RMIntegerType_U32 = RMType_UInt32,

        RMIntegerType_64 = RMType_Int64,
        RMIntegerType_U64 = RMType_UInt64,

    } RMIntegerType;


    typedef enum : uint8 {
        RMRealType_Low = RMType_HalfFloat,
        RMRealType_Medium = RMType_Float,
        RMRealType_Hight =  RMType_Double
    } RMRealType;

    constexpr
    bool isUnsignedType(const RMType type) noexcept {
        return (type & __RMTypeUnsignedBitFlag) != 0;
    }

    constexpr
    bool isUnsignedType(const RMIntegerType type) noexcept {
        return (type & __RMTypeUnsignedBitFlag) != 0;
    }

    constexpr
    bool isSignedType(const RMType type) noexcept {
        return (type & __RMTypeUnsignedBitFlag) == 0;
    }

    constexpr
    bool isSignedType(const RMIntegerType type) noexcept {
        return (type & __RMTypeUnsignedBitFlag) == 0;
    }

    constexpr
    bool isIntegerType(const RMType type) noexcept {
        return (type & __RMTypeRealBitFlag) == 0;
    }

    constexpr
    bool isIntegerType(const RMIntegerType type) noexcept {
        return true;
    }

    constexpr
    bool isRealType(const RMType type) noexcept {
        return (type & __RMTypeRealBitFlag) != 0;
    }

    constexpr
    bool isRealType(const RMIntegerType type) noexcept {
        return false;
    }

    constexpr
    size_t sizeOfRMType(RMType type) noexcept {
        return static_cast<size_t>( 1 << (type & 0x03));
    }

    constexpr
    size_t sizeOfRMType(RMIntegerType type) noexcept {
        return static_cast<size_t>( 1 << (type & 0x03));
    }

    constexpr
    size_t sizeOfRMType(RMRealType type) noexcept {
        return static_cast<size_t>( 1 << (type & 0x03));
    }


    constexpr
    uint64 maxValueForType(const RMIntegerType type) noexcept {
        return isUnsignedType(type) ?
               type == RMIntegerType_U32 ? uint32_max :
               (type == RMIntegerType_U16 ? uint16_max:
                (type == RMIntegerType_U8 ? uint8_max : uint64_max))
               :
               type == RMIntegerType_32 ? int32_max :
               (type == RMIntegerType_16 ? int16_max:
                (type == RMIntegerType_8 ? int8_max : int64_max))
                ;
    }
}

#endif //RMPROPELLER_RMTYPE_HPP
