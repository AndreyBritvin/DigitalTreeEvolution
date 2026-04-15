#include "World.hpp"
#include "Cell.hpp"

World::World()
{
    // unique_ptr are nullptr by default, no initialization needed
}

int World::create_cell(int x, int y, int active_gene, Tree& tree, Cell_state state)
{
    this->grid_[x][y] = std::make_unique<Cell>(x, y, active_gene, tree, state);

    return EXIT_SUCCESS;
}
