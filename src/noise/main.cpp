#include <FastNoise.h>
#include <raylib.h>

#include <array>
#include <cmath>
#include <cstdint>
#include <vector>

constexpr struct {
  std::size_t width {900};
  std::size_t height {600};
} screen;

int main() {
  InitWindow(static_cast<int>(screen.width), static_cast<int>(screen.height),
             "Noise");
  SetTargetFPS(60);

  float octave_scalars[] {50.f, 25.f, 13.f};

  FastNoise noise;
  noise.SetNoiseType(FastNoise::SimplexFractal);
  float angle {0.f};
  float radius {200.0f};
  float time_per_rot {2.f};
  std::size_t num_samples {720};

  while (!WindowShouldClose()) {
    BeginDrawing();
    {
      ClearBackground(BLACK);
      static float timer {0.f};
      timer += GetFrameTime();

      angle = timer / time_per_rot * 360.f;
      if (timer > time_per_rot) timer -= time_per_rot;

      for (std::size_t i {0}; i < num_samples; i += 2) {
        float angle_rad_cos {std::cos(DEG2RAD * angle)};
        float angle_rad_sin {std::sin(DEG2RAD * angle)};
        float i_rad_cos {std::cos(DEG2RAD * static_cast<float>(i))};
        float i_rad_sin {std::sin(DEG2RAD * static_cast<float>(i))};
        Vector3 current_noise_pos {angle_rad_cos, angle_rad_sin, i_rad_cos};
        float current_noise =
            noise.GetNoise(current_noise_pos.x * octave_scalars[0],
                           current_noise_pos.y * octave_scalars[0],
                           current_noise_pos.z * octave_scalars[0]) +
            noise.GetNoise(current_noise_pos.x + 10.f * octave_scalars[1],
                           current_noise_pos.y + 10.f * octave_scalars[1],
                           current_noise_pos.z * octave_scalars[1]) +
            noise.GetNoise(current_noise_pos.x - 10.f * octave_scalars[2],
                           current_noise_pos.y - 10.f * octave_scalars[2],
                           current_noise_pos.z * octave_scalars[2]);
        float current_radius {radius / 2.f +
                              radius / 2.f * current_noise / 10.f};
        Vector2 current_pos {i_rad_cos * current_radius + 300,
                             i_rad_sin * current_radius + 300};

        DrawCircleV(current_pos, 2, {255, 255, 255, 50});
      }

      // DrawFPS(10, 10);
    }
    EndDrawing();
  }
  CloseWindow();
}
