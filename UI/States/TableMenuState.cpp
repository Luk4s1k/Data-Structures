//
// Created by Luka Mitrović on 05/04/2021.
//

#include "TableMenuState.h"
#include <iostream>
#include "../States/InputState.h"
#include <sstream>
namespace lm{
    TableMenuState::TableMenuState(lm::AppDataRef data):_data(data) {}

    void TableMenuState::Init() {

        //this->array = Array(5);//this->getFileSize(sourceFile)
        this->_data->assets.LoadTexture("Push Button", "UI/Resourses/Buttons/PUSH.png");
        this->_data->assets.LoadTexture("Push Front Button", "UI/Resourses/Buttons/PUSH-FRONT.png");
        this->_data->assets.LoadTexture("Push Back Button", "UI/Resourses/Buttons/PUSH-BACK.png");
        this->_data->assets.LoadTexture("Pop Button", "UI/Resourses/Buttons/POP.png");
        this->_data->assets.LoadTexture("Pop Front Button", "UI/Resourses/Buttons/POP-FRONT.png");
        this->_data->assets.LoadTexture("Pop Back Button", "UI/Resourses/Buttons/POP-BACK.png");
        this->_data->assets.LoadTexture("Find Button", "UI/Resourses/Buttons/FIND.png");
        this->_data->assets.LoadTexture("Menu Button", "UI/Resourses/Buttons/MENU.png");
        this->_data->assets.LoadTexture("Create Button", "UI/Resourses/Buttons/CREATE-BUTTON.png");
        this->_data->assets.LoadTexture("Print Button", "UI/Resourses/Buttons/PRINT-BUTTON.png");
        this->_data->assets.LoadTexture("Update Button", "UI/Resourses/Buttons/UPDATE-BUTTON.png");

        this->_pushButton.setTexture(this->_data->assets.GetTexture("Push Button"));
        this->_pushFrontButton.setTexture(this->_data->assets.GetTexture("Push Front Button"));
        this->_pushBackButton.setTexture(this->_data->assets.GetTexture("Push Back Button"));
        this->_popButton.setTexture(this->_data->assets.GetTexture("Pop Button"));
        this->_popFrontButton.setTexture(this->_data->assets.GetTexture("Pop Front Button"));
        this->_popBackButton.setTexture(this->_data->assets.GetTexture("Pop Back Button"));
        this->_findButton.setTexture(this->_data->assets.GetTexture("Find Button"));
        this->_menuButton.setTexture(this->_data->assets.GetTexture("Menu Button"));
        this->_createButton.setTexture(this->_data->assets.GetTexture("Create Button"));
        this->_printButton.setTexture(this->_data->assets.GetTexture("Print Button"));
        this->_updateButton.setTexture(this->_data->assets.GetTexture("Update Button"));

        this->_pushButton.setPosition(90,50);
        this->_pushFrontButton.setPosition(90,130);
        this->_pushBackButton.setPosition(90,210);
        this->_popButton.setPosition(90,290);
        this->_popFrontButton.setPosition(90,370);
        this->_popBackButton.setPosition(90,450);
        this->_findButton.setPosition(90,530);
        this->_menuButton.setPosition(90,610);
        this->_createButton.setPosition(950,650);
        this->_printButton.setPosition(750,650);
        this->_updateButton.setPosition(550,650);

        this->_leftField.setSize(sf::Vector2f(340,800));
        this->_leftField.setFillColor(sf::Color(32,41,46));

        this->outPutTableText.setFont(this->_font);
        this->outPutTableText.setPosition(sf::Vector2f(630,320) );

        this->_font = this->_data->assets.GetFont("Gilroy Font");
    }

    void TableMenuState::HandleInput() {
        sf::Event event;
        while (this->_data->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                this->_data->window.close();
            }
            if(this->_data->input.IsSpriteClicked(this->_pushButton,sf::Mouse::Left,this->_data->window)){
                this->funCall = PUSH;
                std::cout << "make push function" << std::endl;
                _data->machine.AddState(StateRef (new InputState(this->_data)),false);


            }
            if(this->_data->input.IsSpriteClicked(this->_pushFrontButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "make push front button" << std::endl;
                this->funCall = PUSH_FRONT;
                _data->machine.AddState(StateRef (new InputState(this->_data)),false);
            }
            if(this->_data->input.IsSpriteClicked(this->_pushBackButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "make push back" << std::endl;
                this->funCall = PUSH_BACK;
                _data->machine.AddState(StateRef (new InputState(this->_data)),false);
            }
            if(this->_data->input.IsSpriteClicked(this->_popButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "make pop function" << std::endl;
                this->funCall = POP;
                _data->machine.AddState(StateRef (new InputState(this->_data)),false);
            }
            if(this->_data->input.IsSpriteClicked(this->_popFrontButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "make pop front button" << std::endl;
                this->funCall = POP_FRONT;
                _data->machine.AddState(StateRef (new InputState(this->_data)),false);
            }
            if(this->_data->input.IsSpriteClicked(this->_popBackButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "make pop back" << std::endl;
                this->funCall = POP_BACK;
                _data->machine.AddState(StateRef (new InputState(this->_data)),false);
            }
            if(this->_data->input.IsSpriteClicked(this->_createButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "create table pushed" << std::endl;
            }
            if(this->_data->input.IsSpriteClicked(this->_printButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "print table pushed" << std::endl;
                printTable(this->array);
                std::cout << "Array values:" << this->array.outPutString() << std::endl;

            }
            if(this->_data->input.IsSpriteClicked(this->_updateButton,sf::Mouse::Left,this->_data->window)){
                Update();
            }

        }
    }

    void TableMenuState::Draw(float dt) {
        this->_data->window.clear(sf::Color(46, 64, 75));
        this->_data->window.draw(this->_leftField);
        this->_data->window.draw(this->_pushButton);
        this->_data->window.draw(this->_pushFrontButton);
        this->_data->window.draw(this->_pushBackButton);
        this->_data->window.draw(this->_popButton);
        this->_data->window.draw(this->_popFrontButton);
        this->_data->window.draw(this->_popBackButton);
        this->_data->window.draw(this->_findButton);
        this->_data->window.draw(this->_menuButton);
        this->_data->window.draw(this->_createButton);
        this->_data->window.draw(this->_printButton);
        this->_data->window.draw(this->_updateButton);
        this->_data->window.draw(this->outPutTableText);


        this->_data->window.display();
    }

    void TableMenuState::printTable(Array &arrayToPrint)  {
            //Update();
            this->outPutString = this->array.outPutString();
            this->outPutTableText.setString(this->outPutString);
    }

    void TableMenuState::Update() {
        switch(this->funCall){
            case PUSH:
                // check for empty buffer
                //check dor number of args in buffer

                break;
            case PUSH_FRONT:
                if(!this->_data->buffer.empty()) {
                    int value = NULL;
                    std::istringstream(this->_data->buffer) >> value;
                    std::cout << "Integer value to push front:" << value << std::endl;
                    this->_data->buffer.clear();
                    this->array.push_front(value);
                }
                break;
            case PUSH_BACK:
                if(!this->_data->buffer.empty()) {
                    int value = NULL;
                    std::istringstream(this->_data->buffer) >> value;
                    std::cout << "Integer value to push back:" << value << std::endl;
                    this->_data->buffer.clear();
                    this->array.push_back(value);
                }
                break;
            case POP:
                break;
            case POP_FRONT:
                if(!this->_data->buffer.empty()) {
                    int value = NULL;
                    std::istringstream(this->_data->buffer) >> value;
                    std::cout << "Integer value to pop front:" << value << std::endl;
                    this->_data->buffer.clear();
                    this->array.pop_front(); /// add value
                }
                break;
            case POP_BACK:
                if(!this->_data->buffer.empty()) {
                    int value = NULL;
                    std::istringstream(this->_data->buffer) >> value;
                    std::cout << "Integer value to pop back:" << value << std::endl;
                    this->_data->buffer.clear();
                    this->array.pop_back(); /// add value
                }
                break;
            default:
                break;


        }
    }


}

