//
// Created by Vitali Kurlovich on 4/23/16.
//

#ifndef RMPROPELLER_RMPASS_HPP
#define RMPROPELLER_RMPASS_HPP

#include "graphics/material/material_common.hpp"

#include "../../RMBlend.hpp"
#include "../../RMDepth.hpp"

#include "RMPassState.hpp"


namespace rmengine {

    namespace graphics {

        class RMPass {
        public:
            typedef enum : uint8 {
                RMCullFace_None = 0,
                RMCullFace_Back = 1,
                RMCullFace_Front = 2
            } RMCullFace;

            typedef enum : uint8 {
                RMDepthSort_None = 0,
                RMDepthSort_Forward = 1,
                RMDepthSort_Reverse = 2
            } RMDepthSort;

            const RMPassState state;
        protected:


            union {
                struct {
                    RMCullFace _cullFace:2;
                    RMDepthSort _depthSort:2;

                    bool _requireCullFaceEnable:1;
                    bool _requireBlendEnable:1;
                    bool _requireDepthTestEnable:1;
                    bool _requireDepthSort:1;
                };

                uint8 _requirements;
            };

        public:
            RMPass(const RMCullFace cullFace = RMCullFace_Back, const RMDepthSort depthSort = RMDepthSort_None)
                    : state{},
                      _cullFace(cullFace),
                       _requireDepthSort(depthSort != RMDepthSort_None),
                       _requireBlendEnable(false),
                       _requireDepthTestEnable(true),
                       _requireCullFaceEnable(cullFace != RMCullFace_None)
            {
            }

            RMPass(const RMDepth& depth, const RMBlend& blend,
                   const RMCullFace cullFace = RMCullFace_Back, const RMDepthSort depthSort = RMDepthSort_None)
                    :  state(depth, blend),
                       _cullFace(cullFace),
                       _requireDepthSort(depthSort != RMDepthSort_None),
                       _requireBlendEnable(blend.isRequireBlendEnable()),
                       _requireDepthTestEnable(true),
                       _requireCullFaceEnable(cullFace != RMCullFace_None)
            {
            }

        public:
            constexpr
            RMDepth getDepth() const {
                return state.depth;
            }

            constexpr
            RMBlend getBlend() const {
                return state.blend;
            }

            constexpr
            RMCullFace getCullFace() const {
                return _cullFace;
            }

            constexpr
            bool requireBlendEnable() const {
                return _requireBlendEnable;
            }

            constexpr
            bool requireDepthSort() const {
                return _requireDepthSort;
            }

            constexpr
            bool isRequireCullFaceEnable() const {
                return _requireCullFaceEnable;
            }

            constexpr
            bool operator == (const RMPass &pass ) const {
                return pass._requirements == _requirements && pass.state == state;
            }

            constexpr
            bool operator != (const RMPass &a ) const {
                return !(a == *this);
            }
        };

    }
}


#endif //RMPROPELLER_RMPASS_HPP
