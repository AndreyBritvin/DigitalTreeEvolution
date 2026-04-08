#include "Genome.hpp"
#include <ostream>

Genome::Genome()
{
    
}

// class Genome
// {
// private:
//     array<uint8_t, GENOME_SIZE> genes_ = {};
// };

std::ostream& operator<<(std::ostream& os, const Genome& gen)
{
    os << "Printing Genome: " << std::endl;
    return os;
}