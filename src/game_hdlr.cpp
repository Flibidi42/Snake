#include "../hd/game_hdlr.hpp"
#include <iostream>

Game_hdlr::Game_hdlr(Snake *s, sf::RenderWindow* w){
	m_s = s;
	m_w = w;
	s->affichage(w);
	dir_courante = RIGHT;
	dir_suivante = RIGHT;
	ajout = false;
}

bool Game_hdlr::iteration(){
	dir_courante = dir_suivante;
	if(!(m_s->moove(dir_courante, ajout))){
		std::cout << "Fin du jeu!" << std::endl;
		return false;
	}
	else
		m_s->affichage(m_w);
	return true;
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
	}
}
