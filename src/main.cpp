#include <SFML/Graphics.hpp>
#include <iostream>
#include "Config.hpp"
#include "Tree.hpp"
#include "Cell.hpp"
#include "Genome.hpp"
#include "Renderer.hpp"
#include "World.hpp"
#include <array>

using namespace std;

int main()
{
    array<uint8_t, GENOME_SIZE> test_gen_seq = { 1, 2,  3,  0, 
                                                15, 0, 15, 15};
    Genome gen_test;
    gen_test.set_gene(test_gen_seq);
    cout << gen_test << endl;

    tree_color color = {128, 128, 128};
    Tree test_tree(color, gen_test, 1, 0);

    World world;
    world.create_cell(10, 10, 0, test_tree, GROWING);
    cout << "Cell count is " << world.cell_count() << endl;
    cout << "Cell`s genome at 50 50 is " << world.get_cell_at(10, 10)->get_tree().get_genome() << endl;


    sf::RenderWindow window(sf::VideoMode(1600, 800), "Digital Trees");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(60);
    
    Renderer rend(window, world);

    while (window.isOpen())
    {
        rend.handle_event();
        window.clear(sf::Color(30, 30, 30));    
        rend.render_world();
        //rend.render_UI();
        rend.render_overlays();        
        window.display();
    }

    return 0;
}


