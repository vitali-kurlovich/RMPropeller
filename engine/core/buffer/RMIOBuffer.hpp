//
// Created by Vitali Kurlovich on 11/19/16.
//

#ifndef RMPROPELLER_RMWRITEBUFFER_HPP
#define RMPROPELLER_RMWRITEBUFFER_HPP

#include "../../common/common.hpp"


namespace rmengine {

    namespace buffer  {

        class RMIOBuffer : public RMObject {
        public:
            virtual size_t size() const noexcept = 0;
        };

        class RMIOWriteBuffer : public RMIOBuffer {
        public:
           virtual bool write(const void *buffer, size_t size) noexcept = 0;
        };

        class RMIOReadBuffer : public RMIOBuffer {
        public:
            virtual bool read(void* dst, size_t size) noexcept  = 0;
            virtual bool seek(size_t offset) noexcept  = 0;
            virtual size_t seek() noexcept  = 0;
        };
    }
}
#endif //RMPROPELLER_RMWRITEBUFFER_HPP
