//
// Created by Vitali Kurlovich on 9/20/16.
//

#include "gtest/gtest.h"

#include <core/system/memory.hpp>



using namespace rmengine;


TEST(cpsmemcpy, uint8) {

    uint32 src[515];

    for (size_t index = 0; index <= 255; ++index) {
        src[index] = index;
    }

    int32 counter = 256;
    for (size_t index = 256; index < 512; ++index) {
        --counter;
        src[index] = counter;

        assert(counter>=0);
    }

    src[512] = 6;
    src[513] = 86;
    src[514] = 246;

    uint8 dst[515];

    memory::cpsmemcpy(dst,src, 515);

    for (size_t index = 0; index < 515; ++index) {
        EXPECT_EQ(src[index], dst[index]);
    }
}


TEST(cpsmemcpy, uint16) {

    uint32 src[131073];

    for (size_t index = 0; index <= 65535; ++index) {
        src[index] = index;
    }

    int32 counter = 65536;
    for (size_t index = 65536; index < 131072; ++index) {
        --counter;
        src[index] = counter;

        assert(counter>=0);
    }

    src[131072] = 61836;

    uint16 dst[131073];

    memory::cpsmemcpy(dst,src, 131073);

    for (size_t index = 0; index < 131073; ++index) {
        EXPECT_EQ(src[index], dst[index]);
    }
}