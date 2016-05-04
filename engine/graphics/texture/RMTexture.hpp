//
// Created by Vitali Kurlovich on 5/3/16.
//

#ifndef RMPROPELLER_RMTEXTURE_HPP
#define RMPROPELLER_RMTEXTURE_HPP

#include "common/common.hpp"


namespace rmengine {

    namespace graphics {

        typedef enum : uint8 {
            RMTextureType_1D      = 0,
            RMTextureType_2D      = 1,
            RMTextureType_3D      = 2,
            RMTextureType_Buffer  = 3,
            RMTextureType_CubeMap = 4,
        } RMTextureType;

        typedef  enum : uint8 {
            RMTextureWrapping_Repeat         = 0,
            RMTextureWrapping_MirroredRepeat = 1,
            RMTextureWrapping_ClampToEdge    = 2,
            RMTextureWrapping_ClampToBorder  = 3
        } RMTextureWrapping;

        typedef  enum : uint8 {
            RMTextureFiltering_Nearest = 0,
            RMTextureFiltering_Linear = 1,
            RMTextureFiltering_NearestMipmapNearest = 2,
            RMTextureFiltering_LinearMipmapNearest = 3,
            RMTextureFiltering_NearestMipmapLinear = 4,
            RMTextureFiltering_LinearMipmapLinear = 5
        } RMTextureFiltering;


        class RMTexture {

        protected:
            union {
                struct {
                    RMTextureType _type:4;

                    RMTextureWrapping _wrapping_s:2;
                    RMTextureWrapping _wrapping_t:2;
                    RMTextureWrapping _wrapping_r:2;

                    RMTextureFiltering _minFiltering:3;
                    RMTextureFiltering _magFiltering:3;
                };
                uint16 _textureFlags;
            };

        public:
            RMTexture(const RMTexture &other)
                    : _textureFlags(other._textureFlags) {
            }

            RMTexture(const RMTextureType type,
                      const RMTextureWrapping wrapping_s,
                      const RMTextureWrapping wrapping_t,
                      const RMTextureWrapping wrapping_r,
                      const RMTextureFiltering minFiltering = RMTextureFiltering_Nearest,
                      const RMTextureFiltering magFiltering = RMTextureFiltering_Linear)
                    : _type(type),
                      _wrapping_s(wrapping_s), _wrapping_t(wrapping_t), _wrapping_r(wrapping_r),
                      _minFiltering(minFiltering), _magFiltering(magFiltering) {
            }


            RMTexture(const RMTextureType type,
                      const RMTextureWrapping wrapping,
                      const RMTextureFiltering minFiltering = RMTextureFiltering_Nearest,
                      const RMTextureFiltering magFiltering = RMTextureFiltering_Linear)
                    : _type(type),
                      _wrapping_s(wrapping), _wrapping_t(wrapping), _wrapping_r(wrapping),
                      _minFiltering(minFiltering), _magFiltering(magFiltering) {
            }

            RMTexture(const RMTextureType type,
                      const RMTextureWrapping wrapping_s,
                      const RMTextureWrapping wrapping_t,
                      const RMTextureFiltering minFiltering = RMTextureFiltering_Nearest,
                      const RMTextureFiltering magFiltering = RMTextureFiltering_Linear)
                    : _type(type),
                      _wrapping_s(wrapping_s), _wrapping_t(wrapping_t), _wrapping_r(wrapping_t),
                      _minFiltering(minFiltering), _magFiltering(magFiltering) {
            }

            const RMTextureType getType() const {
                return _type;
            }

            const RMTextureWrapping getWrappingS() const {
                return _wrapping_s;
            }

            const RMTextureWrapping getWrappingT() const {
                return _wrapping_t;
            }

            const RMTextureWrapping getWrappingR() const {
                return _wrapping_r;
            }

            const RMTextureFiltering getMinFiltering() const {
                return _minFiltering;
            }

            const RMTextureFiltering getMagFiltering() const {
                return _magFiltering;
            }

            const bool operator == (const RMTexture &a ) const {
                return  a._textureFlags == _textureFlags;
            }

            bool operator != (const RMTexture &a ) const {
                return !(a == *this);
            }
        };
    }
}

#endif //RMPROPELLER_RMTEXTURE_HPP
