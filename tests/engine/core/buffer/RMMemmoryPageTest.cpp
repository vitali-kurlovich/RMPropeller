//
// Created by Vitali Kurlovich on 11/19/16.
//

#include "gtest/gtest.h"

#include <core/buffer/RMMemmoryPage.hpp>

using namespace rmengine;
using namespace rmengine::buffer;


TEST(RMMemmoryPage, constructor) {

RMMemmoryPage page(200);
    EXPECT_EQ(page.pageSize(), 200);
    EXPECT_EQ(page.offset(), 0);
    EXPECT_EQ(page.size(), uint32_max);
    EXPECT_EQ(page.buffer(), nullptr);

    EXPECT_TRUE(page.canWrite(20));
    EXPECT_TRUE(page.canWrite(520));


    uint8 data[] = {56,2,5,3,6,7};

    EXPECT_TRUE(page.write(data, 6));

    EXPECT_TRUE(page.canWrite(20));
    EXPECT_FALSE(page.canWrite(4520));

    EXPECT_EQ(page.pageSize(), RMMEM_PAGE_SIZE);
    EXPECT_EQ(page.offset(), 6);
    EXPECT_EQ(page.size(), RMMEM_PAGE_SIZE - 6);

    EXPECT_TRUE(page.write(data, 6));

    EXPECT_EQ(page.offset(), 12);
    EXPECT_EQ(page.size(), RMMEM_PAGE_SIZE - 12);


    RMMemmoryPage pagea;

    EXPECT_EQ(pagea.pageSize(), 0);
    EXPECT_EQ(pagea.offset(), 0);
    EXPECT_EQ(pagea.size(), uint32_max);
    EXPECT_EQ(pagea.buffer(), nullptr);


    EXPECT_TRUE(pagea.canWrite(20));

    EXPECT_TRUE(pagea.write(data, 6));

    EXPECT_EQ(pagea.pageSize(), RMMEM_PAGE_SIZE);
    EXPECT_EQ(pagea.offset(), 6);
    EXPECT_EQ(pagea.size(), RMMEM_PAGE_SIZE - 6);

    EXPECT_FALSE(pagea.canWrite(4100));
}


TEST(RMMemmoryPage, read_write) {
    RMMemmoryPage page(200);
    uint8 data[] = {56,2,5,3,6,7};
    EXPECT_TRUE(page.write(data, 6));
    EXPECT_TRUE(page.write(data, 6));
    EXPECT_TRUE(page.write(data, 6));

    EXPECT_EQ(page.pageSize(), RMMEM_PAGE_SIZE);
    EXPECT_EQ(page.offset(), 18);
    EXPECT_EQ(page.size(), RMMEM_PAGE_SIZE - 18);

    uint8 *buffer =(uint8 *)page.buffer();

    EXPECT_EQ(buffer[0],56);
    EXPECT_EQ(buffer[1],2);
    EXPECT_EQ(buffer[2],5);
    EXPECT_EQ(buffer[3],3);
    EXPECT_EQ(buffer[4],6);
    EXPECT_EQ(buffer[5],7);

    EXPECT_EQ(buffer[6],56);
    EXPECT_EQ(buffer[7],2);
    EXPECT_EQ(buffer[8],5);
    EXPECT_EQ(buffer[9],3);
    EXPECT_EQ(buffer[10],6);
    EXPECT_EQ(buffer[11],7);

    EXPECT_EQ(buffer[12],56);
    EXPECT_EQ(buffer[13],2);
    EXPECT_EQ(buffer[14],5);
    EXPECT_EQ(buffer[15],3);
    EXPECT_EQ(buffer[16],6);
    EXPECT_EQ(buffer[17],7);


    EXPECT_EQ( page.buffer(), buffer );

}


TEST(RMMemmoryPage, recycle) {
    RMMemmoryPage page(32);
    EXPECT_EQ(page.pageSize(), 32);
    EXPECT_EQ(page.offset(), 0);
    EXPECT_EQ(page.size(), uint32_max);
    EXPECT_EQ(page.buffer(), nullptr);

    uint8 dataB[800];
    uint8 dataA[4098];

    for (size_t index = 0; index < 4098; ++index) {
        dataA[index] = 0xc0;
    }

    for (size_t index = 0; index < 800; ++index) {
        dataB[index] = 0xde;
    }

    page.write(dataA, 4098);

    EXPECT_EQ(page.pageSize(), 2*RMMEM_PAGE_SIZE);
    EXPECT_EQ(page.offset(), 4098);
    EXPECT_EQ(page.size(), 2*RMMEM_PAGE_SIZE - 4098);

    page.write(dataB, 800);

    EXPECT_EQ(page.pageSize(), 2*RMMEM_PAGE_SIZE);
    EXPECT_EQ(page.offset(), 4098+800);
    EXPECT_EQ(page.size(), 2*RMMEM_PAGE_SIZE - ( 4098 + 800));


    uint8 *buffer =(uint8 *)page.buffer();

    for (size_t index = 0; index < 4098; ++index) {
        //dataA[index] = 0xc0;
        EXPECT_EQ(buffer[index],0xc0);
    }

    for (size_t index = 4098; index < 4098+800; ++index) {
        //dataB[index] = 0xde;
        EXPECT_EQ(buffer[index],0xde);
    }

    page.recycle();

    EXPECT_EQ(page.pageSize(), 2*RMMEM_PAGE_SIZE);
    EXPECT_EQ(page.offset(), 0);
    EXPECT_EQ(page.size(), 2*RMMEM_PAGE_SIZE);


    for (size_t index = 0; index < 4098; ++index) {
        dataA[index] = 0xee;
    }

    for (size_t index = 0; index < 800; ++index) {
        dataB[index] = 0xfc;
    }

    page.write(dataB, 800);

    EXPECT_EQ(page.pageSize(), 2*RMMEM_PAGE_SIZE);
    EXPECT_EQ(page.offset(), 800);
    EXPECT_EQ(page.size(), 2*RMMEM_PAGE_SIZE - 800);

    page.write(dataA, 4098);

    EXPECT_EQ(page.pageSize(), 2*RMMEM_PAGE_SIZE);
    EXPECT_EQ(page.offset(), 800+4098);
    EXPECT_EQ(page.size(), 2*RMMEM_PAGE_SIZE - (800 + 4098));


    buffer =(uint8 *)page.buffer();

    for (size_t index = 0; index < 800; ++index) {
        EXPECT_EQ(buffer[index],0xfc);
    }

    for (size_t index = 800; index < (800+4098); ++index) {
        EXPECT_EQ(buffer[index],0xee);
    }

    page.recycle();

    EXPECT_EQ(page.pageSize(), 2*RMMEM_PAGE_SIZE);
    EXPECT_EQ(page.offset(), 0);
    EXPECT_EQ(page.size(), 2*RMMEM_PAGE_SIZE);
}