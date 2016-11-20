//
// Created by Vitali Kurlovich on 11/19/16.
//

#include "gtest/gtest.h"

#include <core/buffer/RMMemmoryBuffer.hpp>

using namespace rmengine;
using namespace rmengine::buffer;

TEST(RMMemmoryBuffer, constructor) {

    uint8 dataA[4000];
    uint8 dataC[8000];
    uint8 dataB[80];


    for (size_t index = 0; index < 4000; ++index) {
        dataA[index] = 0xc0;
    }

    for (size_t index = 0; index < 80; ++index) {
        dataB[index] = 0xde;
    }

    for (size_t index = 0; index < 8000; ++index) {
        dataC[index] = 0x7f;
    }

    RMMemmoryBuffer buffer;

    buffer.write(dataA, 4000);
    buffer.write(dataB, 80);
    buffer.write(dataC, 8000);

    uint8 dst[4000+80+8000];
    EXPECT_TRUE(buffer.read(dst, 4000+80+8000));
    EXPECT_EQ(buffer.seek(), 4000+80+8000);

    for (size_t index = 0; index < 4000; ++index) {
        //dataA[index] = 0xc0;
        EXPECT_EQ(dst[index], 0xc0);
    }

    for (size_t index = 4000; index < (4000+80); ++index) {
        //dataB[index] = 0xde;
        EXPECT_EQ(dst[index], 0xde);
    }

    for (size_t index = (4000+80); index < (4000+80+8000); ++index) {
        //dataC[index] = 0x7f;
        EXPECT_EQ(dst[index], 0x7f);
    }


    uint8 dataD[12000];
    for (size_t index = 0; index < 12000; ++index) {
        dataD[index] = 0x32;
    }

    buffer.write(dataD, 12000);

    uint8 dsta[4000+80+8000+12000];
    EXPECT_TRUE(buffer.seek(0));
    EXPECT_TRUE(buffer.read(dsta, 4000+80+8000+12000));

    EXPECT_EQ(buffer.seek(), 4000+80+8000+12000);

    for (size_t index = 0; index < 4000; ++index) {
        //dataA[index] = 0xc0;
        EXPECT_EQ(dsta[index], 0xc0);
    }

    for (size_t index = 4000; index < (4000+80); ++index) {
        //dataB[index] = 0xde;
        EXPECT_EQ(dsta[index], 0xde);
    }

    for (size_t index = (4000+80); index < (4000+80+8000); ++index) {
        //dataC[index] = 0x7f;
        EXPECT_EQ(dsta[index], 0x7f);
    }

    for (size_t index = (4000+80+8000); index < (4000+80+8000+12000); ++index) {
        //dataC[index] = 0x7f;
        //dataD[index] = 0x32;
        EXPECT_EQ(dsta[index], 0x32);
    }

    uint8 dataE[128];
    for (size_t index = 0; index < 128; ++index) {
        dataE[index] = index;
    }

    buffer.write(dataE, 128);

    uint8 dstb[4000+80+8000+12000+128];

    EXPECT_TRUE(buffer.seek(0));
    EXPECT_TRUE(buffer.read(dstb, 4000+80+8000+12000+128));

    EXPECT_EQ(buffer.seek(), 4000+80+8000+12000+128);

    for (size_t index = (4000+80+8000+12000); index < (4000+80+8000+12000+128); ++index) {
        auto val = index - (4000+80+8000+12000);
        EXPECT_EQ(dstb[index], val);
    }

    EXPECT_TRUE(buffer.seek(4000+80+8000));

    uint8 dstc[12000];

    EXPECT_TRUE(buffer.read(dstc, 12000));

    EXPECT_EQ(buffer.seek(), 4000+80+8000+12000);

    for (size_t index = 0; index < 12000; ++index) {
        EXPECT_EQ(dstc[index], 0x32);
    }

    EXPECT_TRUE(buffer.read(dstc, 128));

    EXPECT_EQ(buffer.seek(), 4000+80+8000+12000+128);


    for (size_t index = 0; index < 128; ++index) {
        EXPECT_EQ(dstc[index], index);
    }

    EXPECT_TRUE(buffer.seek(4000+80+8000 + 11000));

    EXPECT_TRUE(buffer.read(dstc, 1000+128));

    for (size_t index = 0; index < 1000; ++index) {
        EXPECT_EQ(dstc[index], 0x32);
    }

    for (size_t index = 1000; index < 1000+128; ++index) {
        EXPECT_EQ(dstc[index], index-1000);
    }

}