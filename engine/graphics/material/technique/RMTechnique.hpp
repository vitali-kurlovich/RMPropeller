//
// Created by Vitali Kurlovich on 4/23/16.
//

#ifndef RMPROPELLER_RMTECHNIQUE_HPP
#define RMPROPELLER_RMTECHNIQUE_HPP


#include "../material_common.hpp"
#include "../pass/RMPass.hpp"

static const int RMMaxPassCount = 8;

namespace rmengine {
    namespace graphics {

        class RMTechnique {
        protected:
            int _passesCount;
            RMPass* _passes[RMMaxPassCount];

        public:
            RMTechnique(const RMPass* passes = nullptr, const int passesCount = 0)
            : _passesCount(passesCount) {
                for (int index = 0; index < passesCount; ++index) {
                    _passes[index] = passes[index];
                }
            }

            RMTechnique(const RMTechnique& other)
                    : _passesCount(other.passesCount) {
                for (int index = 0; index < other.passesCount; ++index) {
                    _passes[index] = other.passes[index];
                }
            }

        };
    }
}

#endif //RMPROPELLER_RMTECHNIQUE_HPP
