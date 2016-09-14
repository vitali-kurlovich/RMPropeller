//
// Created by Vitali Kurlovich on 9/12/16.
//

#ifndef RMPROPELLER_RMINDEXBUFFER_HPP
#define RMPROPELLER_RMINDEXBUFFER_HPP


#include "../../geometry_common.hpp"


namespace rmengine {

    namespace graphics {

        class  RMIndexBuffer : public RMObject {
            RMIntegerType _type{RMIntegerType_U8};
            uint32 _count{0};
            size_t _size{0};
            void* _indexData{nullptr};

        public:

            constexpr
            void* data() const noexcept {
                return _indexData;
            }

            constexpr
            uint32 count() const noexcept {
                return _count;
            }

            constexpr
            size_t size() const noexcept {
                return _size;
            }

            constexpr
            RMIntegerType type() const noexcept {
                return _type;
            }
        };

    }
}


#endif //RMPROPELLER_RMINDEXBUFFER_HPP
