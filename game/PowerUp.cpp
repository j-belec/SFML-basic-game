#include <stdlib.h>
#include "PowerUp.h"

PowerUp::PowerUp()
{
	_texture.loadFromFile("esmerald.png");
	_sprite.setTexture(_texture);
}

void PowerUp::respawn()
{
	_sprite.setPosition(std::rand() % 600, std::rand() % 400);
}

sf::FloatRect PowerUp::getBounds() const
{
	return _sprite.getGlobalBounds();
}

void PowerUp::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}
