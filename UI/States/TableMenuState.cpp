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

        this->_pushButton.setPosition(25,20);
        this->_pushFrontButton.setPosition(20,100);
        this->_pushBackButton.setPosition(20,180);
        this->_popButton.setPosition(20,260);
        this->_popFrontButton.setPosition(20,340);
        this->_popBackButton.setPosition(20,420);
        this->_findButton.setPosition(20,500);
        this->_menuButton.setPosition(20,580);
        this->_createButton.setPosition(950,650);
        this->_printButton.setPosition(750,650);

        this->_leftField.setSize(sf::Vector2f(340,800));
        this->_leftField.setFillColor(sf::Color(32,41,46));
    }

    void TableMenuState::HandleInput() {
        sf::Event event;
        while (this->_data->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                this->_data->window.close();
            }
            if(this->_data->input.IsSpriteClicked(this->_pushButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "make push function" << std::endl;
                int i;
                std::istringstream(this->_data->buffer) >> i;
                this->_data->buffer.clear();
                this->array.push(i,0);
                //this->_data->machine.RemoveState();
                _data->machine.AddState(StateRef (new InputState(this->_data)),false);


            }
            if(this->_data->input.IsSpriteClicked(this->_pushFrontButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "make push front button" << std::endl;
            }
            if(this->_data->input.IsSpriteClicked(this->_pushBackButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "make push back" << std::endl;
            }
            if(this->_data->input.IsSpriteClicked(this->_popButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "make pop function" << std::endl;
            }
            if(this->_data->input.IsSpriteClicked(this->_popFrontButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "make pop front button" << std::endl;
            }
            if(this->_data->input.IsSpriteClicked(this->_popBackButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "make pop back" << std::endl;
            }
            if(this->_data->input.IsSpriteClicked(this->_createButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "create table pushed" << std::endl;
            }
            if(this->_data->input.IsSpriteClicked(this->_printButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "print table pushed" << std::endl;
                printTable(this->array);
                std::cout << "Array values:" << this->array.outPutString() << std::endl;

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
        this->_data->window.draw(this->outPutTableText);


        this->_data->window.display();
    }

    void TableMenuState::printTable(Array &arrayToPrint)  {
        this->outPutString += this->array.outPutString();
        this->outPutTableText.setString(this->outPutString);
    }


}

