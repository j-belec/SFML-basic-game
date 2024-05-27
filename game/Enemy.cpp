#include <stdlib.h>
#include "Enemy.h"

Enemy::Enemy() {
	_texture.loadFromFile("enemy.png");
	_sprite.setTexture(_texture);
}

void Enemy::respawn()
{
	_sprite.setPosition(std::rand()%600, std::rand() % 200);
	_newPosition = { std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height };
	//_timeRespawn = 60 * 5;
}

sf::FloatRect Enemy::getBounds() const
{
	return _sprite.getGlobalBounds(); //getGlobalBound devuelve las cordenadas de mi sprite teniendo en cuenta sus dimensiones
}

void Enemy::youDamaged()
{
	respawn();
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states); //target es el window, le digo de q forma se va a sobreescribir, osea le explico a el metodo draw de Drawable como se dibuja mi sprite para despues poder usar el metodo window.draw y q este sepa dibujar mi sprite
}

void Enemy::update() {
	_timeRespawn--;
	//if (_timeRespawn < 0) {
	//	//respawn();
	//	//_timeRespawn = 60 * 5; 
	//	_newPosition = { std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height };
	//}

	if (_newPosition.x > _sprite.getPosition().x) {
		_sprite.move(5, 0);
	}
	if (_newPosition.x < _sprite.getPosition().x) {
		_sprite.move(-5, 0);
	}
	if (_newPosition.y > _sprite.getPosition().y) {
		_sprite.move(0, 5);
	}
	if (_newPosition.y < _sprite.getPosition().y) {
		_sprite.move(0, -5);
	}

	if (std::abs(_newPosition.x - _sprite.getPosition().x) < 5 && std::abs(_newPosition.y - _sprite.getPosition().y) < 5) {
		_newPosition = { std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height };
	}
}