//
// Created by Vitali Kurlovich on 9/12/16.
//


#include "gtest/gtest.h"

#include <core/RMObject.hpp>
#include <core/RMAutoreleasePool.hpp>


using namespace rmengine;


TEST(RMObject, retain) {


    RMObject* object = new RMObject();

    EXPECT_EQ(rmRetainCount(object), 1);

    rmRetain(&object);
    EXPECT_EQ(rmRetainCount(object), 2);

    rmRetain(&object);
    EXPECT_EQ(rmRetainCount(object), 3);

    rmRelease(&object);
    EXPECT_EQ(rmRetainCount(object), 2);

    rmRelease(&object);
    EXPECT_EQ(rmRetainCount(object), 1);

    rmRelease(&object);
    EXPECT_EQ(object, nullptr);

}

TEST(AutoreleasePool, retain) {
    RMObject* objectA = new RMObject();
    RMObject* objectB = new RMObject();

    rmRetain(&objectA);

    EXPECT_EQ(rmRetainCount(objectA), 2);
    EXPECT_EQ(rmRetainCount(objectB), 1);

    RMAutoreleasePool pool;

    rmAutoRelease(&objectA, pool);
    rmAutoRelease(&objectB, pool);

    EXPECT_EQ(rmRetainCount(objectA), 2);
    EXPECT_EQ(rmRetainCount(objectB), 1);

    pool.drain();

    EXPECT_EQ(rmRetainCount(objectA), 1);
    EXPECT_EQ(objectB, nullptr);
}