//
// Created by Luka Mitrović on 13/04/2021.
//

#include "InputState.h"
#include "TableMenuState.h"
#include "../DEFINITIONS.h"
#include <iostream>
namespace lm{


    InputState::InputState(AppDataRef data):_data(data) {}

    void InputState::Init() {
        this->font = this->_data->assets.GetFont("Gilroy Font");

        this->_data->assets.LoadTexture("OK Button", OK_BUTTON_PATH);
        this->_data->assets.LoadTexture("Cancel Button", CANCEL_BUTTON_PATH);

        this->_OKButton.setTexture(this->_data->assets.GetTexture("OK Button"));
        this->_CancelButton.setTexture(this->_data->assets.GetTexture("Cancel Button"));

        this->_OKButton.setPosition(630,425);
        this->_CancelButton.setPosition(310,425);

        this->InputField.setFillColor(sf::Color(32,41,46));
        this->InputField.setSize(sf::Vector2<float>(600,400));
        this->InputField.setPosition(sf::Vector2<float>(325,200));

        this->inputText.setFont(this->font);
        this->inputText.setPosition(sf::Vector2f(630,320) );



    }

    void InputState::HandleInput() {
        sf::Event event;
        while (this->_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                this->_data->window.close();
            }
            if(event.type == sf::Event::TextEntered) {
                if (event.text.unicode >= 48 && event.text.unicode <= 57) {
                    this->inputText.setPosition(inputText.getPosition().x - 5,inputText.getPosition().y);
                    inputString += event.text.unicode;
                    inputText.setString(inputString);

                }
            }

                if (event.type == sf::Event::KeyPressed){
                    if(event.key.code == sf::Keyboard::BackSpace){
                        std::string newSting = inputText.getString();
                        if(!newSting.empty()){
                            newSting.pop_back();
                        }
                        inputString = newSting;
                        inputText.setString(inputString);
                        this->inputText.setPosition(inputText.getPosition().x + 5,inputText.getPosition().y);

                    }
                    if(event.key.code == sf::Keyboard::Enter){

                        std::cout << "Value in buffer:" << this->_data->buffer << std::endl;
                        this->_data->buffer += inputString;
                        _data->machine.RemoveState();

                    }

                }
            }
            if(this->_data->input.IsSpriteClicked(this->_OKButton,sf::Mouse::Left,this->_data->window)){
                _data->buffer += inputString;
                std::cout << "Value in buffer:" << this->_data->buffer << std::endl;
                this->_data->machine.RemoveState();
                //_data->machine.AddState(StateRef (new TableMenuState(this->_data)),true);
            }
            if(this->_data->input.IsSpriteClicked(this->_CancelButton,sf::Mouse::Left,this->_data->window)){
                _data->buffer.clear();
                this->_data->machine.RemoveState();
//                _data->machine.AddState(StateRef (new TableMenuState(this->_data)),true);
            }
        }



    void InputState::Draw(float dt) {
        this->_data->window.clear(sf::Color(46, 64, 75));
        this->_data->window.draw(this->InputField);
        this->_data->window.draw(this->_OKButton);
        this->_data->window.draw(this->_CancelButton);
        this->_data->window.draw(this->inputText);



        this->_data->window.display();

    }


}
