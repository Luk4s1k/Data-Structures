//
// Created by Luka Mitrović on 04/04/2021.
//

#ifndef SFMLTUTOR_MAINMENUSTATE_H
#define SFMLTUTOR_MAINMENUSTATE_H
#include <SFML/Graphics.hpp>
#include "../Managers/State.h"
#include "../App.h"

namespace lm{
    class MainMenuState : public State {
    public:
        MainMenuState(AppDataRef data);

        void Init() ;
        void HandleInput();
        void Update(float dt){}
        void Draw(float dt);
        StateRef TableRef;

    private:
        AppDataRef _data;
        sf::Sprite _arrayButton;
        sf::Sprite _listButton;
        sf::Sprite _heapButton;
        sf::Sprite _rbTreeButton;
        sf::Sprite _avlTreeButton;

        sf::Sprite _loadFileButton;
        sf::Sprite _aboutButton;
        sf::Sprite _settingsButton;
        sf::Sprite _exitButton;

        sf::Sprite _arrayGraph;
        sf::Sprite _listGraph;
        sf::Sprite _heapGraph;
        sf::Sprite _rbTreeGraph;

        sf::RectangleShape _leftField;

    };

}


#endif //SFMLTUTOR_MAINMENUSTATE_H
