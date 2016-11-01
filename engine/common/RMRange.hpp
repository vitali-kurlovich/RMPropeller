//
// Created by Vitali Kurlovich on 11/1/16.
//

#ifndef RMPROPELLER_RMRANGE_HPP
#define RMPROPELLER_RMRANGE_HPP


namespace rmengine {

    template<typename T>
    struct RMRange {
        const T begin{0};
        const T lenght{0};

        constexpr
        RMRange(T begin, T lenght)
                : begin(begin), lenght(lenght) {
        }

        constexpr
        RMRange(const RMRange<T> &range)
                : begin(range.begin), lenght(range.lenght) {
        }
    };

    template<typename T>
    constexpr
    bool operator == (const RMRange<T> &a, const RMRange<T> &b) {
        return &a == &b || (a.begin == b.begin && a.lenght == b.lenght);
    }

    template<typename T>
    constexpr
    bool operator != (const RMRange<T> &a, const RMRange<T> &b) {
        return !(a == b);
    }

}
#endif //RMPROPELLER_RMRANGE_HPP
