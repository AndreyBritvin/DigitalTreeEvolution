#pragma once
#include "Tree.hpp"

enum Cell_state 
{
    EMPTY, 
    WOOD,
    GROWING, 
    FALLING
};

class Cell
{
private:
    // TODO: think about struct location
    int x_ = 0;
    int y_ = 0;
    int active_gen_ = 0;
    int energy_ = 0;
    int state_ = 0;
    Tree& tree;

public:
    Cell(int x, int y, int active_gene, Tree& tree, int state): x_(x), y_(y), state_(state), active_gen_(active_gene), tree(tree) {};

    auto get_x() {return x_;};
    auto get_y() {return y_;};
    auto get_tree() {return tree;};
    auto get_state() {return state_;};
    auto get_energy() {return energy_;}
    auto set_energy(int energy) {energy_ = energy;}
    auto set_state(int state) {state_ = state;};
    auto get_active_gene() {return active_gen_;};
    bool has_enough_energy() {return energy_ >= ENERGY_THRESHOLD;}
};