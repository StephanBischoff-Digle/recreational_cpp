/**
 * @file ray.h
 * @author Stephan Bischoff
 * @date 2020-04-08
 * @brief File contains the Ray class
 *
 * The Ray class is part of the raycasting experiment.
 * It is used to be emitted from a location into a direction and then check if
 * it hits a boundary.
 */
#pragma once

#include <raylib_ext/vector2.h>

#include <cmath>
#include <limits>
#include <optional>

#include "boundary.h"
#include "raylib.h"

namespace stb {

/**
 * @brief A Ray is emmited from a direction into a direction and can be checked
 * for collision.
 */
class Ray {
 public:
  Ray(float x, float y) : pos {x, y}, dir {1, 0}, col {ORANGE} {}

  /**
   * @brief Sets the direction of the ray to the method argument.
   */
  void set_direction(const Vector2& direction) { dir = direction; }

  /**
   * @brief Calculates the direction from the rays source and the target
   * position.
   */
  void look_at(const Vector2& target) { dir = normalize(target - pos); }

  /**
   * @brief Moves the ray source to the target position without changing the
   * direction.
   */
  void move_to(const Vector2& target) { pos = target; }

  /**
   * @brief Draws to ray to the screen.
   *
   * @param line_width The width of the line that represents the ray.
   * @param len The length of the line, representing the ray.
   */
  void show(float line_width, float len) const {
    DrawLineEx(pos, pos + dir * len, line_width, col);
  }

  /**
   * @brief Calculates if the ray hits the wall. If it hits the wall, the method
   * returns the intersection point between it and the boundary.
   *
   * @param wall The boundary this methods checks for intersection with the ray.
   * @returns The intersection point if it exists.
   */
  std::optional<Vector2> cast(const Boundary& wall) const {
    const float x1 {wall.a.x};
    const float y1 {wall.a.y};
    const float x2 {wall.b.x};
    const float y2 {wall.b.y};

    const float x3 {pos.x};
    const float y3 {pos.y};
    const float x4 {pos.x + dir.x};
    const float y4 {pos.y + dir.y};

    const float den {(x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)};
    if (std::fabs(den) <= std::numeric_limits<float>::epsilon()) return {};

    const float t {((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den};
    const float u {-((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den};

    if (t > 0.f && t < 1.f && u > 0.f)
      return {x1 + t * (x2 - x1), y1 + t * (y2 - y1)};
    return {}
  }

  Vector2 pos;
  Vector2 dir;
  Color col;
};

}  // namespace stb
