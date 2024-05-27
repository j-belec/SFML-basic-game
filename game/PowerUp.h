#pragma once
#include <SFML/Graphics.hpp>
#include "Collidable.h"

class PowerUp: public sf::Drawable, public Collidable
{
	sf::Texture _texture;
	sf::Sprite _sprite;
public:
	PowerUp();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void respawn();
	sf::FloatRect getBounds() const override;
};

