#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <cstdint>
#include <limits>

/// Systemwide constants
namespace stb::constants {

/// Constants that do not fit into any other category
namespace general {

/// Maximum color value
std::uint8_t const col_max {std::numeric_limits<std::uint8_t>::max()};
}  // namespace general

/// Constants related to the drawing window
namespace screen {
std::size_t const width {900};   ///< window width in pixel
std::size_t const height {600};  ///< window height in pixel
}  // namespace screen

/// Constants related to the frames per second
namespace fps {
int const target {60};  ///< Target frames per second

/// Constants related to the position of the fps counter
namespace pos {
int const x {10};  ///< FPS counter x coordinate
int const y {10};  ///< FPS counter y coordinate
}  // namespace pos
}  // namespace fps

/// Constants related to the probability distribution
namespace distribution {

/// Number of subdevision for discretizing the distribution
std::size_t const subdevisions {100};

/// Constants related to the position of the distribution grid
namespace pos {
int const x {100};  ///< x-coordinate of the upper left corner
int const y {100};  ///< y-coordinate of the upper left corner
}  // namespace pos

/// Constants related to the border around the distribution grid
namespace border {
int const distance {3};  ///< space between the grid and the border
int const stroke {1};    ///< thickness of the border in pixel
}  // namespace border
}  // namespace distribution
}  // namespace stb::constants

#endif
