#pragma once
#include <iostream>
#include <array>
#include <cstdint>
#include "Config.hpp"

enum Direction {LEFT, TOP, RIGHT, BOTTOM};

class Genome
{
private:
// TODO: redo typedef for genome array<GENE>
    std::array<uint8_t, GENOME_SIZE> genes_ = {};

public:
    Genome();
    friend std::ostream& operator<<(std::ostream& os, const Genome& gen);
    int set_gene(std::array<uint8_t, GENOME_SIZE>&);
    
    auto get_gene_group(int gene) { 
        return (std::array<uint8_t, 4>){genes_[4*gene+0],genes_[4*gene+1],genes_[4*gene+2],genes_[4*gene+3]};
    }
};