//
// Created by Vitali Kurlovich on 8/23/16.
//

#ifndef RMPROPELLER_RMRESOURCE_HPP
#define RMPROPELLER_RMRESOURCE_HPP

#include "../../common/common.hpp"

namespace rmengine {

    typedef enum : uint8 {
        RMResourceTypeString,
        RMResourceTypeImage,
        RMResourceTypeMesh,
        RMResourceTypeData
    } RMResourceType;


    class RMResource {

        uint32 _hash{0};
        RMResourceType _type{RMResourceTypeData};

    public:

        constexpr RMResource(RMResourceType type, uint32  hash = 0) noexcept
        : _type(type), _hash(hash)
        {

        }

        constexpr RMResourceType getType() const noexcept {
            return _type;
        }

        constexpr uint32 getHash() const noexcept {
            return _hash;
        }

    };


}

#endif //RMPROPELLER_RMRESOURCE_HPP
