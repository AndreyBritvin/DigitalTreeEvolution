#include "Renderer.hpp"
#include "Cell.hpp"
#include <SFML/Graphics.hpp>

sf::Color Renderer::get_cell_color(Cell* cell)
{
    tree_color color = cell->get_tree().get_color();
    if (cell->get_state() == GROWING) 
    {
        return sf::Color::White;
    }

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

int Renderer::calc_opt_cell_size()
{
    sf::Vector2u windowSize = window_.getSize();
    
    int maxWidth =  (windowSize.x - 2 * MARGIN) / WORLD_WIDTH;
    int maxHeight = (windowSize.y - 2 * MARGIN /*- UI_HEIGHT*/) / WORLD_HEIGHT;
    
    return std::min(maxWidth, maxHeight);
}

void Renderer::render_overlays()
{
    for (int x = 0; x < WORLD_WIDTH; ++x) {
        for (int y = 0; y < WORLD_HEIGHT; ++y) {

            Cell* cell = world_.get_cell_at(x, y);
            if (!cell || cell->get_state() == DEAD) continue;
            
            Tree& tree = cell->get_tree();
            
            //center of cell
            float px = MARGIN + x * CELL_SIZE + CELL_SIZE / 2.0f;
            float py = MARGIN + (WORLD_HEIGHT - 1 - y) * CELL_SIZE + CELL_SIZE / 2.0f;

            sf::Text text;
            text.setFont(font_);
            text.setCharacterSize(std::max(8, CELL_SIZE - 2)); 
            text.setFillColor(sf::Color::Red);

            if (show_Age_overlay_)
            {   // TODO: make function
                text.setString(std::to_string(tree.get_age()));
                text.setPosition(px - text.getLocalBounds().width / 2, 
                                py - text.getLocalBounds().height / 2);
                window_.draw(text);
            }
            if (show_Energy_overlay_) 
            {
                // int energy = (cell->state() =='' Cell::GROWING) ? 
                            // cell->energy() : tree.get_energy();
                int energy = cell->get_energy();
                text.setString(std::to_string(energy));
                text.setPosition(px - text.getLocalBounds().width / 2, 
                                py - text.getLocalBounds().height / 2);
                window_.draw(text);
            }
            
            if (show_Id_overlay_) 
            {
                text.setString(std::to_string(tree.get_id()));
                text.setPosition(px - text.getLocalBounds().width / 2, 
                                py - text.getLocalBounds().height / 2);
                window_.draw(text);
            }
            if (show_Gene_overlay_)
            {
                text.setString(std::to_string(cell->get_active_gene()));
                text.setPosition(px - text.getLocalBounds().width / 2, 
                                py - text.getLocalBounds().height / 2);
                window_.draw(text);
            }
        }
    }
}

void Renderer::handle_event()
{
    sf::Event event;
    while (window_.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) window_.close();
        else if (event.type == sf::Event::Resized) {CELL_SIZE = calc_opt_cell_size();}
        else if (event.type == sf::Event::KeyPressed) {
            // if (event.key.code == sf::Keyboard::Space) {
            //     paused_ = !paused_;
            //} 
            if (event.key.code == sf::Keyboard::A) {
                show_Age_overlay_ = !show_Age_overlay_;
            } 
            else if (event.key.code == sf::Keyboard::E) {
                show_Energy_overlay_ = !show_Energy_overlay_;
            } 
            else if (event.key.code == sf::Keyboard::I) {
                show_Id_overlay_ = !show_Id_overlay_;
            } 
            else if (event.key.code == sf::Keyboard::G) {
                show_Gene_overlay_ = !show_Gene_overlay_;
            } 
            else if (event.key.code == sf::Keyboard::N) {//next
                sim_.step();
            } 
            else if (event.key.code == sf::Keyboard::Escape) {
                window_.close();
            }
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left) {
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;
                handle_cell_click(x, y);
            }
        }
    }
}

void Renderer::handle_cell_click(int mouseX, int mouseY) {
    int cellX = (mouseX - MARGIN) / CELL_SIZE;
    int cellY = WORLD_HEIGHT - 1 - (mouseY - MARGIN) / CELL_SIZE;
    
    if (cellX < 0 || cellX >= WORLD_WIDTH || cellY < 0 || cellY >= WORLD_HEIGHT) {
        return;
    }
    
    Cell* cell = world_.get_cell_at(cellX, cellY);
    if (!cell || cell->get_state() == EMPTY) {
        std::cout << "Empty cell at (" << cellX << ", " << cellY << ")" << std::endl;
        return;
    }
    
    std::cout << *cell << std::endl;
}