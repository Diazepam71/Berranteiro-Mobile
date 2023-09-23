#pragma once
#include "Inimigo.h"
#include "ListaEntes.h"
#include "Lista.h"
#include "Projetil.h"
#include "Item.h"
#include "Fase.h"
using namespace Fases;

namespace Entidades
{

	namespace Personagens
	{

		class Curupira: public Inimigo
		{
			private:
				Projetil *fogo;
				bool atirar;
				bool ressucitar;
				bool corre;
				ListaEntes *animais;
				clock_t relogio;
				string item;
				Fase* f;
				clock_t proj;

			public:
				Curupira(Jogador* j1, float x, float y, Fmx::Types::TFmxObject* parent);
				~Curupira();
				void move();
				void viradoEsq();
				void viradoDir();
				void ataqueDir();
				void ataqueEsq();
				void ataque(TPointF posiJogador);
				void afastar(TPointF posiJogador);
				void ressucitarAnimais();
				void calculaRessucitar();
				void setLista(ListaEntes *l);
				void setVidas(int x);
				Projetil* getFogo();
				void setItem(string s) { item = s; }
				void setFase(Fase* f0) { f = f0; }
				
		};

	}

}