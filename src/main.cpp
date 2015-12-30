#include <SFML/Graphics.hpp>
#include "../hd/game_hdlr.hpp"
#include "../hd/constantes.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIND_SZ, WIND_SZ), "Snake");
    Snake s(50, 50);
    s.affichage(&window);
    sf::Clock horloge;
    Game_hdlr game(&s, &window);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){
            	case sf::Event::Closed:
                	window.close();
                	break;
                case (sf::Event::KeyPressed):
         		if(event.key.code == sf::Keyboard::Left)
         			game.chgt_dir(LEFT);
         		if(event.key.code == sf::Keyboard::Up)
         			game.chgt_dir(UP);
         		if(event.key.code == sf::Keyboard::Down)
         			game.chgt_dir(DOWN);
         		if(event.key.code == sf::Keyboard::Right)
         			game.chgt_dir(RIGHT);
         		break;
            }
        }
        if(horloge.getElapsedTime().asMilliseconds() >= 300){
        	if(!game.iteration())
        		window.close();
        	horloge.restart();
        }
        window.display();
    }
    return 0;
}
