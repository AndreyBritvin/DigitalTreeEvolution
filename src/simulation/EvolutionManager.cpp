#include <vector>
#include "EvolutionManager.hpp"
#include "Tree.hpp"

void EvolutionManager::process_growth() {
    std::vector<Cell*> cells_to_grow;
    for (int x = 0; x < WORLD_WIDTH; ++x) 
    {
        for (int y = 0; y < WORLD_HEIGHT; ++y) 
        {
            Cell* cell = world_.get_cell_at(x, y);
            if (cell != nullptr && cell->get_state() == GROWING && cell->has_enough_energy()) 
            {
                cells_to_grow.push_back(cell);
            }
        }
    }

    for (Cell* cell : cells_to_grow)
    {
        int x = cell->get_x();
        int y = cell->get_y();
        int Gene = cell->get_active_gene();
        Tree& tree = cell->get_tree();
        std::array<uint8_t, 4> genes = tree.get_genome().get_gene_group(Gene);
        
        // TODO: think about reducing copypaste
        int new_gene = genes[0];
        if (new_gene < 16 && y + 1 < WORLD_HEIGHT)
        {  // <16 = разрешён рост
            if (world_.is_position_free(x, y + 1)) 
            {
                world_.create_cell(x, y + 1, new_gene, tree, GROWING);
            }
        }
        
        new_gene = genes[1];        
        if (new_gene < 16) 
        {
            int nx = (x == 0) ? WORLD_WIDTH - 1 : x - 1;  
            if (world_.is_position_free(nx, y)) 
            {
                world_.create_cell(nx, y, new_gene, tree, GROWING);
            }
        }
        
        new_gene = genes[2];
        if (new_gene < 16) 
        {
            int nx = (x == WORLD_WIDTH - 1) ? 0 : x + 1;  
            if (world_.is_position_free(nx, y)) 
            {
                world_.create_cell(nx, y, new_gene, tree, GROWING);
            }
        }
        
        new_gene = genes[3];
        if (new_gene < 16 && y > 0) 
        {
            if (world_.is_position_free(x, y - 1)) 
            {
                world_.create_cell(x, y - 1, new_gene, tree, GROWING);
            }
        }

        cell->set_state(WOOD);
        cell->set_energy(cell->get_energy() - 100);// TODO: redo via consume energy
    }
}