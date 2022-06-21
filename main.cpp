#include <SFML/Graphics.hpp>

int main(){

    float winwidth = 400;
    float winheight = 300;

    sf::RenderWindow Window(sf::VideoMode(winwidth,winheight), "Walk");

    sf::Texture texture;
    texture.loadFromFile("man.png");

    sf::IntRect rectSourceSprite(0,0,90,185);
    sf::Sprite sprite(texture, rectSourceSprite);

    sf::Clock clock;

    while(Window.isOpen()){
        sf::Event event;
        while (Window.pollEvent(event)){
            if(event.type == sf::Event::EventType::Closed)
                Window.close();
        }

        if (clock.getElapsedTime().asSeconds() > 0.1f){
            if(rectSourceSprite.left == 1200)
                rectSourceSprite.left = 0;
            else
                rectSourceSprite.left+= 100;

            sprite.setTextureRect(rectSourceSprite);
            clock.restart();
        }

        Window.clear();
        Window.draw(sprite);
        Window.display();

    }
}
