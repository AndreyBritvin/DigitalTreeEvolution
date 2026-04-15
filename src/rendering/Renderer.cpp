#include "Renderer.hpp"
#include "Cell.hpp"
#include <SFML/Graphics.hpp>

sf::Color Renderer::get_cell_color(Cell* cell)
{
    tree_color color = cell->get_tree().get_color();
    
    return sf::Color(color.r, color.g, color.b); // TODO: make dependency on type
}

void Renderer::render_world()
{
    for (int x = 0; x < WORLD_WIDTH; x++) 
    {
        for (int y = 0; y < WORLD_HEIGHT; y++) 
        {
            auto cell = world_.get_cell_at(x, y);
            if (!cell || cell->get_state() == DEAD) continue;

            float px = MARGIN + x * CELL_SIZE;
            float py = MARGIN + (WORLD_HEIGHT - 1 - y) * CELL_SIZE;
            
            sf::RectangleShape rect(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            rect.setPosition(px, py);
            rect.setFillColor(get_cell_color(cell));
            rect.setOutlineColor(sf::Color(50, 50, 50));
            rect.setOutlineThickness(0.5f);
            window_.draw(rect);
        } 
    }
}