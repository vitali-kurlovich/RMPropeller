//
// Created by Vitali Kurlovich on 11/21/16.
//

#include "gtest/gtest.h"

#include <core/serialize/RMCoder.hpp>
#include <core/buffer/RMMemmoryBuffer.hpp>

using namespace rmengine;
using namespace rmengine::serialize;
using namespace rmengine::buffer;

TEST(RMCoder, constructor) {

    RMMemmoryBuffer* buffer = new RMMemmoryBuffer();
    RMCoder coder(buffer);

    coder.encode((uint32)1);
    coder.encode((uint32)2);
    coder.encode((uint32)3);
    coder.encode((uint32)4);

    uint32 data[4];
    buffer->seek(0);
    buffer->read(data, sizeof(uint32)*4);

    EXPECT_EQ(data[0],1);
    EXPECT_EQ(data[1],2);
    EXPECT_EQ(data[2],3);
    EXPECT_EQ(data[3],4);
}