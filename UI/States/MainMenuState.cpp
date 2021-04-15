//
// Created by Luka Mitrović on 04/04/2021.
//

#include "MainMenuState.h"
#include <sstream>
#include "../DEFINITIONS.h"
#include "../States/TableMenuState.h"

#include <iostream>

namespace lm{
    MainMenuState::MainMenuState(AppDataRef data) : _data(data){

    }

    void MainMenuState::Init() {
        this->_data->assets.LoadTexture("Array Button", "UI/Resourses/Buttons/ARRAY.jpg");
        this->_data->assets.LoadTexture("List Button", "UI/Resourses/Buttons/LIST.png");
        this->_data->assets.LoadTexture("Heap Button", "UI/Resourses/Buttons/HEAP.png");
        this->_data->assets.LoadTexture("RBTree Button", "UI/Resourses/Buttons/RB-TREE.png");
        this->_data->assets.LoadTexture("AVLTree Button", "UI/Resourses/Buttons/AVL-TREE.png");

        this->_arrayButton.setTexture(this->_data->assets.GetTexture("Array Button"));
        this->_listButton.setTexture(this->_data->assets.GetTexture("List Button"));
        this->_heapButton.setTexture(this->_data->assets.GetTexture("Heap Button"));
        this->_rbTreeButton.setTexture(this->_data->assets.GetTexture("RBTree Button"));
        this->_avlTreeButton.setTexture(this->_data->assets.GetTexture("AVLTree Button"));

        this->_arrayButton.setPosition(340,70);
        this->_listButton.setPosition(340,260);
        this->_heapButton.setPosition(340,400);
        this->_rbTreeButton.setPosition(700,400);
        this->_avlTreeButton.setPosition(970,400);

        this->_data->assets.LoadTexture("Array Graph", "UI/Resourses/Graphics/array_graphical.png");
        this->_data->assets.LoadTexture("List Graph", "UI/Resourses/Graphics/list_graphical.png");
        this->_data->assets.LoadTexture("Heap Graph", "UI/Resourses/Graphics/heap_graphical.png");
        this->_data->assets.LoadTexture("RBTree Graph", "UI/Resourses/Graphics/rb_graphical.jpg");

        this->_arrayGraph.setTexture(this->_data->assets.GetTexture("Array Graph"));
        this->_listGraph.setTexture(this->_data->assets.GetTexture("List Graph"));
        this->_heapGraph.setTexture(this->_data->assets.GetTexture("Heap Graph"));
        this->_rbTreeGraph.setTexture(this->_data->assets.GetTexture("RBTree Graph"));

        this->_arrayGraph.setPosition(650,70);
        this->_listGraph.setPosition(615,260);
        this->_heapGraph.setPosition(340,520);
        this->_rbTreeGraph.setPosition(815,520);

        this->_listGraph.scale(0.8,1);
        this->_heapGraph.scale(0.8,0.8);
        this->_rbTreeGraph.scale(0.3,0.3);


        this->_data->assets.LoadTexture("Load File Button", "UI/Resourses/Buttons/LOAD-FILE_purple.png");
        this->_data->assets.LoadTexture("About Button", "UI/Resourses/Buttons/ABOUT.png");
        this->_data->assets.LoadTexture("Settings Button", "UI/Resourses/Buttons/SETTINGS.png");
        this->_data->assets.LoadTexture("Exit Button", "UI/Resourses/Buttons/EXIT.png");

        this->_loadFileButton.setTexture(this->_data->assets.GetTexture("Load File Button"));
        this->_aboutButton.setTexture(this->_data->assets.GetTexture("About Button"));
        this->_settingsButton.setTexture(this->_data->assets.GetTexture("Settings Button"));
        this->_exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));

        this->_loadFileButton.setPosition(25,70);
        this->_aboutButton.setPosition(25,230);
        this->_settingsButton.setPosition(25,390);
        this->_exitButton.setPosition(25,550);

        this->_leftField.setSize(sf::Vector2f(340,800));
        this->_leftField.setFillColor(sf::Color(32,41,46));





    }

    void MainMenuState::HandleInput() {
        sf::Event event;
        while (this->_data->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                this->_data->window.close();
            }
            if(this->_data->input.IsSpriteClicked(this->_arrayButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "go to array screen" << std::endl;
                _data->machine.AddState(StateRef (new TableMenuState(this->_data)),true);
            }
            if(this->_data->input.IsSpriteClicked(this->_listButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "go to list screen" << std::endl;
            }
            if(this->_data->input.IsSpriteClicked(this->_heapButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "go to heap screen" << std::endl;
            }
            if(this->_data->input.IsSpriteClicked(this->_rbTreeButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "go to rbtree screen" << std::endl;
            }
            if(this->_data->input.IsSpriteClicked(this->_avlTreeButton,sf::Mouse::Left,this->_data->window)){
                std::cout << "go to avl screen" << std::endl;
            }
        }
    }
    void MainMenuState::Draw(float dt) {
        this->_data->window.clear(sf::Color(46, 64, 75));
        this->_data->window.draw(this->_leftField);
        this->_data->window.draw(this->_arrayButton);
        this->_data->window.draw(this->_heapButton);
        this->_data->window.draw(this->_listButton);
        this->_data->window.draw(this->_rbTreeButton);
        this->_data->window.draw(this->_avlTreeButton);

        this->_data->window.draw(this->_loadFileButton);
        this->_data->window.draw(this->_aboutButton);
        this->_data->window.draw(this->_settingsButton);
        this->_data->window.draw(this->_exitButton);

        this->_data->window.draw(this->_arrayGraph);
        this->_data->window.draw(this->_listGraph);
        this->_data->window.draw(this->_heapGraph);
        this->_data->window.draw(this->_rbTreeGraph);
        this->_data->window.display();
    }
}