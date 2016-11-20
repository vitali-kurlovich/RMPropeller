//
// Created by Vitali Kurlovich on 8/23/16.
//

#ifndef RMPROPELLER_RMRESOURCE_HPP
#define RMPROPELLER_RMRESOURCE_HPP

#include "../../common/common.hpp"
#include "RMResourceHeader.hpp"

namespace rmengine {

    namespace resource {

        class RMResource : public RMObject {

        public:

            const RMResourceHeader header;

            constexpr
            RMResource(const RMResourceHeader &header ) noexcept
                    : header(header) {
            }

            constexpr
            size_t size() const noexcept {
                return header.size;
            }

            virtual void *data() const noexcept = 0;
        };

    }




}

#endif //RMPROPELLER_RMRESOURCE_HPP
