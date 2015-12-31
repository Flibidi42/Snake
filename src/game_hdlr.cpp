#include "../hd/game_hdlr.hpp"
#include "../hd/constantes.hpp"
#include <iostream>

Game_hdlr::Game_hdlr(sf::RenderWindow* w){
	m_w = w;
	init();
}

Game_hdlr::~Game_hdlr(){
	delete food;
	delete m_s;
}

bool Game_hdlr::iteration(){
	dir_courante = dir_suivante;
	Retour val = m_s->moove(dir_courante, food->getPosition().x, food->getPosition().y);
	if(val == FIN){
		std::cout << "Fin du jeu!" << std::endl;
		return false;
	}
	else if(val == FOOD){
		generer_food();
		affichage();
	}
	else
		affichage();
	return true;
}

void Game_hdlr::affichage(){
	m_w->clear(sf::Color::Black);
	m_w->draw(*food);
	m_s->affichage(m_w);
}

void Game_hdlr::generer_food(){
	int x, y;
	do{
		x = (rand()%(WIND_SZ/PART_SZ))*PART_SZ;
		y = (rand()%(WIND_SZ/PART_SZ))*PART_SZ;
	}while(!m_s->check_position(x,y));
	food->setPosition(x,y);
}

void Game_hdlr::init(){
	dir_courante = NONE;
	dir_suivante = RIGHT;
	if(food == 0)
		delete food;
	if(m_s == 0)
		delete m_s;
	m_s = new Snake((rand()%(WIND_SZ/PART_SZ))*PART_SZ, (rand()%(WIND_SZ/PART_SZ))*PART_SZ);
	food = new sf::RectangleShape(sf::Vector2f(PART_SZ, PART_SZ));
	generer_food();
	food->setFillColor(sf::Color::Red);
	affichage();
}

void Game_hdlr::chgt_dir(Dir direction){

	switch(dir_courante){
		case RIGHT:
			if(direction != LEFT)
				dir_suivante = direction;
			break;
		case LEFT:
			if(direction != RIGHT)
				dir_suivante = direction;
			break;
		case UP:
			if(direction != DOWN)
				dir_suivante = direction;
			break;
		case DOWN:
			if(direction != UP)
				dir_suivante = direction;
			break;
		case NONE:
			dir_suivante = direction;
			break;
	}
}
