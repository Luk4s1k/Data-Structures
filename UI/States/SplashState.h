//
// Created by Luka Mitrović on 04/04/2021.
//

#ifndef SFMLTUTOR_SPLASHSTATE_H
#define SFMLTUTOR_SPLASHSTATE_H
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "../Managers/State.h"

#include "../App.h"
#include "../DEFINITIONS.h"

namespace lm{
    class SplashState : public State{
    public:
        SplashState(AppDataRef data);

        void Init() ;
        // Can be added Pause and Resume methods

        void HandleInput() ;
        void Update(float dt) ;
        void Draw(float dt) ;

        StateRef &GetActiveState();


    private:
        AppDataRef _data;
        sf::Clock _clock;

        sf::Sprite _background;




    };
}







#endif //SFMLTUTOR_SPLASHSTATE_H
