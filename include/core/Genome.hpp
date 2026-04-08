#pragma once
#include <iostream>
#include <array>
#include <cstdint>
#include "Config.hpp"

enum Direction {LEFT, TOP, RIGHT, BOTTOM};

class Genome
{
private:
    std::array<uint8_t, GENOME_SIZE> genes_ = {};

public:
    Genome();
    friend std::ostream& operator<<(std::ostream& os, const Genome& gen);
};