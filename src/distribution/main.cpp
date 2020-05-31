#include <raylib.h>

#include <cstdint>
#include <limits>

#include "constants.hpp"
#include "grid.hpp"

template <typename In, typename Out>
constexpr auto project(In src_low, In src_high, Out trgt_low, Out trgt_high,
                       In value) -> Out
{
    auto const src_range {src_high - src_low};
    auto const trgt_range {trgt_high - trgt_low};
    auto const factor {static_cast<In>(trgt_range) / src_range};
    return static_cast<Out>((value - src_low) * factor);
}

auto main() -> int
{
    InitWindow(static_cast<int>(stb::constants::screen::width),
               static_cast<int>(stb::constants::screen::height),
               "distribution");
    SetTargetFPS(stb::constants::fps::target);

    Grid grid {stb::constants::distribution::subdevisions,
               stb::constants::distribution::subdevisions};
    grid.set_cell(stb::constants::distribution::subdevisions / 2,
                  stb::constants::distribution::subdevisions / 2, 100.F);
    grid.normalize(1.F);

    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(BLACK);

            DrawRectangle(stb::constants::distribution::pos::x -
                              stb::constants::distribution::border::distance -
                              stb::constants::distribution::border::stroke,
                          stb::constants::distribution::pos::y -
                              stb::constants::distribution::border::distance -
                              stb::constants::distribution::border::stroke,
                          2 * (stb::constants::distribution::border::distance +
                               stb::constants::distribution::border::stroke) +
                              stb::constants::distribution::subdevisions,
                          2 * (stb::constants::distribution::border::distance +
                               stb::constants::distribution::border::stroke) +
                              stb::constants::distribution::subdevisions,
                          WHITE);
            DrawRectangle(stb::constants::distribution::pos::x -
                              stb::constants::distribution::border::distance,
                          stb::constants::distribution::pos::y -
                              stb::constants::distribution::border::distance,
                          2 * stb::constants::distribution::border::distance +
                              stb::constants::distribution::subdevisions,
                          2 * stb::constants::distribution::border::distance +
                              stb::constants::distribution::subdevisions,
                          BLACK);

            auto const& data {grid.get_repr()};
            for (std::size_t x {0}; x < data.size(); x++) {
                for (std::size_t y {0}; y < data[x].size(); y++) {
                    std::uint8_t color_component {
                        project(0.F, 1.F, std::uint8_t {0},
                                stb::constants::general::col_max, data[x][y])};
                    DrawPixel(stb::constants::distribution::pos::x +
                                  static_cast<int>(x),
                              stb::constants::distribution::pos::y +
                                  static_cast<int>(y),
                              Color {stb::constants::general::col_max,
                                     stb::constants::general::col_max,
                                     stb::constants::general::col_max,
                                     color_component});
                }
            }

            DrawFPS(stb::constants::fps::pos::x, stb::constants::fps::pos::y);
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
