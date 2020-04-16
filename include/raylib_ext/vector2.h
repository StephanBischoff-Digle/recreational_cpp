#pragma once

#include <raylib.h>

#include <cmath>
#include <limits>

Vector2 operator+(Vector2 lhs, const Vector2& rhs) {
  return {lhs.x + rhs.x, lhs.y + rhs.y};
}

Vector2 operator-(Vector2 lhs, const Vector2& rhs) {
  return {lhs.x - rhs.x, lhs.y - rhs.y};
}

Vector2 operator*(Vector2 lhs, const float& rhs) {
  return {lhs.x * rhs, lhs.y * rhs};
}

float size(const Vector2& vec) {
  return {
      static_cast<float>(std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2)))};
}

Vector2 normalize(const Vector2& vec) {
  float len = size(vec);
  return {vec.x / len, vec.y / len};
}
