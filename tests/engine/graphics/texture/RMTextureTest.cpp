//
// Created by Vitali Kurlovich on 5/3/16.
//

#include "gtest/gtest.h"

#include <graphics/texture/RMTexture.hpp>


using namespace rmengine;
using  namespace graphics;

TEST(RMTextureTest, constructor) {

    RMTexture a(RMTextureType_2D,
                RMTextureWrapping_ClampToBorder,
                RMTextureFiltering_LinearMipmapLinear,
                RMTextureFiltering_LinearMipmapLinear);

    EXPECT_EQ(a.getType(), RMTextureType_2D );

    EXPECT_EQ(a.getWrappingS(), RMTextureWrapping_ClampToBorder );
    EXPECT_EQ(a.getWrappingT(), RMTextureWrapping_ClampToBorder );
    EXPECT_EQ(a.getWrappingR(), RMTextureWrapping_ClampToBorder );

    EXPECT_EQ(a.getMinFiltering(), RMTextureFiltering_LinearMipmapLinear);
    EXPECT_EQ(a.getMagFiltering(), RMTextureFiltering_LinearMipmapLinear);


    RMTexture b(RMTextureType_2D,
                RMTextureWrapping_ClampToBorder,
                RMTextureWrapping_ClampToBorder,
                RMTextureWrapping_ClampToBorder,
                RMTextureFiltering_LinearMipmapLinear,
                RMTextureFiltering_LinearMipmapLinear);


    EXPECT_EQ(b.getType(), RMTextureType_2D );

    EXPECT_EQ(b.getWrappingS(), RMTextureWrapping_ClampToBorder );
    EXPECT_EQ(b.getWrappingT(), RMTextureWrapping_ClampToBorder );
    EXPECT_EQ(b.getWrappingR(), RMTextureWrapping_ClampToBorder );

    EXPECT_EQ(b.getMinFiltering(), RMTextureFiltering_LinearMipmapLinear);
    EXPECT_EQ(b.getMagFiltering(), RMTextureFiltering_LinearMipmapLinear);


    EXPECT_EQ(a, b);

    RMTexture c(RMTextureType_3D, RMTextureWrapping_ClampToBorder,
                RMTextureWrapping_ClampToBorder,
                RMTextureWrapping_ClampToBorder,
                RMTextureFiltering_LinearMipmapLinear,
                RMTextureFiltering_LinearMipmapLinear);

    EXPECT_NE(a,c);

    a = RMTexture(RMTextureType_3D, RMTextureWrapping_ClampToBorder,
                  RMTextureWrapping_ClampToEdge,
                  RMTextureFiltering_NearestMipmapLinear,
                    RMTextureFiltering_LinearMipmapLinear);


    b = RMTexture(RMTextureType_3D,
                  RMTextureWrapping_ClampToBorder,
                  RMTextureWrapping_ClampToEdge,
                  RMTextureWrapping_ClampToEdge,
                  RMTextureFiltering_NearestMipmapLinear,
                  RMTextureFiltering_LinearMipmapLinear);

    EXPECT_EQ(a,b);

    EXPECT_NE(a,c);
    c = b;

    EXPECT_EQ(b,c);


}