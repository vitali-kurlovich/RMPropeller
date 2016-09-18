//
// Created by Vitali Kurlovich on 5/1/16.
//

#ifndef RMPROPELLER_RMMESH_HPP
#define RMPROPELLER_RMMESH_HPP


#include "../geometry_common.hpp"


namespace rmengine {

    namespace graphics {

        typedef enum : uint8 {
            RMMeshType_Static = 0,
            RMMeshType_Dynamic = 1
        } RMMeshType;

        class RMMesh {
            RMMeshType _type{RMMeshType_Static};

        };
    }
}

#endif //RMPROPELLER_RMMESH_HPP
