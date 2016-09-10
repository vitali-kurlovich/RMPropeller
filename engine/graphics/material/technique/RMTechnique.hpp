//
// Created by Vitali Kurlovich on 4/23/16.
//

#ifndef RMPROPELLER_RMTECHNIQUE_HPP
#define RMPROPELLER_RMTECHNIQUE_HPP


#include "../material_common.hpp"

#include "pass/RMPass.hpp"

#include <vector>


namespace rmengine {

    namespace graphics {

        class RMTechnique {
        protected:
            std::vector<RMPass*> _passes;

            union {
                struct {
                    bool _multipass:1;
                    bool _requireBlendEnable:1;
                    bool _requireDepthSort:1;
                };

                uint32 _flags;
            };

        public:

            RMTechnique(const RMTechnique& other)
            : _passes(other._passes), _flags(other._flags) {
            }

            RMTechnique(std::initializer_list<RMPass*> passes)
            : _multipass(passes.size() > 1)  {
                _passes.reserve(passes.size());
                for ( RMPass* pass : passes ) {
                    _passes.push_back(pass);

                    _requireBlendEnable |= pass->requireBlendEnable();
                    _requireDepthSort |= pass->requireDepthSort();
                }
            }

            RMTechnique(std::vector<RMPass*> passes)
            : _multipass(passes.size() > 1) {

                _passes.reserve(passes.size());
                for ( RMPass* pass : passes ) {
                    _passes.push_back(pass);

                    _requireBlendEnable |= pass->requireBlendEnable();
                    _requireDepthSort |= pass->requireDepthSort();
                }
            }


            const bool isMultipass() const {
                return _multipass;
            }

            const bool requireBlendEnable() const {
                return _requireBlendEnable;
            }

            const bool requireDepthSort() const {
                return _requireDepthSort;
            }
        };
    }
}

#endif //RMPROPELLER_RMTECHNIQUE_HPP
