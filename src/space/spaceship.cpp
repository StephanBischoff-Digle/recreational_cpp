//
// Created by stb on 19.06.20.
//
#include <raylib.h>
#include "spaceship.h"


void stb::objects::SpaceShip::draw(Color col, float zoom) const {
    Eigen::Translation2f translate {position};
    Eigen::Rotation2Df rot {theta};
    auto size_transform = Eigen::Scaling(size);
    auto zoom_transform = Eigen::Scaling(zoom);
    auto transform = zoom_transform * translate * rot * size_transform;

    auto screen_a = transform * geometry.a;
    auto screen_b = transform * geometry.b;
    auto screen_c = transform * geometry.c;

    Vector2 points[] = {
        Vector2 {screen_a.x(), screen_a.y() * zoom},
        Vector2 {screen_b.x(), screen_b.y() * zoom},
        Vector2 {screen_c.x(), screen_c.y() * zoom},
        Vector2 {screen_a.x(), screen_a.y() * zoom}
    };
    DrawLineStrip(points, 4, col);
}
