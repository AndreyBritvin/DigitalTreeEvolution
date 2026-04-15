#pragma once
#include <array>
#include <memory>
#include "Config.hpp"
#include "Cell.hpp"
#include "Tree.hpp"
#include "Genome.hpp"

class World
{
private:
    std::array<std::array<std::unique_ptr<Cell>, WORLD_HEIGHT>, WORLD_WIDTH> grid_;

public:
    World();
    int create_cell(int x, int y, int active_gene, Tree& tree, Cell_state state);

    int cell_count() {return grid_.size();};
    auto get_cell_at(int x, int y) {return grid_[x][y].get();};
};