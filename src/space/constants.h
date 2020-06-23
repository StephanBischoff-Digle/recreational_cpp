//
// Created by stb on 19.06.20.
//

#ifndef ABC_CONSTANTS_H
#define ABC_CONSTANTS_H

namespace stb {
template <typename T>
struct Dimensions
{
    T width;
    T height;
};

namespace constants {
Dimensions<int> const screen {800, 600};
}  // namespace constants
}  // namespace stb

#endif  // ABC_CONSTANTS_H
