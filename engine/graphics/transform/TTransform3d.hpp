//
// Created by Vitali Kurlovich on 8/4/16.
//

#ifndef RMVECTORMATH_TTRANSFORM3D_HPP
#define RMVECTORMATH_TTRANSFORM3D_HPP


#include "common/common.hpp"

#include "TTransform.hpp"

#include "../../../libs/math/rmvmath/utils/TQuaternionUtils.hpp"


/*
#include "../matrix/TAffineMatrix4x4.hpp"
#include "../vector/TAffineVector4.hpp"
#include "../vector/TVector3.hpp"
#include "../complex/TQuaternion.hpp"

#include "../utils/TQuaternionUtils.hpp"
*/

// TRS transformation

namespace rmengine {

    namespace transform {

        class TTransform3d : public TTransform {

        private:
            quat _localRotation{quat::identity()};
            vec3 _localPosition{vec3::zero()};
            vec3 _localScale{1, 1, 1};

            amat4x4 _localTransform{amat4x4::identity()};
            amat4x4 _globalTransform{amat4x4::identity()};


        protected:
            TTransform3d* _parentTransform3d;

            constexpr TTransform3d *getParentTransform3d() const noexcept {
                return _parentTransform3d;
            }

            void setParentTransform3d(TTransform3d *parent) {
                _parentTransform3d = parent;
                setParent(parent);
            }

        public:

            void setPosition(const vec3 &position) noexcept {
                _localPosition = position;
                setPositionNeedsUpdate();
                setGlobalTransformNeedsUpdate();
            }

            constexpr vec3 getPosition() const noexcept {
                return _localPosition;
            }

            void setRotation(const quat &rotation) noexcept {
                _localRotation = rotation;
                setRotationNeedsUpdate();
                setGlobalTransformNeedsUpdate();
            }

            constexpr quat getRotation() const noexcept {
                return _localRotation;
            }

            void setScale(const vec3 &scale) noexcept {
                _localScale = scale;
                setScaleNeedsUpdate();
                setGlobalTransformNeedsUpdate();
            }

            constexpr vec3 getScale() const noexcept {
                return _localScale;
            }

            void setTransform(const vec3 &position,
                              const quat &rotation,
                              const vec3 &scale) noexcept {

                _localPosition = position;
                setPositionNeedsUpdate();

                _localRotation = rotation;
                setRotationNeedsUpdate();

                _localScale = scale;
                setScaleNeedsUpdate();

                setGlobalTransformNeedsUpdate();
            }

            void setTransform(const amat4x4 &transform) {
                _localTransform = transform;

                // !!!
                // rmmath::utils::convertTRSTransform(_localTransform, &_localPosition, &_localRotation, &_localScale);

                setTransformUpdated();
            }

            const amat4x4 &getTransform() noexcept {
                if (isTransformNeedsUpdate()) {
                    // !!!
                    _localTransform = rmmath::utils::affineTRSMatrix4x4(_localPosition, _localRotation, _localScale);
                    setTransformUpdated();
                }
                return _localTransform;
            }

            const amat4x4 getGlobalTransform() {

                if (isGlobalTransformNeedsUpdate()) {
                    if (hasParent()) {
                        _globalTransform = getParentTransform3d()->getGlobalTransform() * getTransform();
                    } else {
                        _globalTransform = getTransform();
                    }
                    setGlobalTransformUpdated();
                }
                return _globalTransform;
            }
        };

    }

}
#endif //RMVECTORMATH_TTRANSFORM3D_HPP
