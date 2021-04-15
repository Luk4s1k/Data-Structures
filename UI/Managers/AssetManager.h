//
// Created by Luka Mitrović on 04/04/2021.
//

#ifndef SFMLTUTOR_ASSETMANAGER_H
#define SFMLTUTOR_ASSETMANAGER_H
#include <map>
#include <SFML/Graphics.hpp>
namespace lm{
    class AssetManager {
    public:
        AssetManager(){}
        ~AssetManager(){}

        void LoadTexture(std::string name , std::string fileName);
        sf::Texture &GetTexture(std::string name);


        void LoadFont(std::string name , std::string fileName);
        sf::Font &GetFont(std::string name);

    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font>    _fonts;
    };

}


#endif //SFMLTUTOR_ASSETMANAGER_H
