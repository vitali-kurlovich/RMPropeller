//
// Created by Vitali Kurlovich on 8/4/16.
//

#ifndef RMVECTORMATH_TTRANSFORM_HPP
#define RMVECTORMATH_TTRANSFORM_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

class TTransform {

private:
    TTransform* _parent{nullptr};
    std::vector<TTransform*>  _childs;

private:
    union {
        struct {
            unsigned int rotationChanged:1;
            unsigned int positionChanged:1;
            unsigned int scaleChanged:1;
            unsigned int transformChanged:1;

            unsigned int rotated:1;
            unsigned int translated:1;
            unsigned int scaled:1;

            unsigned int globalTransformChanged:1;

        } _flags;

        unsigned int _allFlags{0};
    };

public:

    constexpr TTransform* getParent() const noexcept {
        return _parent;
    }

    constexpr bool hasParent() const noexcept {
        return _parent != nullptr;
    }

    inline const std::vector<TTransform*> getChilds() const noexcept {
        return _childs;
    }

protected:

    inline void setParent(TTransform* parent) noexcept {
        _parent = parent;
    }

    void notifyChildsAboutGlobalTransformNeedsUpdate() noexcept {
        for(TTransform* child : getChilds()) {
            child->setGlobalTransformNeedsUpdate();
        }
    }

    void setGlobalTransformNeedsUpdate() noexcept {
        if (!_flags.globalTransformChanged) {
            _flags.globalTransformChanged = true;
            notifyChildsAboutGlobalTransformNeedsUpdate();
        }
    }

    constexpr bool isGlobalTransformNeedsUpdate() const noexcept {
        return _flags.globalTransformChanged;
    }

    inline void setTransformNeedsUpdate() noexcept {
        _flags.transformChanged = true;
    }

    constexpr bool isTransformNeedsUpdate() const noexcept {
        return _flags.transformChanged;
    }

    inline void setRotationNeedsUpdate() noexcept {
        _flags.rotationChanged = true;
        setTransformNeedsUpdate();
    }

    inline void setRotationUpdated() noexcept {
        _flags.rotationChanged = false;
    }

    constexpr bool isRotationNeedsUpdate() const noexcept {
        return _flags.rotationChanged;
    }

    void setPositionNeedsUpdate() noexcept {
        _flags.positionChanged = true;
        setTransformNeedsUpdate();
    }

    inline void setPositionUpdated() noexcept {
        _flags.positionChanged = false;
    }

    constexpr bool isPositionNeedsUpdate() const noexcept {
        return _flags.positionChanged;
    }

    inline void setScaleNeedsUpdate() noexcept {
        _flags.scaleChanged = true;
        setTransformNeedsUpdate();
    }

    inline void setScaleUpdated() noexcept {
        _flags.scaleChanged = false;
    }

    constexpr bool isScaleNeedsUpdate() const noexcept {
        return _flags.scaleChanged;
    }

    inline void setTransformUpdated() noexcept {
        _flags.transformChanged = false;
        setRotationUpdated();
        setPositionUpdated();
        setScaleUpdated();
    }

    inline void setGlobalTransformUpdated() noexcept {
        _flags.globalTransformChanged = false;
    }
};

#endif //RMVECTORMATH_TTRANSFORM_HPP
