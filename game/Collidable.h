#pragma once
#include <SFML/Graphics.hpp>

class Collidable
{
public:
	virtual sf::FloatRect getBounds() const = 0; //esto lo ahgo para q el q herede esta clase tenga si o si sobreescribir este metodo (por esto es q lo igualo a 0)
	bool isCollision(Collidable& obj) const; //recibe una referencia a un Collidable
};

