#ifndef GRID_HPP
#define GRID_HPP

#include <algorithm>
#include <cstdint>
#include <numeric>
#include <optional>
#include <vector>

class Grid
{
    std::size_t n_x {};
    std::size_t n_y {};

    std::vector<std::vector<float>> repr {};

   public:
    Grid(std::size_t x_subdevision, std::size_t y_subdevision)
        : n_x {x_subdevision}, n_y {y_subdevision}, repr {x_subdevision}
    {
        for (std::size_t x {}; x < x_subdevision; x++) {
            repr[x].resize(y_subdevision);
        }
    }

    void normalize(float sum = 1.0F)
    {
        float grid_max = std::accumulate(
            repr.begin(), repr.end(), 0.F,
            [](auto acc, std::vector<float>& line) {
                return std::max(
                    acc, std::accumulate(line.begin(), line.end(), 0.F,
                                         [](float sub_acc, float value) {
                                             return std::max(sub_acc, value);
                                         }));
            });
        float normalization_multiplicator = sum / grid_max;

        std::transform(repr.begin(), repr.end(), repr.begin(),
                       [&](std::vector<float>& line) {
                           std::transform(
                               line.begin(), line.end(), line.begin(),
                               [&](float& value) {
                                   return value * normalization_multiplicator;
                               });
                           return line;
                       });
    }

    [[nodiscard]] auto get_cell(std::size_t x, std::size_t y) const
        -> std::optional<float>
    {
        if (x >= n_x || y >= n_y) {
            return {};
        }

        return repr[x][y];
    }

    [[nodiscard]] auto get_repr() const
        -> std::vector<std::vector<float>> const&
    {
        return repr;
    }

    void set_cell(std::size_t x, std::size_t y, float value)
    {
        if (x >= n_x || y >= n_y) {
            return;
        }
        repr[x][y] = value;
    }
};

#endif
