//
// Created by Vitali Kurlovich on 5/4/16.
//

#ifndef RMPROPELLER_RMTRANSFORM_HPP
#define RMPROPELLER_RMTRANSFORM_HPP


#include "common/common.hpp"


namespace rmengine {

    namespace graphics {

        class RMTransform3d {
        protected:
            RMTransform3d* _parent;

            vec3 _translate;
            quaternion _rotation;
            vec3 _scale;

            affine_mat4x4 _localTransformMatrix;

            union {
                struct {
                    uint8 _localTranslateChanged:1;
                    uint8 _localRotationChanged:1;
                    uint8 _localScaleChanged:1;
                };
                uint8 _localTransformChanged:3;
            };

        public:

            const affine_mat4x4& getLocalTransformMatrix() const {

                if (_localTransformChanged == 0) {
                    return _localTransformMatrix;
                } else {
                    //_localTransformChanged = 0;
                }

                return _localTransformMatrix;
            }


            const affine_mat4x4& getWorldTransformMatrix() const {
                if (_parent == nullptr) {
                    return getLocalTransformMatrix();
                }

                return _parent->getWorldTransformMatrix()*getLocalTransformMatrix();
            }

            virtual void setParent(const RMTransform3d* parent = nullptr) {
                if (_parent != parent) {

                }
            }

            virtual void setLocalTranslate(const vec3 &translate) {
                if (_translate != translate) {
                    _translate = translate;
                    _translateChanged = true;
                }
            }

            virtual void setWorldTranslate(vec3 translate) {
                if (_parent == nullptr) {
                    setLocalTranslate(translate);
                } else {

                }
            }

        };

    }
}


#endif //RMPROPELLER_RMTRANSFORM_HPP
