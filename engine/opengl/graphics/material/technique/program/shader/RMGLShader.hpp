//
// Created by Vitali Kurlovich on 8/24/16.
//

#ifndef RMPROPELLER_RMGLSHADER_HPP
#define RMPROPELLER_RMGLSHADER_HPP

#include "../../../../../opengl_common.hpp"

namespace rmengine {

    namespace graphics {

        typedef enum : uint8 {
            RMGLShaderTypeVertex,
            RMGLShaderTypeFragment,
#ifdef GL_GEOMETRY_SHADER
            RMGLShaderTypeGeometry,
#endif

        } RMGLShaderType;

        class RMGLShader {

        private:
            GLuint _handle{0};
            bool _compiled{false};
            RMGLShaderType _type{RMGLShaderTypeVertex};
            const GLchar* _source;

        public:

            RMGLShader(const char *source, RMGLShaderType type)
                    : _source(source),  _type(type)
            {}

            constexpr RMGLShaderType getType() const noexcept {
                return _type;
            }

            constexpr GLuint getHandle() const noexcept {
                return _handle;
            }

            bool compile() noexcept  {

                if (_handle == 0) {

                    GLenum shaderType;
                    switch (_type) {
                        case RMGLShaderTypeFragment:
                            shaderType = GL_FRAGMENT_SHADER;
                            break;
                        case RMGLShaderTypeVertex:
                            shaderType = GL_VERTEX_SHADER;
                            break;
#ifdef GL_GEOMETRY_SHADER
                        case RMGLShaderTypeGeometry:
                            shaderType = GL_GEOMETRY_SHADER;
                            break;
#endif
                        default:
                            shaderType = GL_VERTEX_SHADER;
                            break;
                    }

                    _handle = glCreateShader(shaderType);

                    if (_handle == 0) {
                        return false;
                    }


                    glShaderSource(_handle, 1, &_source, nullptr); // vertex_shader_source is a GLchar* containing glsl shader source code
                    glCompileShader(_handle);

                    GLint shader_compiled;
                    glGetShaderiv(_handle, GL_COMPILE_STATUS, &shader_compiled);
                    if (shader_compiled != GL_TRUE)
                    {
                        //GLsizei log_length = 0;
                        //GLchar message[1024];
                        //glGetShaderInfoLog(vshader, 1024, &log_length, message);
                        // Write the error to a log

                        return false;
                    } else {
                        _compiled = true;
                    }
                }

                return _compiled;
            }

            constexpr bool isCompiled() const noexcept {
                return _compiled;
            }

        };
    }
}


#endif //RMPROPELLER_RMGLSHADER_HPP
