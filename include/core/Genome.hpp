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

    uint8_t operator[](size_t index) const {
        if (index >= GENOME_SIZE) {
            throw std::out_of_range("Genome index out of range");
        }
        return genes_[index];
    }

    uint8_t& operator[](size_t index) {
        if (index >= GENOME_SIZE) {
            throw std::out_of_range("Genome index out of range");
        }
        return genes_[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const Genome& gen);
    int set_gene(std::array<uint8_t, GENOME_SIZE>&);

    auto get_gene_group(int gene) { 
        return (std::array<uint8_t, 4>){genes_[4*gene+0],genes_[4*gene+1],genes_[4*gene+2],genes_[4*gene+3]};
    }
};