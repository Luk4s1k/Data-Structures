//
// Created by Luka Mitrović on 05/04/2021.
//

#ifndef SFMLTUTOR_TABLEMENUSTATE_H
#define SFMLTUTOR_TABLEMENUSTATE_H

#include "../Managers/State.h"
#include "../App.h"
#include "../../Structures/Table/Array.h"
namespace lm{
    class TableMenuState : public State{
    public:
        enum FunctionCall{
            NONE,
            CREATE,
            PUSH,
            PUSH_FRONT,
            PUSH_BACK,
            POP,
            POP_FRONT,
            POP_BACK,
            FIND

        };

        TableMenuState(AppDataRef data);

        void Init() ;
        void HandleInput();
        void Update();
        void Draw(float dt);
        void printTable(Array &arrayToPrint);

    private:
        AppDataRef _data;
        Array array  = Array(5);

        FunctionCall funCall;

        sf::Sprite _pushButton;
        sf::Sprite _pushFrontButton;
        sf::Sprite _pushBackButton;

        sf::Sprite _popButton;
        sf::Sprite _popFrontButton;
        sf::Sprite _popBackButton;

        sf::Sprite _findButton;
        sf::Sprite _menuButton;

        sf::Sprite _createButton;
        sf::Sprite _printButton;
        sf::Sprite _updateButton;

        sf::RectangleShape _leftField;

        sf::Text outPutTableText;
        sf::String outPutString;
        sf::Font _font;



    };

}

#endif //SFMLTUTOR_TABLEMENUSTATE_H
