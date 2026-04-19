#include "EnergySystem.hpp"

void EnergySystem::distribute_sun_energy()
{
    for (int x = 0; x < WORLD_WIDTH; ++x) {
        int remainingPenetration = SUN_PENETRATION; 
        
        for (int y = WORLD_HEIGHT - 1; y >= 0; --y) {
            Cell* cell = world_.get_cell_at(x, y);
            if (!cell || cell->get_state() == DEAD) continue;
            
            // Энергия = глубина проникновения × (высота + бонус)
            int energyBonus = (y + LEVEL_BIAS);
            int energy = remainingPenetration * energyBonus;
            
            // TODO:
            if (cell->get_state() == WOOD || cell->get_state() == FALLING) 
            {
                // Древесина и семена получают энергию дерева
                // cell->tree()->add_energy(energy);
            } 
            else if (cell->get_state() == GROWING) 
            {
                // Отростки получают свою собственную энергию
                // std::cout << "y="<< y << " " << cell->get_energy() << std::endl;
                cell->set_energy(cell->get_energy() + energy);
            }
            
            remainingPenetration--;
            if (remainingPenetration <= 0) {
                break;
            }
        }
    }
}

void EnergySystem::consume_energy()
{
    for (int i = 0; i < world_.get_trees_list()->size(); i++)
    {
        (*(world_.get_trees_list()))[i].get()->energy -= 10; // TODO: redone mass*consumption
        // TODO: redo with tree->consume_energy (without public energy)
    }
}