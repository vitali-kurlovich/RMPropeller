//
// Created by Vitali Kurlovich on 4/23/16.
//

#ifndef RMPROPELLER_RMPASS_HPP
#define RMPROPELLER_RMPASS_HPP

#include "../../material_common.hpp"

#include "RMBlend.hpp"
#include "RMDepth.hpp"

#include "../shader/RMShader.hpp"


namespace rmengine {

    namespace graphics {

        typedef enum : uint8 {

            RMCullFace_None = 0,
            RMCullFace_Back = 1,
            RMCullFace_Front = 2,
            RMCullFace_Front_And_Back = 3,

        } RMCullFace;


        class RMPass {
        protected:
            RMBlend _blend;
            RMDepth _depth;
            RMShader* _shader;

            union {
                struct {
                    RMCullFace _cullFace:2;

                    bool _requireCullFaceEnable:1;
                    bool _requireBlendEnable:1;
                    bool _requireDepthTestEnable:1;
                    bool _requireDepthSort:1;
                };

                uint32 _requirements;
            };

        public:

            RMPass(RMShader* shader, const RMCullFace cullFace = RMCullFace_Back, const bool requireDepthSort = false)
                    :  _shader(shader),
                       _cullFace(cullFace),
                       _requireDepthSort(requireDepthSort),
                       _requireBlendEnable(false),
                       _requireDepthTestEnable(true),
                       _requireCullFaceEnable(cullFace != RMCullFace_None)
            {

            }


            RMPass(const RMDepth& depth, const RMBlend& blend, RMShader* shader, const RMCullFace cullFace = RMCullFace_Back, const bool requireDepthSort = false )
            : _depth(depth),
              _blend(blend),
              _shader(shader),
              _cullFace(cullFace),
              _requireDepthSort(requireDepthSort),
              _requireBlendEnable(blend.requireBlendEnable()),
              _requireDepthTestEnable(depth.requireDepthTestEnable()),
              _requireCullFaceEnable(cullFace != RMCullFace_None) {

            }

            RMPass(const RMPass& other)
                    : _depth(other._depth),
                      _blend(other._blend),
                      _shader(other._shader),
                      _requirements(other._requirements) { }


        public:
            const RMDepth& getDepth() const {
                return _depth;
            }

            const RMBlend& getBlend() const {
                return _blend;
            }

            const RMShader* getShader() const {
                return _shader;
            }

            const RMCullFace getCullFace() const {
                return _cullFace;
            }

            const bool requireBlendEnable() const {
                return _requireBlendEnable;
            }

            const bool requireDepthSort() const {
                return _requireDepthSort;
            }

            const bool requireCullFaceEnable() const {
                return _requireCullFaceEnable;
            }

            const bool operator == (const RMPass &a ) const {
                return a._requirements == _requirements && a._shader == _shader && a._depth == _depth && a._blend == _blend;
            }

            bool operator != (const RMPass &a ) const {
                return !(a == *this);
            }
        };

    }
}


#endif //RMPROPELLER_RMPASS_HPP
