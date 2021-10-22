
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "cellcontroller.hpp"
#include "ResourcePath.hpp"

int main(int, char const**)
{
    //reset random generator
    srand(time(NULL));
    
    CellController x;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Epidemy Model");
    window.setFramerateLimit(30);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        x.update();
        window.clear();

        //draw objects
        x.draw(&window);
        x.count_cells();
        //x.print_info();

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
