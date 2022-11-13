//
// Created by ryanj on 09/11/2022.
//

//player.cpp
#include "Player.h"
using namespace sf;
using namespace std;

const Keyboard::Key controls[4] = {
        Keyboard::A,   // Player1 UP
        Keyboard::D,   // Player1 Down
        Keyboard::W,
        Keyboard::S,
};

void Player::Update(double dt) {
    //Move in four directions based on keys
    float directionX = 0.0f;
    float directionY = 0.0f;
    if (Keyboard::isKeyPressed(controls[0])) {
        if(getPosition().x > 50)
            directionX--;
    }
    if (Keyboard::isKeyPressed(controls[1])) {
        if(getPosition().x < 445)
            directionX++;
    }
    if (Keyboard::isKeyPressed(controls[2])) {
        if(getPosition().y > 45)
            directionY--;
    }
    if (Keyboard::isKeyPressed(controls[3])) {
        if(getPosition().y < 450)
            directionY++;
    }

    move(Vector2f(directionX*_speed*dt,directionY*_speed*dt));
    Entity::Update(dt);
}

Player::Player()
        : _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) {
    _shape->setFillColor(Color::Green);
    _shape->setOrigin(Vector2f(25.f, 25.f));
}

void Player::Render(sf::RenderWindow &window) const {
    window.draw(*_shape);
}