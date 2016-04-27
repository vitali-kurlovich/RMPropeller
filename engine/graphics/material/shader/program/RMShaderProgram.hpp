//
// Created by Vitali Kurlovich on 4/24/16.
//

#ifndef RMPROPELLER_RMSHADERPROGRAM_HPP
#define RMPROPELLER_RMSHADERPROGRAM_HPP


#include "RMPixelProgram.hpp"
#include "RMVertexProgram.hpp"
#include "RMProgram.hpp"

#include "../material_common.hpp"

namespace rmengine {
    namespace graphics {

        class RMShaderProgram : public RMProgram {

        protected:
            union {
                struct {
                    uint8 _flagVertexProgramCompiled:1;
                    uint8 _flagPixelProgramCompiled:1;
                    uint8 _flagVertexProgramHasError:1;
                    uint8 _flagPixelProgramHasError:1;
                };
                uint8 _shaderFlags;
            };

            RMVertexProgram *_vertexProgram;
            RMPixelProgram *_pixelProgram;
        public:
            RMShaderProgram(const RMVertexProgram *vertexProgram = nullptr,
                            const RMPixelProgram *pixelProgram = nullptr)
                    : RMProgram(),
                      _shaderFlags(0),
                      _vertexProgram(vertexProgram),
                      _pixelProgram(pixelProgram) {
            }

            RMShaderProgram(const RMShaderProgram &other)
                    : RMProgram(other),
                      _shaderFlags(other._shaderFlags),
                      _vertexProgram(other.vertexProgram),
                      _pixelProgram(other.pixelProgram) {
            }


        public:
            const RMVertexProgram *vertexProgram() const {
                return _vertexProgram;
            }

            const RMPixelProgram *pixelProgram() const {
                return _pixelProgram;
            }

        protected:
            virtual bool compileProgram() override {

                if (_flagCompiled) return true;

                if (!_flagVertexProgramCompiled) {
                    if (_vertexProgram == nullptr) {
                        _flagVertexProgramCompiled = true;
                        _flagVertexProgramHasError = false;
                    } else {
                        _vertexProgram->compile();
                        _flagVertexProgramCompiled = _vertexProgram->isCompiled();
                        _flagVertexProgramHasError = _vertexProgram->hasError();
                    }
                }

                if (!_flagPixelProgramCompiled) {

                    if (_pixelProgram == nullptr) {
                        _flagPixelProgramCompiled = true;
                        _flagPixelProgramHasError = false;
                    } else {
                        _pixelProgram->compile();
                        _flagPixelProgramCompiled = _pixelProgram->isCompiled();
                        _flagPixelProgramHasError = _pixelProgram->hasError();
                    }
                }

                _flagCompiled = _flagVertexProgramCompiled && _flagPixelProgramCompiled;
                _flagHasError = _flagVertexProgramHasError || _flagPixelProgramHasError;
                return _flagCompiled;
            }
        };
    }
}

#endif //RMPROPELLER_RMSHADERPROGRAM_HPP
