#include "Cell.hpp"

std::ostream& operator<<(std::ostream& os, const Cell& cell)
{
    os << "=== Cell Info ===\n";
    os << "X = "<< static_cast<int>(cell.x_) << ", Y = " << static_cast<int>(cell.y_) << "\n";
    os << "Genome: " << cell.tree.get_genome();
    os << "Position: (" << cell.x_ << ", " << cell.y_ << ")\n";
    os << "State: ";
    switch (cell.state_) {
        case DEAD: os << "DEAD"; break;
        case WOOD: os << "WOOD"; break;
        case GROWING: os << "GROWING"; break;
        case FALLING: os << "FALLING_SEED"; break;
    }
    os << "\n";
    os << "Active gene: " << (int)cell.active_gen_ << "\n";
    os << "Energy: " << cell.energy_ << "\n";
    
    // Tree* tree = cell.tree;
    // if (tree) {
    //     os << "Tree ID: " << tree->id() << std::endl;
    //     os << "Tree mass: " << tree->mass() << std::endl;
    //     os << "Tree energy: " << tree->energy() << std::endl;
    //     os << "Tree age: " << tree->age() << std::endl;
    //     os << "Color: RGB(" << (int)tree->r() << ", " 
    //               << (int)tree->g() << ", " << (int)tree->b() << ")" << std::endl;
    // }
    os << "=================\n"; 

    return os;
}