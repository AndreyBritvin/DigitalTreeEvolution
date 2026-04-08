#include "Genome.hpp"
#include <ostream>

Genome::Genome()
{
    
}

int Genome::set_gene(std::array<uint8_t, GENOME_SIZE>& to_copy)
{
    for (int i = 0; i < sizeof(this->genes_); i++){
        this->genes_[i] = to_copy[i];
    }

    return 0; // TODO:add error codes
}

std::ostream& operator<<(std::ostream& os, const Genome& gen)
{
    os << "Printing Genome: ";
    for (int i = 0; i < GENOME_SIZE; i++)
    {
        if (i % 4 == 0) os << i / 4 << ")<";
        os << static_cast<int>(gen.genes_[i]) << " ";
        if (i % 4 == 3) os << "\b>  ";
    }

    return os;
}