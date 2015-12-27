#include "../hd/snake.hpp"
#include "../hd/constantes.hpp"
#include <iostream>
#include <iterator>


snake::snake(int x, int y){
	sf::RectangleShape rec (sf::Vector2f(PART_SZ, PART_SZ));
	rec.setPosition(x, y);
	file.push_front(rec);
}

void snake::affichage(sf::RenderWindow* w){
	std::deque<sf::RectangleShape>::iterator it;
	w->clear(sf::Color::Black);
	for(it = file.begin(); it!= file.end(); it++)
		w->draw(*it);
}
