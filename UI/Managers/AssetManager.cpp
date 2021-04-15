//
// Created by Luka Mitrović on 04/04/2021.
//

#include "AssetManager.h"
namespace lm{
    void AssetManager::LoadTexture(std::string name, std::string fileName) {
        sf::Texture texture;
        if(texture.loadFromFile(fileName)){
            this->_textures[name] = texture;
        }


    }

    sf::Texture &AssetManager::GetTexture(std::string name) {
        return this->_textures.at(name);
    }

    void AssetManager::LoadFont(std::string name, std::string fileName) {
        sf::Font font;
        if(font.loadFromFile(fileName)){
            this->_fonts[name] = font;
        }


    }

    sf::Font &AssetManager::GetFont(std::string name) {
        return this->_fonts.at(name);
    }
}
