#pragma once
#include "Config.hpp"
#include "World.hpp"
#include "EnergySystem.hpp"

class EvolutionManager
{
private:
    World& world_;
    EnergySystem& energy_system_;

public:
    EvolutionManager(World& world, EnergySystem& energy_system):world_(world), energy_system_(energy_system) {}

    void process_falling();
    void process_growth();
};