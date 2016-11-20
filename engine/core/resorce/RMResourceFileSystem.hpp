//
// Created by Vitali Kurlovich on 11/13/16.
//

#ifndef RMPROPELLER_RMRESOURCEFILESYSTEM_HPP
#define RMPROPELLER_RMRESOURCEFILESYSTEM_HPP


#include "../../common/common.hpp"
#include "RMResourceHeader.hpp"


namespace rmengine {

    namespace resource {

        class RMResourceFileSystem {

        public:
            class Item {
                std::string filename;
                RMResourceHeader header;

                const std::string& filepath() const {

                };
            };

        };
    }
}


#endif //RMPROPELLER_RMRESOURCEFILESYSTEM_HPP
