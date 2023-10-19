#pragma once
#include "ListaEntes.h"
#include "Jogador.h"
#include "Mapa.h"
#include <vector>
using namespace Entidades;
using namespace Personagens;

namespace Gerenciadores
{

	class GerenciadorColisao {
	private:
		Jogador* jogador;
		ListaEntes* inimigos;
		Mapa* map;
        int plataforma_inicio;


	public:
		GerenciadorColisao(ListaEntes* ini, Jogador* p, Mapa* m);
		GerenciadorColisao();
		~GerenciadorColisao();
		const TPointF calculaColisaoIni(Ente* e1, Ente* e2);
		const TPointF calculaColisaoPlat(Ente* e, Plataforma* p);
		void executar();
		//void incluirJogador(Jogador *p);
		void setInimigos (ListaEntes *l);
        void trataExplosao(Entidade* expl);
		//void setMapa (Mapa *m);
		//Ente* hitscan(Jogador* j, Ente* e);
	};

}