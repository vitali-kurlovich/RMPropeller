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
            virtual bool compileProgram() = 0;

        public:
            virtual bool useProgram() = 0;

            bool isCompiled() const {
                return _flagCompiled;
            }

            bool compile() {
                if (_flagCompiled) return !hasError();

                if (compileProgram()) {
                    _flagCompiled = true;
                    _flagHasError = false;
                } else {
                    _flagCompiled = true;
                    _flagHasError = true;
                }
                return _flagCompiled && !_flagHasError;
            }

            bool hasError() {
                if (_flagHasError) {
                    return true;
                }

                if (!isCompiled()) {
                    return false;
                }

                if (compileProgram()) {
                    _flagCompiled = true;
                    _flagHasError = false;
                } else {
                    _flagCompiled = true;
                    _flagHasError = true;
                }

                return _flagHasError;
            }
        };
    }
}

#endif //RMPROPELLER_RMPROGRAM_HPP
