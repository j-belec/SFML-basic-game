#pragma once
#include <SFML/Graphics.hpp>
#include "Collidable.h"

class Proyectile: public sf::Drawable, public Collidable
{
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Vector2f _speed;
	bool _isFire;
public:
	Proyectile();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override; 
	sf::FloatRect getBounds() const override;
	void fire(sf::Vector2f coords);
	void impact();
};

