#pragma once
#include "Config.hpp"
#include "World.hpp"
#include "Tree.hpp"
#include <SFML/Graphics.hpp>

class Renderer
{
private:
    sf::Font font_;
    sf::RenderWindow& window_;
    World& world_;
    int CELL_SIZE = 5;
    int MARGIN = 10;

    bool show_Age_overlay_ = false;
    bool show_Energy_overlay_ = false;
    bool show_Id_overlay_ = false;

public:
    Renderer(sf::RenderWindow& window, World& world): world_(world), window_(window) 
    {
        if (!font_.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf") &&
        !font_.loadFromFile("/System/Library/Fonts/SFNS.ttf") &&
        !font_.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        std::cerr << "Warning: Could not load font!" << std::endl;
        }
    };
    
    sf::Color get_cell_color(Cell* cell);
    
    void render_world();
    void render_overlays();

    void handle_event();
    int  calc_opt_cell_size();
};