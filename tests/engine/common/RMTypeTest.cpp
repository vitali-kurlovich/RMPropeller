//
// Created by Vitali Kurlovich on 5/2/16.
//

#include "gtest/gtest.h"

#include <common/RMType.hpp>

using namespace rmengine;

TEST(RMTypeTest, cases) {

    EXPECT_TRUE(isUnsignedType(RMType_UInt8));
    EXPECT_TRUE(isUnsignedType(RMType_UInt16));
    EXPECT_TRUE(isUnsignedType(RMType_UInt32));
    EXPECT_TRUE(isUnsignedType(RMType_UInt64));

    EXPECT_TRUE(isSignedType(RMType_Int8));
    EXPECT_TRUE(isSignedType(RMType_Int16));
    EXPECT_TRUE(isSignedType(RMType_Int32));
    EXPECT_TRUE(isSignedType(RMType_Int64));

    EXPECT_TRUE(isSignedType(RMType_Float));


    EXPECT_TRUE(isIntegerType(RMType_UInt8));
    EXPECT_TRUE(isIntegerType(RMType_UInt16));
    EXPECT_TRUE(isIntegerType(RMType_UInt32));
    EXPECT_TRUE(isIntegerType(RMType_UInt64));

    EXPECT_TRUE(isRealType(RMType_Float));

}