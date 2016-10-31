//
// Created by Vitali Kurlovich on 4/23/16.
//

#ifndef RMPROPELLER_RMBLEND_HPP
#define RMPROPELLER_RMBLEND_HPP

#include "graphics/material/material_common.hpp"

namespace rmengine {

    namespace graphics {




        typedef enum : uint8 {
            RMBlendEquation_Add = 0,
            RMBlendEquation_Subtract = 1,
            RMBlendEquation_ReverseSubtract = 2,
            RMBlendEquation_Min = 3,
            RMBlendEquation_Max = 4
        } RMBlendEquation;

        struct RMBlend final {

            typedef enum : uint8 {
                RMBlendFunc_Zero = 0,
                RMBlendFunc_One = 1,
                RMBlendFunc_SrcColor = 2,
                RMBlendFunc_OneMinusSrcColor = 3,
                RMBlendFunc_DstColor = 4,
                RMBlendFunc_OneMinusDstColor = 5,
                RMBlendFunc_SrcAlpha = 6,
                RMBlendFunc_OneMinusSrcAlpha = 7,
                RMBlendFunc_DstAlpha = 8,
                RMBlendFunc_OneMinusDstAlpha = 9,
                RMBlendFunc_ConstantColor = 10,
                RMBlendFunc_OneMinusConstantColor = 11,
                RMBlendFunc_ConstantAlpha = 12,
                RMBlendFunc_OneMinusConstantAlpha = 13,
                RMBlendFunc_SrcAlphaSaturate = 14,
                RMBlendFunc_Src1Color = 15,
                RMBlendFunc_OneMinusSrc1Color = 16,
                RMBlendFunc_Src1Alpha = 17,
                RMBlendFunc_OneMinusSrc1Alpha = 18
            } RMBlendFunc;


            union {
                struct {
                    RMBlendFunc src;
                    RMBlendFunc dst;

                    RMBlendFunc alphaSrc;
                    RMBlendFunc alphaDst;
                };

                struct {
                    uint16 colorBlendFunc;
                    uint16 alphaBlendFunc;
                };

                uint32 blendFunc;
            };

        //    RMBlendEquation equation;

        public:
            constexpr
            RMBlend(const RMBlendFunc src ,
                    const RMBlendFunc dst,
                    const RMBlendFunc alphaSrc,
                    const RMBlendFunc alphaDst)
                    //const RMBlendEquation equation = RMBlendEquation_Add)
                    : src(src), dst(dst), alphaSrc(alphaSrc), alphaDst(alphaDst) {//, equation(equation) {
            }

            constexpr
            RMBlend(const RMBlendFunc src = RMBlendFunc_One,
                    const RMBlendFunc dst = RMBlendFunc_Zero)
            :  src(src), dst(dst), alphaSrc(src), alphaDst(dst) {

            }

            constexpr
            RMBlend(const RMBlend &other)
                    : blendFunc(other.blendFunc) {//, equation(other.equation) {
            }

            constexpr
            bool isRequireBlendEnable() const {
                return colorBlendFunc != alphaBlendFunc || src != RMBlendFunc_One || dst != RMBlendFunc_Zero;
            }

        };

        constexpr
        bool operator == (const RMBlend &a, const RMBlend &b) {
            return a.blendFunc == b.blendFunc;//&& a.equation == b.equation;
        }

        constexpr
        bool operator != (const RMBlend &a, const RMBlend &b) {
            return !(a == b);
        }
    }
}
#endif //RMPROPELLER_RMBLEND_HPP
