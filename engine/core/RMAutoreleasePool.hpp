//
// Created by Vitali Kurlovich on 9/12/16.
//

#ifndef RMPROPELLER_RMAUTORELEASEPOOL_HPP
#define RMPROPELLER_RMAUTORELEASEPOOL_HPP


#include <forward_list>

#include "RMObject.hpp"

namespace rmengine {

    class RMAutoreleasePool {
        std::forward_list<RMObject**> object_ref_list;
        std::forward_list<RMObject*> objectlist;

    public:

        inline
        void push(RMObject** object) noexcept {
            object_ref_list.push_front(object);
        }

        inline
        void push(RMObject* object) noexcept {
            objectlist.push_front(object);
        }

        void drain() noexcept {
            while (!object_ref_list.empty())
            {
                RMObject** obj = *object_ref_list.begin();
                object_ref_list.pop_front();
                rmRelease(obj);
            }

            while (!objectlist.empty())
            {
                RMObject* obj = *objectlist.begin();
                objectlist.pop_front();
                rmRelease(obj);
            }
        }

        static  RMAutoreleasePool& sharedInstance() noexcept {
            static RMAutoreleasePool pool;
            return pool;
        }
    };


    inline
    void rmAutoRelease(RMObject **object, RMAutoreleasePool &pool) noexcept {
        pool.push(object);
    }

    inline
    void rmAutoRelease(RMObject **object) noexcept {
        rmAutoRelease(object, RMAutoreleasePool::sharedInstance());
    }


}


#endif //RMPROPELLER_RMAUTORELEASEPOOL_HPP
