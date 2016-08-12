//
// Created by Vitali Kurlovich on 8/4/16.
//

#ifndef RMVECTORMATH_TTRANSFORM3D_HPP
#define RMVECTORMATH_TTRANSFORM3D_HPP

#include "TTransform.hpp"

#include "../matrix/TAffineMatrix4x4.hpp"
#include "../vector/TAffineVector4.hpp"
#include "../vector/TVector3.hpp"
#include "../complex/TQuaternion.hpp"

#include "../utils/TQuaternionUtils.hpp"


// TRS transformation

template<typename T>
class TTransform3d : public TTransform {

private:
    rmmath::complex::TQuaternion<T> _localRotation{rmmath::complex::TQuaternion<T>::identity()};
    rmmath::vector::TVector3<T> _localPosition{rmmath::vector::TVector3<T>::zero()};
    rmmath::vector::TVector3<T> _localScale{1,1,1};

    rmmath::matrix::TAffineMatrix4x4<T> _localTransform{rmmath::matrix::TAffineMatrix4x4<T>::identity()};
    rmmath::matrix::TAffineMatrix4x4<T> _globalTransform{rmmath::matrix::TAffineMatrix4x4<T>::identity()};



protected:
    TTransform3d<T>* _parentTransform3d;

    constexpr TTransform3d<T>* getParentTransform3d () const noexcept {
        return _parentTransform3d;
    }

    void setParentTransform3d(const TTransform3d<T>* parent) {
        _parentTransform3d = parent;
        setParent(parent);
    }

public:

    void setPosition(const rmmath::vector::TVector3<T> &position) noexcept {
        _localPosition = position;
        setPositionNeedsUpdate();
        setGlobalTransformNeedsUpdate();
    }

    constexpr rmmath::vector::TVector3<T> getPosition() const noexcept {
        return _localPosition;
    }

    void setRotation(const rmmath::complex::TQuaternion<T> &rotation) noexcept {
        _localRotation = rotation;
        setRotationNeedsUpdate();
        setGlobalTransformNeedsUpdate();
    }

    constexpr rmmath::complex::TQuaternion<T> getRotation() const noexcept {
        return _localRotation;
    }

    void setScale(const rmmath::vector::TVector3<T> &scale) noexcept {
        _localScale = scale;
        setScaleNeedsUpdate();
        setGlobalTransformNeedsUpdate();
    }

    constexpr rmmath::vector::TVector3<T> getScale() const noexcept {
        return _localScale;
    }

    void setTransform(const rmmath::vector::TVector3<T> &position,
                      const rmmath::complex::TQuaternion<T> &rotation,
                      const rmmath::vector::TVector3<T> &scale) noexcept {

        _localPosition = position;
        setPositionNeedsUpdate();

        _localRotation = rotation;
        setRotationNeedsUpdate();

        _localScale = scale;
        setScaleNeedsUpdate();

        setGlobalTransformNeedsUpdate();
    }

    void setTransform(const rmmath::matrix::TAffineMatrix4x4<T> &transform ) {
        _localTransform = transform;
        rmmath::utils::convertTRSTransform(_localTransform, &_localPosition, &_localRotation, &_localScale);
        setTransformUpdated();
    }

    const rmmath::matrix::TAffineMatrix4x4<T> getTransform() noexcept {
        if (isTransformNeedsUpdate()) {
            _localTransform = rmmath::utils::affineTRSMatrix4x4<T>(_localPosition, _localRotation, _localScale);
            setTransformUpdated();
        }
        return _localTransform;
    }

    const rmmath::matrix::TAffineMatrix4x4<T> getGlobalTransform() {

        if (isGlobalTransformNeedsUpdate()) {
            if (hasParent()) {
                _globalTransform = getParentTransform3d()->getGlobalTransform()*getTransform();
            } else {
                _globalTransform = getTransform();
            }
            setGlobalTransformUpdated();
        }
        return _globalTransform;
    }
};

#endif //RMVECTORMATH_TTRANSFORM3D_HPP
