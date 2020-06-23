//
// Created by stb on 19.06.20.
//
#include <cmath>

#include <raylib.h>

#include <Eigen/Dense>

#include "constants.h"
#include "spaceship.h"

auto main() -> int
{
    InitWindow(stb::constants::screen.width, stb::constants::screen.height,
               "space");
    SetTargetFPS(60);

    Eigen::Rotation2Df rotation {0.02F};
    Eigen::Vector2f pointer {200.F, 0.F};

    stb::objects::SpaceShip ship;
    ship.set_position(Eigen::Vector2f {100.F, 100.F});

    float theta {0.F};
    while (!WindowShouldClose()) {
        theta += 0.01F;
        ship.set_theta(theta);
        ship.set_size(20.F + 10.F * sinf(theta));
        pointer = rotation * pointer;

        BeginDrawing();
        {
            ClearBackground(BLACK);

            ship.draw(WHITE);

            DrawFPS(10, 10);

            DrawLine(300 + static_cast<int>(pointer.x()),
                     300 + static_cast<int>(pointer.y()), 300, 300, WHITE);
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;
}