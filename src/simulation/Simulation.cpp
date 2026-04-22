#include "Simulation.hpp"

void Simulation::step()
{
    ES_.distribute_sun_energy();
    EV_.process_growth();
    EV_.process_falling();
    // process falling
    // process aging // TODO: here kill the tree
    // should consume energy be here?, maybe for tree as whole part
    
    year_++;
    if (year_ % AVERAGE_AGE == 0)
    {
        generation_++;
        year_ = 0;
        world_.kill_trees();
    }

    //TODO: check extinction
}