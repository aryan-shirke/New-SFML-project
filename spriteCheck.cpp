// Demonstrate creating a spritesheet
#include "SFML/Graphics.hpp"

int main(int argc, char ** argv){
  sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo Game");

  sf::Event event;
  sf::Texture texture;
  texture.loadFromFile("man.png");

  sf::Sprite sprite(texture,sf::IntRect(0,0,85,200));


  while (renderWindow.isOpen()){
    while (renderWindow.pollEvent(event)){
      if (event.type == sf::Event::EventType::Closed)
        renderWindow.close();
    }

    renderWindow.clear();
    renderWindow.draw(sprite);
    renderWindow.display();
  }
}
