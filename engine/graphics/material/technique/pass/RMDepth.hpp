//
// Created by Vitali Kurlovich on 4/24/16.
//

#ifndef RMPROPELLER_RMDEPTH_HPP
#define RMPROPELLER_RMDEPTH_HPP

#include "../../material_common.hpp"

namespace rmengine {
    namespace graphics {

        typedef enum : uint8 {

            RMDepthFunc_Never = 0,
            RMDepthFunc_Less = 1,
            RMDepthFunc_Equal = 2,
            RMDepthFunc_Lequal = 3,
            RMDepthFunc_Greater = 4,
            RMDepthFunc_Notequal = 5,
            RMDepthFunc_Gequal = 6,
            RMDepthFunc_Always = 7

        } RMDepthFunc;

        struct RMDepth final {

            RMDepthFunc depthFunc;
            bool write;

        public:
            RMDepth(const bool write = true, const RMDepthFunc depthFunc = RMDepthFunc_Less)
                    : write(write), depthFunc(depthFunc) {
            }

            RMDepth(const RMDepth &other)
                    : write(other.write), depthFunc(other.depthFunc) {
            }

            const bool requireDepthTestEnable() const {
                return depthFunc != RMDepthFunc_Always;
            }
        };

        inline bool operator == (const RMDepth &a, const RMDepth &b) {
            return a.depthFunc == b.depthFunc && a.write == b.write;
        }

        inline bool operator != (const RMDepth &a, const RMDepth &b) {
            return !(a == b);
        }
    }
}

#endif //RMPROPELLER_RMDEPTH_HPP
