//
// Created by Vitali Kurlovich on 8/23/16.
//

#ifndef RMPROPELLER_RMGLPROGRAM_HPP
#define RMPROPELLER_RMGLPROGRAM_HPP


#include "../../../../opengl_common.hpp"

namespace rmengine {

    namespace graphics {


        class RMGLShader;

        class RMGLShaderProgram : public RMShaderProgram {

        private:
            GLuint _programHandle{0};
            bool _compiled{false};

        public:

            const GLuint getProgramHandle() {
                if (_programHandle == 0) {

                    _programHandle = glCreateProgram();
                }
                return _programHandle;
            }

            void attachShader(RMGLShader* shader) {

                if (shader->isCompiled() || shader->compile()) {
                    GLuint  shaderHandle =  shader->getHandle();
                    glAttachShader(getProgramHandle(), shaderHandle);
                }
            }



            bool compile() noexcept override {
                if (isCompiled())
                    return true;

                glLinkProgram(getProgramHandle());

                GLint program_linked;
                glGetProgramiv(getProgramHandle(), GL_LINK_STATUS, &program_linked);
                if (program_linked != GL_TRUE)
                {
                    GLsizei log_length = 0;
                    GLchar message[1024];
                    glGetProgramInfoLog(getProgramHandle(), 1024, &log_length, message);


                    std::cout << message;
                    // Write the error to a log
                } else {
                    _compiled = true;
                }


                return _compiled;
            }

            bool isCompiled() const noexcept override {
                return _compiled;
            }

            void use() {
                glUseProgram(getProgramHandle());
            }

        private:

            GLint getUniformLocation(const char *name)  noexcept {
                return glGetUniformLocation(getProgramHandle(), name);
            }

        public:

            void setUniform( const char *name, float x, float y, float z, float w) noexcept override {
                const GLint loc = getUniformLocation(name);
                glUniform4f(loc, x, y, z, w);
            }

            void setUniform( const char *name, float x, float y, float z) noexcept override {
                const GLint loc = getUniformLocation(name);
                glUniform3f(loc, x, y, z);
            }

            void setUniform( const char *name, float x, float y) noexcept override {
                const GLint loc = getUniformLocation(name);
                glUniform2f(loc, x, y);
            }

            void setUniform( const char *name, float val) noexcept override {
                const GLint loc = getUniformLocation(name);
                glUniform1f(loc, val);
            }

            void setUniform( const char *name, const vec2 &vec) noexcept override {
                const GLint loc = getUniformLocation(name);
                glUniform2f(loc, vec.x, vec.y);
            }

            void setUniform( const char *name, const vec3 &vec) noexcept override {
                const GLint loc = getUniformLocation(name);
                glUniform3f(loc, vec.x, vec.y, vec.z);
            }

            void setUniform( const char *name, const vec4 &vec) noexcept override {
                const GLint loc = getUniformLocation(name);
                glUniform4f(loc, vec.x, vec.y, vec.z, vec.w);
            }

            void setUniform( const char *name, const mat2x2 &mat) noexcept override {
                const GLint loc = getUniformLocation(name);
                glUniformMatrix2fv(loc, 1, GL_FALSE, mat.m);
            }

            void setUniform( const char *name, const mat3x3 &mat) noexcept override {
                const GLint loc = getUniformLocation(name);
                glUniformMatrix3fv(loc, 1, GL_FALSE, mat.m);
            }

            void setUniform( const char *name, const mat4x4 &mat) noexcept override {
                const GLint loc = getUniformLocation(name);
                glUniformMatrix4fv(loc, 1, GL_FALSE, mat.m);
            }

            void setUniform( const char *name, int32 val ) noexcept  override {
                const GLint loc = getUniformLocation(name);
                glUniform1i(loc, val);
            }

            void setUniform( const char *name, uint32 val ) noexcept  override {
                const GLint loc = getUniformLocation(name);
                glUniform1ui(loc, val);
            }

            void setUniform( const char *name, bool val ) noexcept  override {
                const GLint loc = getUniformLocation(name);
                glUniform1i(loc, val);
            }

        };
    }

}

#endif //RMPROPELLER_RMGLPROGRAM_HPP
