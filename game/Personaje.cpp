#include "Personaje.h"
#include "Proyectile.h"

//maquina de estado
//enum class PersonajeState {
//    Idle = 0, //es cuando esta quieto el personaje
//    Move
//};
 
Personaje::Personaje() {
    _texture.loadFromFile("ship.jpg"); //aca pongo la img de tdos
    _sprite.setTexture(_texture);
    _speed = { 4,4 }; //velocidad en X y en Y, de por si si la vel es pos va ir a la der y si es neg a la izq, lo mismo en y
    //_speed = 5;
    //_sprite.getTextureRect({ 660,0,40,50 }); //coordenada en x en la img, en y, ancho de mi frame, alto
    _frame = 0;
    //_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2); //tomo el origen desde la mitad en X y en Y del sprite, pongo el axis en la mitad del sprite //si o si el origen se hace desps de establecer el rect
}

void Personaje::cmd() {
    _movePosition = { 0,0 };
    _state = PersonajeState::Idle;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _movePosition.y = -_speed.y;
        _state = PersonajeState::Move;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _movePosition.x = -_speed.x;
        _state = PersonajeState::Move;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _movePosition.y = _speed.y;
        _state = PersonajeState::Move;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _movePosition.x = _speed.x;
        _state = PersonajeState::Move;
    }
}

void Personaje::update() {
    //sf::Vector2f speed = { 0,0 };

    //_frame += 0.2;
    // 
    //if (_frame >= 4) { //4 porq mi animacion de correr tiene 4 frames solo, osea 4 imgs distintas
    //    _frame = 0;
    //}

    //_sprite.setTextureRect({660 + int(_frame) * 40, 0, 40, 50})

    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    //    //_sprite.move(0, -_speed); //X,Y
    //    speed.y = -_speed.y;
    //}
    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    //    //_sprite.move(-_speed, 0);
    //    speed.x = -_speed.x;
    //}
    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    //    //_sprite.move(0, _speed);
    //    speed.y = _speed.y;
    //}
    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    //    //_sprite.move(_speed, 0);
    //    speed.x = _speed.x;
    //}
    //_sprite.move(speed.x, speed.y);

    //esto es para q el personaje mire hacia donde se esta moviendo, tamb tendria q cambiar lo del orignem para q ande
  /*  if (speed.x < 0) {
        _sprite.setScale(-1, 1);
    } 
    else if (speed.x > 0) {
        _sprite.setScale(1, 1);
    }*/

    switch (_state) {
    case PersonajeState::Idle:
        //_frame += 0.2;
        // 
        //if (_frame >= 4) { //4 porq mi animacion de correr tiene 4 frames solo, osea 4 imgs distintas
        //    _frame = 0;
        //}

        //_sprite.setTextureRect({660 + int(_frame) * 40, 0, 40, 50})
        break;

    case PersonajeState::Move:
        //_frame += 0.2;
        // 
        //if (_frame >= 4) { //4 porq mi animacion de correr tiene 4 frames solo, osea 4 imgs distintas
        //    _frame = 0;
        //}

        //_sprite.setTextureRect({660 + int(_frame) * 40, 0, 40, 50})
        _sprite.move(_movePosition);
        break;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        shoot(_sprite.getPosition().x, _sprite.getPosition().y);
    }

    //para q no se salga de la pantalla, se hace si o si antes de dibujar no desps
    if (_sprite.getPosition().x < 0) {
        _sprite.setPosition(0, _sprite.getPosition().y);
    }
    if (_sprite.getPosition().y < 0) {
        _sprite.setPosition(_sprite.getPosition().x, 0);
    }
    if (_sprite.getPosition().x > 800 - 50) {
        _sprite.setPosition(800 - 50, _sprite.getPosition().y); //- 50 pq es el tamaño de mi sprite 
    }
    if (_sprite.getPosition().y > 600 - 50) {
        _sprite.setPosition(_sprite.getPosition().x, 600 - 50);
    }
}

void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states); //target es el window, le digo de q forma se va a sobreescribir, osea le explico a el metodo draw de Drawable como se dibuja mi sprite para despues poder usar el metodo window.draw y q este sepa dibujar mi sprite
}

sf::FloatRect Personaje::getBounds() const
{
    return _sprite.getGlobalBounds();
}

void Personaje::increaseSpeed(int speed)
{
    _speed.x = _speed.x + speed;
    _speed.y = _speed.y + speed;
}

void Personaje::shoot(float x, float y)
{
    Proyectile pro;
    pro.fire(x, y);
}
