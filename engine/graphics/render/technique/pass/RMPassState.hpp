//
// Created by Vitali Kurlovich on 10/27/16.
//

#ifndef RMPROPELLER_RMPASSSTATE_HPP
#define RMPROPELLER_RMPASSSTATE_HPP

#include "graphics/material/material_common.hpp"

#include "../../RMBlend.hpp"
#include "../../RMDepth.hpp"


namespace rmengine {

    namespace graphics {

        class RMPassState {

        public:
            const RMBlend blend;
            const RMDepth depth;

            constexpr
            RMPassState(const RMDepth& d, const RMBlend& b) noexcept
                    : depth(d), blend(b)
                    {
                    }

            constexpr
            RMPassState() noexcept
                    : depth{}, blend{}
            {
            }

            constexpr
            bool operator == (const RMPassState &state ) const noexcept {
                return state.depth == depth && state.blend == blend;
            }

            constexpr
            bool operator != (const RMPassState &a ) const noexcept {
                return !(a == *this);
            }
        };
    }
}

#endif //RMPROPELLER_RMPASSSTATE_HPP
