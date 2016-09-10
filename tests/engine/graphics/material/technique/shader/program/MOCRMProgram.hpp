//
// Created by Vitali Kurlovich on 5/1/16.
//

#ifndef RMPROPELLER_MOCRMPROGRAM_HPP
#define RMPROPELLER_MOCRMPROGRAM_HPP


#include "gtest/gtest.h"

#include <core/resorces/RMResource.hpp>

using namespace rmengine;
using  namespace graphics;

TEST(RMResourceTest, constructor) {

RMResource::RMResourceType::Vertex;

}

/*

namespace rmengine {
    namespace graphics {

        class MOCRMProgram : public RMProgram {
        protected:
            bool _complileFlag;
            bool _useProgramFlag;

        public:
            MOCRMProgram(const bool complile, const bool useProgram = true)
                    : _complileFlag(complile),
                      _useProgramFlag(useProgram) {
            }

        protected:
            virtual bool _compileProgram() override {
                return _complileFlag;
            }

            virtual bool _useProgram() override  {
                return _useProgramFlag;
            };
        };


        class MOCRMVertexProgram : public RMVertexProgram {
        protected:
            bool _complileFlag;
            bool _useProgramFlag;

        public:
            MOCRMVertexProgram(const bool complile, const bool useProgram = true)
                    : _complileFlag(complile),
                      _useProgramFlag(useProgram) {
            }

        protected:
            virtual bool _compileProgram() override {
                return _complileFlag;
            }

            virtual bool _useProgram() override  {
                return _useProgramFlag;
            };
        };

        class MOCRMPixelProgram : public RMPixelProgram {
        protected:
            bool _complileFlag;
            bool _useProgramFlag;

        public:
            MOCRMPixelProgram(const bool complile, const bool useProgram = true)
                    : _complileFlag(complile),
                      _useProgramFlag(useProgram) {
            }

        protected:
            virtual bool _compileProgram() override {
                return _complileFlag;
            }

            virtual bool _useProgram() override  {
                return _useProgramFlag;
            };
        };
    }
}
 */

#endif //RMPROPELLER_MOCRMPROGRAM_HPP
