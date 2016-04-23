//
// Created by Vitali Kurlovich on 4/23/16.
//

#ifndef RMPROPELLER_RMPASS_HPP
#define RMPROPELLER_RMPASS_HPP

#include "../../common/rmtypes.hpp"

#include "RMAlpha.hpp"
#include "RMBlend.hpp"
#include "RMDepth.hpp"

#include "../shader/RMShader.hpp"

class RMPass {
protected:
    rm_uint32 opaque:1;
    rm_uint32 blendEnable:1;
    rm_uint32 depthEnable:1;

    RMAlpha alpha;
    RMBlend blend;
    RMDepth depth;

    RMShader* shader;
public:
};


#endif //RMPROPELLER_RMPASS_HPP
