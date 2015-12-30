#include "../hd/snake.hpp"
#include "../hd/constantes.hpp"
#include <iostream>
#include <iterator>


Snake::Snake(int x, int y){
	sf::RectangleShape rec (sf::Vector2f(PART_SZ, PART_SZ));
	rec.setPosition(x, y);
	rec.setFillColor(sf::Color(100, 250, 50));
	sf::RectangleShape rec2(sf::Vector2f(PART_SZ, PART_SZ));
	rec2.setPosition(x + PART_SZ, y);
	rec2.setFillColor(sf::Color(100, 250, 50));
	file.push_back(rec);
	file.push_back(rec2);
}

void Snake::affichage(sf::RenderWindow* w){
	std::deque<sf::RectangleShape>::iterator it;
	w->clear(sf::Color::Black);
	for(it = file.begin(); it!= file.end(); it++)
		w->draw(*it);
}

bool Snake::moove(Dir direction, bool ajout = false){
	//On retient la position qu'aura le nouveau
	int posx, posy;
	switch(direction){
		case RIGHT:
			posy = file[file.size()-1].getPosition().y;
			posx = file[file.size()-1].getPosition().x + PART_SZ;
		break;
		case LEFT:
			posy = file[file.size()-1].getPosition().y;
			posx = file[file.size()-1].getPosition().x - PART_SZ;
		break;
		case UP:
			posy = file[file.size()-1].getPosition().y - PART_SZ;
			posx = file[file.size()-1].getPosition().x;
		break;
		case DOWN:
			posy = file[file.size()-1].getPosition().y + PART_SZ;
			posx = file[file.size()-1].getPosition().x;
		break;
	}
	
	//On teste s'il sort de l'écran
	if(posx >= WIND_SZ || posy >= WIND_SZ || posx < 0 || posy < 0)
		return false;
		
	//Le premier devient le dernier
	sf::RectangleShape rec = file[0];
	file.pop_front();
	rec.setPosition(posx, posy);
	file.push_back(rec);
	return true;
}

