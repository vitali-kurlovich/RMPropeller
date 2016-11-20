//
// Created by Vitali Kurlovich on 11/13/16.
//

#ifndef RMPROPELLER_RMSHA1_HPP
#define RMPROPELLER_RMSHA1_HPP

#include <common/common.hpp>
#include <sha1.h>

namespace rmengine {

    namespace hash {

        struct RMSHA1 {
            union {
                const uint8 sha1_20[20]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                const uint32 sha1_20_5[5];
                struct {
                    const uint64 sha1_16[2];
                    const uint32 sha1_4;
                };
            };

            constexpr
            RMSHA1() {}

            constexpr
            RMSHA1(const uint8 buffer[20]) noexcept
                    : sha1_20{
                    buffer[0], buffer[1], buffer[2], buffer[3], buffer[4],
                    buffer[5], buffer[6], buffer[7], buffer[8], buffer[9],
                    buffer[10], buffer[11], buffer[12], buffer[13], buffer[14],
                    buffer[15], buffer[16], buffer[17], buffer[18], buffer[19]} {
            }

            constexpr
            RMSHA1(const RMSHA1 &src) noexcept
                    : sha1_20{
                    src.sha1_20[0], src.sha1_20[1], src.sha1_20[2], src.sha1_20[3], src.sha1_20[4],
                    src.sha1_20[5], src.sha1_20[6], src.sha1_20[7], src.sha1_20[8], src.sha1_20[9],
                    src.sha1_20[10], src.sha1_20[11], src.sha1_20[12], src.sha1_20[13], src.sha1_20[14],
                    src.sha1_20[15], src.sha1_20[16], src.sha1_20[17], src.sha1_20[18], src.sha1_20[19]} {
            }

            static const RMSHA1& zero() noexcept {
                static RMSHA1 zero;
                return zero;
            }

            static RMSHA1 sha1(const void *data, size_t lenght) {
                blk_SHA_CTX ctx;
                blk_SHA1_Init(&ctx);
                blk_SHA1_Update(&ctx, data, lenght);
                uint8 hashout[20];
                blk_SHA1_Final(hashout, &ctx);
                return RMSHA1{hashout};
            }
        };

        constexpr
        bool operator==(const RMSHA1 &a, const RMSHA1 &b) noexcept {
            return &a == &b ||
                   (a.sha1_16[0] == b.sha1_16[0] && a.sha1_16[1] == b.sha1_16[1] && a.sha1_4 == b.sha1_4);
        }

        constexpr
        bool operator!=(const RMSHA1 &a, const RMSHA1 &b) noexcept {
            return !(a == b);
        }
    }
}


namespace std {
    template <>
    class hash<rmengine::hash::RMSHA1> {
    public:
        size_t operator()(const rmengine::hash::RMSHA1 &rmsha1) const {

            size_t result = (rmsha1.sha1_20_5[0]
                             ^rmsha1.sha1_20_5[1]
                             ^rmsha1.sha1_20_5[2]
                             ^rmsha1.sha1_20_5[3]
                             ^rmsha1.sha1_20_5[4]);
            return result;
        }
    };
}


#endif //RMPROPELLER_RMSHA1_HPP
