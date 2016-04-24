//
// Created by Vitali Kurlovich on 4/24/16.
//

#ifndef RMPROPELLER_RMALPHA_HPP
#define RMPROPELLER_RMALPHA_HPP


#include "../material_common.hpp"

namespace rmengine {
    namespace graphics {

        typedef enum : rm_uint8 {
            RMAlphaFunc_Never = 0,
            RMAlphaFunc_Less = 1,
            RMAlphaFunc_Equal = 2,
            RMAlphaFunc_Lequal = 3,
            RMAlphaFunc_Greater = 4,
            RMAlphaFunc_Notequal = 5,
            RMAlphaFunc_Gequal = 6,
            RMAlphaFunc_Always = 7
        } RMAlphaFunc;


        struct RMAlpha {
            RMAlphaFunc alphaFunc;
            float value;
        public:
            RMAlpha(RMAlphaFunc alphaFunc, float value)
                    : alphaFunc(alphaFunc), value(value) {
            }

            RMAlpha(const RMAlpha &other)
                    : alphaFunc(other.alphaFunc), value(other.value) {
            }
        };

        inline bool operator==(const RMAlpha &a, const RMAlpha &b) {
            return a.alphaFunc == b.alphaFunc && a.value == b.value;
        }

        inline bool operator!=(const RMAlpha &a, const RMAlpha &b) {
            return !(a == b);
        }

    }
}
#endif //RMPROPELLER_RMALPHA_HPP
