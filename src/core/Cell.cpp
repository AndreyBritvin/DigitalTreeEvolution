#include "Cell.hpp"

std::ostream& operator<<(std::ostream& os, const Cell& cell)
{
    os << "Printing Cell information:\n";
    os << "X = "<< static_cast<int>(cell.x_) << ", Y = " << static_cast<int>(cell.y_) << "\n";
    os << "Genome: " << cell.tree.get_genome(); 

    return os;
}