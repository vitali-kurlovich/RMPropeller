//
// Created by Vitali Kurlovich on 9/17/16.
//

#ifndef RMPROPELLER_RMRENDARABLE_HPP
#define RMPROPELLER_RMRENDARABLE_HPP

namespace rmengine {

    namespace graphics {

        class RMRendarable {
        public:
            virtual void render() const noexcept  = 0;
        };
    }
}


#endif //RMPROPELLER_RMRENDARABLE_HPP
