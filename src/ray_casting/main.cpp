#include <raylib.h>

#include <cmath>
#include <cstdint>
#include <optional>
#include <utility>
#include <vector>

#include "boundary.h"
#include "ray.h"

constexpr float F_PI {static_cast<float>(M_PI)};

float rad_to_deg(float rad) { return rad / F_PI * 180; }
float deg_to_rad(float deg) { return deg / 180 * F_PI; }
Vector2 vec_from_deg(float deg) {
  return {std::cos(deg_to_rad(deg)), std::sin(deg_to_rad(deg))};
}
float project(float low, float x, float high) {
  return low + std::max(0.f, std::min(1.f, x)) * (high - low);
}

const struct {
  int width {900};
  int height {600};
} screen;

int main() {
  InitWindow(screen.width, screen.height, "DevWindow");
  SetTargetFPS(60);

  std::vector<stb::Ray> rays;
  for (float i {0.f}; i <= 360.f; i += 0.05f) {
    stb::Ray r {1.f, 1.f};
    r.set_direction(vec_from_deg(i));
    rays.push_back(r);
  }

  std::vector<stb::Boundary> walls;
  walls.push_back({{200, 100}, {300, 400}});
  walls.push_back({{300, 400}, {700, 400}});
  walls.push_back({{700, 400}, {600, 100}});
  walls.push_back({{800, 500}, {700, 0}});

  while (!WindowShouldClose()) {
    BeginDrawing();
    {
      ClearBackground(BLACK);
      auto mouse = GetMousePosition();

      for (stb::Ray& r : rays) {
        r.move_to(mouse);

        std::optional<Vector2> closest {std::nullopt};
        float closest_dist {std::numeric_limits<float>::infinity()};
        for (const auto& wall : walls) {
          if (auto hit {r.cast(wall)}) {
            if (!closest) {
              closest = hit;
              closest_dist = size(*hit - mouse);
            } else {
              float dist = size(*hit - mouse);
              if (closest_dist > dist) {
                closest_dist = dist;
                closest = hit;
              }
            }
          }
        }
        if (closest) {
          DrawLineEx(*closest, mouse, 3, {255, 255, 255, 3});
        } else {
          r.col = {255, 255, 255, 3};
          r.show(1000.f);
        }
      }

      for (const auto& wall : walls) {
        wall.show();
      }

      DrawFPS(10, 10);
    }
    EndDrawing();
  }
  CloseWindow();
}
