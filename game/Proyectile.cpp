#include "Proyectile.h"

Proyectile::Proyectile()
{
	_texture.loadFromFile("proyectile.jpg");
	_sprite.setTexture(_texture);
	//_speed = { 0,0 };
}

void Proyectile::update()
{
	if (_isFire) {
		_sprite.move(0, -5);
	}
}

void Proyectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

sf::FloatRect Proyectile::getBounds() const
{
	return _sprite.getGlobalBounds();
}

void Proyectile::fire(sf::Vector2f coords)
{
	_sprite.setPosition(coords);
	_speed = { 0, 5 };
	//_sprite.move(_speed.x, _speed.y);
	_isFire = true;
}

void Proyectile::impact()
{
	_sprite.setPosition({ -100, -100 });
}
