#include "World.hpp"
#include "Cell.hpp"

World::World()
{
    // unique_ptr are nullptr by default, no initialization needed
}

int World::create_cell(int x, int y, int active_gene, Tree& tree, Cell_state state)
{
    this->grid_[x][y] = std::make_unique<Cell>(x, y, active_gene, tree, state);
    tree_pool_.push_back(std::make_unique<Tree>(tree));
    
    return EXIT_SUCCESS; 
}

void World::kill_trees()
{
    std::vector<Cell*> cells_to_kill;
    for (int x = 0; x < WORLD_WIDTH; ++x) 
    {
        for (int y = 0; y < WORLD_HEIGHT; ++y) 
        {
            Cell* cell = get_cell_at(x, y);
            if (cell == nullptr)
            {
                continue;
            }
            if (cell->get_state() == WOOD) 
            {
                cells_to_kill.push_back(cell);
            }
            if (cell->get_state() == GROWING) 
            {
                cell->set_state(FALLING);
            }            
        }
    }

    for (Cell* cell : cells_to_kill)
    {
        cell->kill();
    }

}

void World::move_cell_down(int x, int y)
{
    grid_[x][y - 1] = std::move(grid_[x][y]);
    Cell* cell = grid_[x][y - 1].get();
    cell->set_y(y - 1);
}