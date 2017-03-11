//
// Created by Vitali Kurlovich on 11/21/16.
//

#include "gtest/gtest.h"

#include <core/serialize/RMCoder.hpp>
#include <core/serialize/RMDecoder.hpp>

#include <core/buffer/RMMemmoryBuffer.hpp>

using namespace rmengine;
using namespace rmengine::serialize;
using namespace rmengine::buffer;

TEST(RMDecoder, constructor) {
    RMMemmoryBuffer* buffer = new RMMemmoryBuffer();
    RMCoder coder(buffer);

    coder.encode((uint8)0xfc);
    coder.encode((int16)0x4567);
    coder.encode((uint32)0x7654);
    coder.encode((int64)0xde1034);

    coder.encode((int8)0x2c);
    coder.encode((uint16)0x2567);
    coder.encode((int32)0x2654);
    coder.encode((uint64)0x2e1034);

    coder.encode("string");

    coder.encode((uint64)0xffcceedd);

    uint8 array[] = {0x3a, 0x3b, 0x3c, 0xfa, 0xfb, 0xfc};

    coder.encode(array, 6);

    RMDecoder decoder(buffer);

    buffer->seek(0);

    EXPECT_EQ(decoder.decode_uint8(),0xfc);
    EXPECT_EQ(decoder.decode_int16(),0x4567);
    EXPECT_EQ(decoder.decode_uint32(),0x7654);
    EXPECT_EQ(decoder.decode_int64(),0xde1034);

    EXPECT_EQ(decoder.decode_int8(),0x2c);
    EXPECT_EQ(decoder.decode_uint16(),0x2567);
    EXPECT_EQ(decoder.decode_int32(),0x2654);
    EXPECT_EQ(decoder.decode_uint64(),0x2e1034);

    EXPECT_EQ(decoder.decode_string(), "string");
    EXPECT_EQ(decoder.decode_uint64(), 0xffcceedd);

    std::vector<uint8> vector;
    vector.reserve(6);
    vector.assign(array, array+6);
    EXPECT_EQ(decoder.decode_uint8_array(), vector);

}