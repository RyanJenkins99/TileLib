#include <iostream>
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "Entity.h"
#include "Player.h"
#include "../lib_tile_level_loader/levelSystem.h"


using namespace std;
using namespace sf;

Player* player= new Player;

void Render(RenderWindow &window) {
    player->Render(window);
    ls::Render(window);
}

void load() {
    ls::loadLevelFile("src/maze.txt");

    // Print the level to the console
    for (size_t y = 0; y < ls::getHeight(); ++y) {
        for (size_t x = 0; x < ls::getWidth(); ++x) {
            cout << ls::getTile({x, y});
        }
        cout << endl;
    }
}

void Update(RenderWindow &window) {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
            return;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }
    static Clock clock;
    float dt = clock.restart().asSeconds();
    player ->Update(dt);

}
int main()
{

    RenderWindow window(VideoMode(500, 500), "SPACE INVADERS");
    //Load();

    while (window.isOpen()) {
        window.clear();
        Update(window);
        Render(window);
        window.display();
    }
    return 0;

}



