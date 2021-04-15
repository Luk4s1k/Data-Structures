//
// Created by Luka Mitrović on 04/04/2021.
//

#ifndef SFMLTUTOR_APP_H
#define SFMLTUTOR_APP_H

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "Managers/StateMachine.h"
#include "Managers/AssetManager.h"
#include "Managers/InputManager.h"
namespace lm{
    struct AppData{
        StateMachine machine;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager input;
        std::string buffer;
    };

    typedef std::shared_ptr<AppData> AppDataRef;

    class App {
    public:
        App(int width, int height, std::string title);
    private:
        const float dt = 1.0f / 60.0f;

        sf::Clock _clock;

        AppDataRef _data = std::make_shared<AppData>();

        void Run();




    };

}


#endif //SFMLTUTOR_APP_H
