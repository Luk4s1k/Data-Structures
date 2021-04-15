//
// Created by Luka Mitrović on 04/04/2021.
//

#ifndef SFMLTUTOR_INPUTMANAGER_H
#define SFMLTUTOR_INPUTMANAGER_H
#include <SFML/Graphics.hpp>
namespace lm{
    class InputManager {
    public:
        InputManager(){}
        ~InputManager(){}

        bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
        sf::Vector2i GetMousePosition(sf::RenderWindow &window);

    };
}



#endif //SFMLTUTOR_INPUTMANAGER_H
