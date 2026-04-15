#pragma once
#include "Genome.hpp"

enum Tree_state {DEAD, ALIVE};

struct tree_color
{
    int r;
    int g;
    int b;
};

class Tree
{
private:
    tree_color color_;
    Genome gene_;
    unsigned long id_;
    int age_;
    
public:
    Tree(tree_color color, Genome gene, unsigned long id, int age)
    : color_(color), gene_(gene), id_(id), age_(age){};
    
    auto get_genome() {return gene_;};
};