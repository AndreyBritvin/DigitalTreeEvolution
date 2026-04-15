#pragma once
#include "Config.hpp"
#include "World.hpp"
#include "Tree.hpp"
#include <SFML/Graphics.hpp>

class Renderer
{
private:
    sf::RenderWindow& window_;
    World& world_;
    int CELL_SIZE = 5;
    int MARGIN = 10;

public:
    Renderer(sf::RenderWindow& window, World& world): world_(world), window_(window) {};
    
    sf::Color get_cell_color(Cell* cell);
    void render_world();
};