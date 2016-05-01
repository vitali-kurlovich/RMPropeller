//
// Created by Vitali Kurlovich on 4/24/16.
//

#ifndef RMPROPELLER_RMPROGRAM_HPP
#define RMPROPELLER_RMPROGRAM_HPP

#include "graphics/material/material_common.hpp"

namespace rmengine {
    namespace graphics {

        class RMProgram {
        protected:
            union {
                struct {
                    uint8 _flagCompiled:1;
                    uint8 _flagHasError:1;
                };
                uint8 _flags;
            };

        public:
            RMProgram()
                    : _flags(0) {
            }

            RMProgram(const RMProgram &other)
                    : _flags(other._flags) {
            }

        protected:
            virtual bool _compileProgram() = 0;
            virtual bool _useProgram() = 0;

        public:

            const bool isCompiled() const {
                return _flagCompiled;
            }

            const bool useProgram() {
                if (_flagCompiled && !_flagHasError) {
                    return _useProgram();
                }
                return false;
            }

            const bool compile() {
                if (_flagCompiled) return !hasError();

                _flagHasError = !_compileProgram();
                _flagCompiled = true;

                return _flagCompiled && !_flagHasError;
            }

            const bool hasError() {
                return _flagHasError;
            }
        };
    }
}

#endif //RMPROPELLER_RMPROGRAM_HPP
