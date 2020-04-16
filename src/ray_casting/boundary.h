#pragma once

#include <raylib.h>

namespace stb {
class Boundary {
 public:
  Boundary(Vector2 v1, Vector2 v2) : a {v1}, b {v2} {}

  void show() const { DrawLineEx(a, b, 4, BLACK); }

  Vector2 a;
  Vector2 b;
};
}  // namespace stb
