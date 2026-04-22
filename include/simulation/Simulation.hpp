#include "Config.hpp"
#include "World.hpp"
#include "EnergySystem.hpp"
#include "EvolutionManager.hpp"

class Simulation
{
private:
    World& world_;
    EnergySystem& ES_;
    EvolutionManager& EV_;

public:
    Simulation(World& world, EnergySystem& ES, EvolutionManager& EV) 
    : world_(world), ES_(ES), EV_(EV) {}
    
    void step();
    
    void create_initial_population();

};