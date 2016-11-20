//
// Created by Vitali Kurlovich on 11/13/16.
//

#ifndef RMPROPELLER_RMRESOURCEHEADER_HPP
#define RMPROPELLER_RMRESOURCEHEADER_HPP

#include "../../common/common.hpp"

#include "sha1/RMSHA1.hpp"

#include "mime/RMMime.hpp"

namespace rmengine {

    namespace resource {

        struct RMResourceHeader {
            const hash::RMSHA1 sha1;
            const mime::RMMime mime;
            const uint32 size{0};

            RMResourceHeader(const hash::RMSHA1 &s, mime::RMMime &mimetype, uint32 size)
                    :  sha1(s), mime(mimetype), size(size) {
            }
        };

        constexpr
        bool operator == (const RMResourceHeader &a, const RMResourceHeader &b) {
            return &a == &b || (a.sha1 == b.sha1 && a.mime == b.mime && a.size == b.size);
        }

        constexpr
        bool operator != (const RMResourceHeader &a, const RMResourceHeader &b) {
            return !(a == b) ;
        }

    }
}

#endif //RMPROPELLER_RMRESOURCEHEADER_HPP
