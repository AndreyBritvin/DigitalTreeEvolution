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

    std::vector<std::unique_ptr<Tree>> tree_pool_;
    // std::unordered_map<int, Tree*> active_trees_;

public:
    World();
    int create_cell(int x, int y, int active_gene, Tree& tree, Cell_state state);

    int cell_count() {return grid_.size();};
    auto get_cell_at(int x, int y) {return grid_[x][y].get();};

    auto get_trees_list() {return &tree_pool_;}
    
    // TODO: think about FALLING
    bool is_position_free(int x, int y) 
    {
        if (grid_[x][y].get() == nullptr) return true;
        return grid_[x][y].get()->get_state() == EMPTY;
    }
 
    // TODO: maybe it good idea
    // class CellIterator {};
};