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

#include <raylib.h>
#include <raylib_ext/vector2.h>

#include <cmath>
#include <limits>
#include <optional>

#include "boundary.h"

namespace stb {

/**
 * @brief A Ray is emmited from a direction into a direction and can be checked
 * for collision.
 */
class Ray {
 public:
  Ray(float x, float y) : pos {x, y}, dir {1, 0}, col {ORANGE} {}

  void set_direction(const Vector2& direction) { dir = direction; }
  void look_at(const Vector2& target) { dir = normalize(target - pos); }
  void move_to(const Vector2& target) { pos = target; }
  void show(float len) const { DrawLineEx(pos, pos + dir * len, 3, col); }
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
    if (std::fabs(den) <= std::numeric_limits<float>::epsilon())
      return std::nullopt;

    const float t {((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den};
    const float u {-((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den};

    if (t > 0.f && t < 1.f && u > 0.f)
      return Vector2 {x1 + t * (x2 - x1), y1 + t * (y2 - y1)};
    return std::nullopt;
  }

  Vector2 pos;
  Vector2 dir;
  Color col;
};

}  // namespace stb
