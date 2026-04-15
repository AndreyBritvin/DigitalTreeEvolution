#pragma once
#include "Tree.hpp"

enum Cell_state 
{
    EMPTY, 
    BARK,
    GROWING, 
    FALLING
};

class Cell
{
private:
    int x_ = 0;
    int y_ = 0;
    int active_gen_ = 0;
    int energy_ = 0;
    int state_ = 0;
    Tree& tree;

public:
    Cell(int x, int y, int active_gene, Tree& tree, int state): x_(x), y_(y), state_(state), active_gen_(active_gene), tree(tree) {};

    auto get_tree() {return tree;};
    
};