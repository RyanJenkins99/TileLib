//
// Created by ryanj on 09/11/2022.
//

//player.h
#pragma once
#include "Entity.h"

class Player : public Entity {
private:
    float _speed;

public:
    void Update(double dt) override;
    Player();
    void Render(sf::RenderWindow &window) const override;
};
