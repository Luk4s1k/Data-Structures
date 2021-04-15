//
// Created by Luka Mitrović on 13/04/2021.
//

#ifndef SFMLTUTOR_INPUTSTATE_H
#define SFMLTUTOR_INPUTSTATE_H
#include <SFML/Graphics.hpp>
#include "../Managers/State.h"
#include "../App.h"

namespace lm{
class InputState : public State {
public:
    InputState(AppDataRef data);

    void Init() ;
    void HandleInput();
    void Update(float dt){}
    void Draw(float dt);
private:

    AppDataRef _data;
    sf::Sprite _OKButton;
    sf::Sprite _CancelButton;
    sf::Text inputText;
    sf::String inputString;
    sf::RectangleShape InputField;
    sf::Font font;

};

}


#endif //SFMLTUTOR_INPUTSTATE_H
