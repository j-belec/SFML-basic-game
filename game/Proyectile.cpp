#include "Proyectile.h"

Proyectile::Proyectile()
{
	_texture.loadFromFile("proyectile.jpg");
	_sprite.setTexture(_texture);
}

void Proyectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

sf::FloatRect Proyectile::getBounds() const
{
	return _sprite.getGlobalBounds();
}

void Proyectile::fire(float x, float y)
{
	_sprite.setPosition(x, y);
	_sprite.move(0, _speed);
}


