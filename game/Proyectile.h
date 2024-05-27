#pragma once
#include <SFML/Graphics.hpp>
#include "Collidable.h"

class Proyectile: public sf::Drawable, public Collidable
{
	sf::Texture _texture;
	sf::Sprite _sprite;
	float _speed;
public:
	Proyectile();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getBounds() const override;
	void fire(float x, float y);
};

