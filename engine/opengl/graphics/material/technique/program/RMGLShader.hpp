//
// Created by Vitali Kurlovich on 11/8/16.
//

#ifndef RMPROPELLER_RMGLSHADER_HPP
#define RMPROPELLER_RMGLSHADER_HPP

#include "../../../../opengl_common.hpp"

namespace rmengine {

    namespace graphics {

        GLenum glEnum(RMShader::RMShaderType type) {
            GLenum shaderType(0);
            switch (type) {
                case RMShader::RMShaderTypeFragment :
                    shaderType = GL_FRAGMENT_SHADER;
                    break;
                case RMShader::RMShaderTypeVertex:
                    shaderType = GL_VERTEX_SHADER;
                    break;
#ifdef GL_GEOMETRY_SHADER
                case RMShader::RMShaderTypeGeometry:
                    shaderType = GL_GEOMETRY_SHADER;
                    break;
#endif
                default:
                    shaderType = GL_VERTEX_SHADER;
                    break;
            }
            return shaderType;
        }

        class RMGLShader : public RMShader {

        protected:
            GLuint _handle{0};
            const std::string _source;

        private:
            bool _compiled{false};
        public:
            RMGLShader(std::string source, RMShaderType type)
                    : RMShader::RMShader(type), _source(source) {
            }

            RMGLShader( const char *source, RMShaderType type)
                    : RMShader::RMShader(type), _source(source) {
            }


            virtual ~RMGLShader() {
                if (_handle != 0) {
                    glDeleteShader(_handle);
                }
            }

            constexpr
            GLuint getHandle() const noexcept {
                return _handle;
            }

            bool compile() noexcept override {

                if (_compiled) return true;

                if (_handle == 0 && _source.size() > 0) {
                    _handle = glCreateShader(glEnum(type));

                    if (_handle == 0) return false;

                    const char *src =  _source.c_str();
                    glShaderSource(_handle, 1, &src , nullptr);
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

        };

    }
}


#endif //RMPROPELLER_RMGLSHADER_HPP
