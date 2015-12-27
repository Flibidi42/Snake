#include "../hd/game_hdlr.hpp"
#include <iostream>

Game_hdlr::Game_hdlr(Snake *s, sf::RenderWindow* w){
	m_s = s;
	m_w = w;
	s->affichage(w);
	dir_courante = RIGHT;
	ajout = false;
}

void Game_hdlr::iteration(){
	if(!(m_s->moove(dir_courante, ajout)))
		std::cout << "Fin du jeu!" << std::endl;
}
