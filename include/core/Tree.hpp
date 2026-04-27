#pragma once
#include "Genome.hpp"
#include <SFML/Graphics.hpp>

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
    int age_;
    inline static int free_id_ = 0;
    unsigned int id_;

public:
    
    int energy = 0;
    
    Tree(tree_color color, Genome gene, unsigned long id, int age)
    : color_(color), gene_(gene), age_(age){};
    
    auto get_genome() {return gene_;};
    auto get_color() {return color_;};
    auto get_age() {return age_;};
    static int get_free_id() {return free_id_;};
    int get_id() {return id_;};
    void set_genome(Genome& gene) {gene_ = gene;}
    void add_id() {id_ = free_id_++;}
};