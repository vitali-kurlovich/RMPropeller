//
// Created by Vitali Kurlovich on 9/12/16.
//

#ifndef RMPROPELLER_RMAUTORELEASEPOOL_HPP
#define RMPROPELLER_RMAUTORELEASEPOOL_HPP

#include "../common/common.hpp"

#include <list>

#include "RMObject.hpp"

namespace rmengine {


    class RMAutoreleasePool {
        std::list<RMObject**> objectlist;

    public:
        void push(RMObject** object) {
            objectlist.push_back(object);
        }

        void drain() {
            while (!objectlist.empty())
            {
                RMObject** obj = objectlist.back();
                objectlist.pop_back();
                rmRelease(obj);
            }
        }

        static  RMAutoreleasePool& sharedInstance() noexcept {
            static RMAutoreleasePool pool;
            return pool;
        }
    };


    void rmAutoRelease(RMObject **object, RMAutoreleasePool &pool) {
        pool.push(object);
    }

    void rmAutoRelease(RMObject **object) {
        rmAutoRelease(object, RMAutoreleasePool::sharedInstance());
    }
}


#endif //RMPROPELLER_RMAUTORELEASEPOOL_HPP
