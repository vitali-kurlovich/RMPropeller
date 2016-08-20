//
// Created by Vitali Kurlovich on 8/8/16.
//

#ifndef RMVECTORMATH_TTRANSFORM3DTEST_HPP
#define RMVECTORMATH_TTRANSFORM3DTEST_HPP

#include <transform/TTransform3d.hpp>

using namespace rmengine;

class TestTTransform3d : public TTransform3d<float> {
public:

    constexpr bool test_isGlobalTransformNeedsUpdate() const noexcept {
        return isGlobalTransformNeedsUpdate();
    }

    constexpr bool test_isTransformNeedsUpdate() const noexcept { return isTransformNeedsUpdate(); }
    constexpr bool test_isRotationNeedsUpdate() const noexcept { return isRotationNeedsUpdate(); }
    constexpr bool test_isPositionNeedsUpdate() const noexcept { return isPositionNeedsUpdate(); }
    constexpr bool test_isScaleNeedsUpdate() const noexcept { return isScaleNeedsUpdate(); }

};

#endif //RMVECTORMATH_TTRANSFORM3DTEST_HPP
