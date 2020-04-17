/**
 * @file boundary.h
 * @author Stephan Bischoff
 * @date 2020-04-08
 * @brief File contains the Boundary class
 *
 * The Boundary class is part of the raycasting experiment.
 * It is used as a collision object for the rays.
 */

#pragma once

#include <raylib.h>

namespace stb {

/**
 * @brief A Boundary is an object that can be hit by a ray.
 */
class Boundary {
  Vector2 a; /**< An endpoint of the boundary. */
  Vector2 b; /**< An endpoint of the boundary. */

 public:
  /**
   * @brief Constructs the Boundary between the two arguments.
   * @param v1 the first boundary endpoint
   * @param v2 the second boundary endpoint
   */
  Boundary(Vector2 v1, Vector2 v2) : a {v1}, b {v2} {}

  /**
   * @brief Draws the Boundary to the canvas.
   *
   * The Boundary is drawn as a black line 4 pixel wide.
   */
  void show() const { DrawLineEx(a, b, 4, BLACK); }
};
}  // namespace stb
