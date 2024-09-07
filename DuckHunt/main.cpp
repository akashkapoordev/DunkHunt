#include <SFML/Graphics.hpp>
#include "../../Header/GameService/GameService.h"

using namespace GameService;

int main()
{
    GameServce* game_service = new GameServce();

    game_service->ignite();
    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    } 

    return 0;
}
//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//int main() {
//    // Create a window
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Background Example");
//
//    // Load the image into a texture
//    sf::Texture backgroundTexture;
//    if (!backgroundTexture.loadFromFile("assets/Texture/Background.png")) {
//        std::cerr << "Error loading texture" << std::endl;
//        return -1;
//    }
//
//    // Create a sprite to display the texture
//    sf::Sprite backgroundSprite;
//    backgroundSprite.setTexture(backgroundTexture);
//
//    // Set the texture rect to use only a portion of the image
//    // For example, let's use the top left section (assume each section is 256x256)
//    backgroundSprite.setTextureRect(sf::IntRect(0, 0, 256, 190)); // Adjust these values to fit your needs
//
//    // Scale the sprite to fit the window size if needed
//    backgroundSprite.setScale(
//        window.getSize().x / float(backgroundSprite.getTextureRect().width),
//        window.getSize().y / float(backgroundSprite.getTextureRect().height)
//    );
//
//    // Main loop
//    while (window.isOpen()) {
//        // Process events
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        // Clear the window
//        window.clear();
//
//        // Draw the background sprite
//        window.draw(backgroundSprite);
//
//        // Display the contents of the window
//        window.display();
//    }
//
//    return 0;
//}

