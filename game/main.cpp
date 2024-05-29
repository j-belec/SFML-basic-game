#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <ctime>
#include "Personaje.h"
#include "Enemy.h"
#include "PowerUp.h"
#include "Proyectile.h"

//en gral se hace una clase al personaje y otra al jugador, en donde van a estar las estadisticas y las vidas por ej

int main()
{
    std::srand((unsigned)std::time(0));
    //inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60); //limito a max 60fps

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("bg.jpg");
    sf::Sprite background;
    background.setTexture(backgroundTexture);

    //texto
    sf::Font font;
    font.loadFromFile("nums.ttf");

    sf::Text text;
    text.setFont(font);
    
    sf::Text vidasText;
    vidasText.setFont(font);
    vidasText.setPosition({ 0, 50 });

    sf::Text textRestart;
    textRestart.setFont(font);
    textRestart.setPosition({ 200,200 });

    
    Personaje player;

    Enemy enemy;
    enemy.respawn();

    PowerUp powerUp;
    powerUp.respawn();

    Proyectile proyectile;


    int puntos = 0;
    int vidas = 3;
    int timer = 60 * 5; //el juego esta a 60fps, por lo q el game loop se va a ejecutar 60 veces en 1 seg, por eso 60 por 5

    //game loop
    while (window.isOpen())
    {
        window.clear();
        //lo primero q hace el loop es readInput, osea actualizar los estados de los perifericos de entrada
        //luego lee la cola de mensajes
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //CMD
        //aca uno se hace x cosa dependiendo q apreta el usuario (por ej el usuario toca la flecha izq)
       
        //update actualiza los estados del juego (por ej se actuliza a la clase del personaje q esta yendo a la izq)
        if (vidas > 0) {
            player.cmd();
            player.update();
            enemy.update();
            proyectile.update();
        }
        else {
            textRestart.setString("Presione ESPACIO para continuar");
            window.draw(textRestart);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                vidas = 3;
                puntos = 0;
                enemy.respawn();
                
            }
        }

        if (timer > 0) {
            timer--;
        }

        if (player.isCollision(enemy)) {
            enemy.respawn();
            puntos++;
            vidas--;
        }

        if (timer == 0 && player.isCollision(powerUp)) {
            player.increaseSpeed(1);
            timer = 60 * 5;
            powerUp.respawn();
        }

        if (player.isCollision(enemy)) {
            //player.hited();
            enemy.youDamaged();
            vidas--;
        }

        if (enemy.isCollision(proyectile)) {
            enemy.die();
            proyectile.impact();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            proyectile.fire(player.getCoordinates());
        }

        text.setString("puntos: " + std::to_string(puntos));//texto  //to_string porq es un numero puntos
        vidasText.setString("vidas: " + std::to_string(vidas));

        /*window.clear();*/ //antes de dibujar se limpia la pantalla, osea se borra todo para q no se superpongan las imagenes

        //DRAW muestra en pantalla lo q se va actualizando (por ej el personaje camina a la izq)
        window.draw(background); //el fondo tiene q ir  siempre primero, sino tapa lo otro
        window.draw(player);
        window.draw(enemy);
        window.draw(proyectile);
        if (timer == 0) {
            window.draw(powerUp);
        }
        window.draw(text); //para el texto
        window.draw(vidasText);


        //display
        //aca se hace el flip, sfml trabaja con dos buffers, uno en el q se va cargando las cosas q necesito, y cuando ya este todo hago flip con el otro buffer, y asi 
        //sucesuvamente. Esto es para q no se vean cosas a medias, es deicr por ej cargue el fondo pero no el personaje. Entonces solo cuando este todo cargado en un buffer se lo mando
        //al otro q es el encargado de mostrarlo
        window.display();


    }

    //liberacion del juego

    return 0;
}