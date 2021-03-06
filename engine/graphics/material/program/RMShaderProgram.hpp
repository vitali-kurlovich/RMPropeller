//
// Created by Vitali Kurlovich on 8/23/16.
//

#ifndef RMPROPELLER_RMPROGRAM_HPP
#define RMPROPELLER_RMPROGRAM_HPP

#include <vector>

#include "graphics/material/material_common.hpp"

#include "RMShader.hpp"

namespace rmengine {

    namespace graphics {


        class RMShaderProgram : public RMObject {

        protected:
            std::vector<RMShader*> _shaders;

            void clearShaders() {
                for (RMShader* shader : _shaders) {
                    rmRelease(shader);
                }
                _shaders.clear();
            }

        public:


            RMShaderProgram(std::initializer_list<RMShader*> shaders)
            : _shaders(shaders)
            {
                for (RMShader* shader : _shaders) {
                    rmRetain(shader);
                }
            }

            virtual ~RMShaderProgram() {
                for (RMShader* shader : _shaders) {
                    rmRelease(shader);
                }
            }

            virtual bool compile() noexcept = 0;


            constexpr uint32 shaderCount() const noexcept  {
                return _shaders.size();
            }

            constexpr RMShader* shaderAtIndex(uint32 index) const {
                return _shaders[index];
            }

            virtual void use() const noexcept = 0;


            virtual void setUniform( const char *name, float x, float y, float z, float w) noexcept = 0;
            virtual void setUniform( const char *name, float x, float y, float z) noexcept = 0;
            virtual void setUniform( const char *name, float x, float y) noexcept = 0;
            virtual void setUniform( const char *name, float val) noexcept = 0;

            virtual void setUniform( const char *name, const vec2 &vec) noexcept = 0;
            virtual void setUniform( const char *name, const vec3 &vec) noexcept = 0;
            virtual void setUniform( const char *name, const vec4 &vec) noexcept = 0;

            virtual void setUniform( const char *name, const mat2x2 &mat) noexcept = 0;
            virtual void setUniform( const char *name, const mat3x3 &mat) noexcept = 0;
            virtual void setUniform( const char *name, const mat4x4 &mat) noexcept = 0;

            virtual void setUniform( const char *name, int32 val ) noexcept = 0;
            virtual void setUniform( const char *name, uint32 val ) noexcept = 0;
            virtual void setUniform( const char *name, bool val ) noexcept = 0;

            virtual void setUniform( const char *name, const amat3x3 &mat) noexcept {
                mat3x3 m(
                        mat.m00, mat.m01, 0,
                        mat.m10, mat.m11, 0,
                        mat.m20, mat.m21, 1
                );

                setUniform(name, m);
            }

            virtual void setUniform( const char *name, const amat4x4 &mat) noexcept {
                mat4x4 m(
                        mat.m00, mat.m01, mat.m02, 0,
                        mat.m10, mat.m11, mat.m12, 0,
                        mat.m20, mat.m21, mat.m22, 0,
                        mat.m30, mat.m31, mat.m32, 1
                );

                setUniform(name, m);
            }

        };
    }
}

#endif //RMPROPELLER_RMPROGRAM_HPP
