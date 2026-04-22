#include "Simulation.hpp"

void Simulation::step()
{
    ES_.distribute_sun_energy();
    EV_.process_growth();
    // process falling
    // process aging
    // should consume energy be here?, maybe for tree as whole part
    
    //TODO: add counter for generation (every 90 years)

    //TODO: check extinction
}