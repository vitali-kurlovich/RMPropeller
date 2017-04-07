//
// Created by Vitali Kurlovich on 8/20/16.
//

#ifndef RMPROPELLER_RMVIEWPORT_HPP
#define RMPROPELLER_RMVIEWPORT_HPP

#include "../graphics_common.hpp"

namespace rmengine {

    namespace graphics {

        class RMViewport {

        private:
            vec2 _size;
            vec2 _origin;
            rgbaf _clearColor;

            union {
                struct {
                    bool _needClearColor:1;
                    bool _needClearDepth:1;
                    bool _needClearStencil:1;
                };

                uint8 _clearFlags{0};
            };

        public:

            RMViewport() = default;
            RMViewport(const RMViewport& viewport) = default;


            RMViewport(const vec2& size)
            : _size(size)
            {}

            RMViewport(const vec2& size, const vec2& origin)
                    :_origin(origin), _size(size)
            {}

            constexpr vec2 getSize() const noexcept {
                return _size;
            }

            void setSize(const vec2& size) noexcept {
                _size = size;
            }

            constexpr vec2 getOrigin() const noexcept {
                return _origin;
            }

            void setOrigin(const vec2& origin) noexcept {
                 _origin = origin;
            }


            constexpr rgbaf getClearColor() const noexcept {
                return _clearColor;
            }

            void setClearColor(const rgbaf& clearColor) noexcept {
                _clearColor = clearColor;
            }


            void setNeedClearColor(const bool flag = true) noexcept {
                _needClearColor = flag;
            }

            constexpr bool isNeedClearColor() const noexcept {
                return _needClearColor;
            }

            void setNeedClearDepth(const bool flag = true) noexcept {
                _needClearDepth = flag;
            }

            constexpr bool isNeedClearDepth() const noexcept {
                return _needClearDepth;
            }

            void setNeedClearStencil(const bool flag = true) noexcept {
                _needClearStencil = flag;
            }

            constexpr bool isNeedClearStencil() const noexcept {
                return _needClearStencil;
            }

        public:
            virtual void update() const noexcept = 0;

        };

    }
}

#endif //RMPROPELLER_RMVIEWPORT_HPP
