#pragma once
#include <SFML/Graphics.hpp>
#include "Collidable.h"

//maquina de estado
enum class PersonajeState {
	Idle = 0, //es cuando esta quieto el personaje
	Move
};

class Personaje : public sf::Drawable, public Collidable //lo extiendo de drawable para q el personaje se pueda dibujar, para eso viene con el metodo draw, q lo sobreescribo
{
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Vector2f _speed;

	sf::Vector2f _movePosition;

	float _frame; //es el q me va a manejar en q frame estoy actualmente
	PersonajeState _state = PersonajeState::Idle; //es el estado actual y por default va a ser idle
public:
	Personaje();
	void cmd();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override; //const para no modificar el estado actual del personaje y override para sobreescribir
	sf::FloatRect getBounds() const override;
	void increaseSpeed(int speed);
	void hited();
	void shoot(float x, float y);
};



