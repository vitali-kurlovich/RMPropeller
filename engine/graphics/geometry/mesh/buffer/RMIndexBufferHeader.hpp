//
// Created by Vitali Kurlovich on 11/1/16.
//

#ifndef RMPROPELLER_RMINDEXBUFFERHEADER_HPP
#define RMPROPELLER_RMINDEXBUFFERHEADER_HPP

#include "../../geometry_common.hpp"
#include "RMBuffer.hpp"

namespace rmengine {

    namespace graphics {

        class RMIndexBufferHeader {
        public:
            RMRange<uint32>range{0, uint32_max};
            RMIntegerType type{RMIntegerType_U8};

            RMIndexBufferHeader(){}

            RMIndexBufferHeader(const RMRange<uint32> &range, RMIntegerType type)
                    : range(range), type(type) {
            }

            RMIndexBufferHeader(RMIntegerType type)
                    : type(type), range(0, maxValueForType(type)) {


            }
        };
    }
}


#endif //RMPROPELLER_RMINDEXBUFFERHEADER_HPP
