#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Create a window with SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear the window with a color
        window.clear(sf::Color::Blue);

        // Display the contents of the window
        window.display();
    }

    std::cout << "SFML is working correctly!" << std::endl;
    return 0;
}