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
        if(horloge.getElapsedTime().asMilliseconds() >= 300){
        	s.moove();
        	s.affichage(&window);
        	horloge.restart();
        }
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }
    return 0;
}
