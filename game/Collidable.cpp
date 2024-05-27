#include "Collidable.h"

bool Collidable::isCollision(Collidable& obj) const {
	return getBounds().intersects(obj.getBounds()); //veo la posicion de mi colisionable con la del otro y devuelvo true si se estan tocando 
}