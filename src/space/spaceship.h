//
// Created by stb on 19.06.20.
//

#ifndef ABC_SPACESHIP_H
#define ABC_SPACESHIP_H

#include <raylib.h>
#include <Eigen/Dense>
#include "constants.h"

namespace stb::objects {
class SpaceShip {
    Eigen::Vector2f position {0.F, 0.F};
    float theta {0.F};
    float size {30.F};

    struct Geometry {
        Eigen::Vector2f a {0.F, 1.F};
        Eigen::Vector2f b {-.5F, -1.F};
        Eigen::Vector2f c {.5F, -1.F};
    } geometry {};

   public:
    void draw(Color col, float zoom=1.F) const;
    void set_position(Eigen::Vector2f pos) {position = pos;}
    void set_theta(float angle) {theta = angle;}
    void set_size(float resize) {size = resize;}
};
}

#endif  // ABC_SPACESHIP_H
