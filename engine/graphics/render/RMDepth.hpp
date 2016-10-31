//
// Created by Vitali Kurlovich on 4/24/16.
//

#ifndef RMPROPELLER_RMDEPTH_HPP
#define RMPROPELLER_RMDEPTH_HPP

#include "graphics/material/material_common.hpp"

namespace rmengine {
    namespace graphics {



        struct RMDepth final {

        public:
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

        protected:
            RMDepthFunc _depthFunc;
            bool _write;

        public:
            constexpr
            RMDepth(const bool write = true, const RMDepthFunc depthFunc = RMDepthFunc_Less)
                    : _write(write), _depthFunc(depthFunc) {
            }

            constexpr
            bool requireDepthTestEnable() const {
                return _depthFunc != RMDepthFunc_Always;
            }

            constexpr
            bool isRequireWrite() const {
                return _write;
            }

            constexpr
            RMDepthFunc getDepthFunc() const {
                return _depthFunc;
            }

        };

        constexpr
        bool operator == (const RMDepth &a, const RMDepth &b) {
            return a.getDepthFunc() == b.getDepthFunc() && a.isRequireWrite() == b.isRequireWrite();
        }

        constexpr
        bool operator != (const RMDepth &a, const RMDepth &b) {
            return !(a == b);
        }
    }
}

#endif //RMPROPELLER_RMDEPTH_HPP
