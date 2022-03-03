#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>
#include <SFML/Graphics.hpp>

class TextureLoader
{
public: //Loading textures
    void load(int id, const std::string& filename);

    sf::Texture& get(int id);
    const sf::Texture& get(int id) const;

private: //Storing stuff
    std::map<int, std::unique_ptr<sf::Texture>> mTextureMap;

};

