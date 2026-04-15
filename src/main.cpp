#include <SFML/Graphics.hpp>
#include <iostream>
#include "Config.hpp"
#include "Tree.hpp"
#include "Cell.hpp"
#include "Genome.hpp"
#include "World.hpp"
#include <array>

using namespace std;

int main()
{
    array<uint8_t, GENOME_SIZE> test_gen_seq = {1, 2, 3, 0, 15, 0, 15, 15};
    Genome gen_test;
    gen_test.set_gene(test_gen_seq);
    cout << gen_test << endl;

    tree_color color = {128, 128, 128};
    Tree test_tree(color, gen_test, 1, 0);

    World world;
    world.create_cell(50, 50, 0, test_tree, GROWING);
    cout << "Cell count is " << world.cell_count() << endl;
    cout << "Cell`s genome at 50 50 is " << world.get_cell(50, 50)->get_tree().get_genome() << endl;

    // sf::RenderWindow window(sf::VideoMode(1024, 400), "Digital Trees");
    // window.setVerticalSyncEnabled(false);
    // window.setFramerateLimit(60);
    
    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed) window.close();
    //     }

    //     window.clear(sf::Color(30, 30, 30));
        
    //     for (int x = 0; x < 256; x++) 
    //     {
    //         for (int y = 0; y < 100; y++) 
    //         {
    //             sf::RectangleShape cell(sf::Vector2f(4, 4));
    //             cell.setPosition(10 + x * 4, 10 + (99 - y) * 4); 
    //             cell.setFillColor(sf::Color(50, 50, 50)); // заполнение клетки
    //             cell.setOutlineColor(sf::Color(200, 30, 30)); // разграничение клеток
    //             cell.setOutlineThickness(1.0f);
    //             window.draw(cell);
    //         } 
    //     }
        
    //     window.display();
        
    // }

    return 0;
}


