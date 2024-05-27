#pragma once
#include <SFML/Graphics.hpp>
#include "Collidable.h"

//un item es igual a un enemy

class Enemy: public sf::Drawable, public Collidable
{
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Vector2f _speed;
	int _timeRespawn;
	sf::Vector2f _newPosition;
public:
	Enemy();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override; 
	void respawn();
	sf::FloatRect getBounds() const override;
	void youDamaged();
};

