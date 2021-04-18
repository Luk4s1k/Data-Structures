//
// Created by Luka Mitrović on 04/04/2021.
//

#include "App.h"
#include "States/MainMenuState.h"
#include "States/TableMenuState.h"
#include "States/InputState.h"
#include "DEFINITIONS.h"

namespace lm{
    App::App(int width, int height, std::string title) {

        _data->assets.LoadFont("Gilroy Font", GILROY_FONT_PATH);
        _data->window.create(sf::VideoMode(width,height),title, sf::Style::Close | sf::Style::Titlebar);

        _data->machine.AddState(StateRef (new MainMenuState(this->_data)),false);

        this->Run();
    }

    void App::Run() {
        float newTime, frameTime, interpolation;

        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while (this->_data->window.isOpen()){
            this->_data->machine.ProcessStateChanges();
            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if(frameTime > 0.25f){
                frameTime = 0.25f;

            }
            currentTime = newTime;
            accumulator += frameTime;

            while(accumulator >= dt){
                this->_data->machine.GetActiveState()->HandleInput();
                this->_data->machine.GetActiveState()->Update();

                accumulator -= dt;
            }
            interpolation = accumulator / dt;
            this->_data->machine.GetActiveState()->Draw(interpolation);
        }
    }
}

