#pragma once
#include "Config.hpp"
#include "World.hpp"
#include "Tree.hpp"

class EnergySystem
{
private:
    World& world_;

public:
    EnergySystem(World& world): world_(world){};
    
    void consume_energy();
    void distribute_sun_energy();
};