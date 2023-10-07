#pragma once
#include "Entidade.h"
#include "Personagem.h"
#include "ListaEntes.h"
using namespace Listas;
#include "Mapa.h"
#include "Arma.h"

namespace Entidades
{

	namespace Personagens
	{

		class Jogador : public Personagem {
		private:
			//sf::Texture Tesq, Tdir, Adir, Aesq;
			Mapa* pMapa2;
			clock_t tempoDano;
			bool verifTempo, atirando;
			int pontos;
			Lista<Arma> *l_arma;
			int arma_sel;
			ListaEntes* ini;
			//sf::Sound s1;
			int maxVidas;
			Lista<string>* itens;
			System::Classes::TComponent* Owner;

		public:
			Jogador(Fmx::Types::TFmxObject* parent);
			~Jogador();
			void move();
			void pular();
            void setOwner(System::Classes::TComponent* owner);
			void parar();
			void setMapa2(Mapa* m2) { pMapa2 = m2; }
			Mapa* getMapa2() { return pMapa2; }
			void viradoDir();
			void viradoEsq();
			void ataqueDir();
			void ataqueEsq();
			void colisaoInimigo(Entidade *i);
			int colisaoMapaObs(Entidade *hbx);
			int getPontos();
			void setArmaSel(int x);
			int getArmaSel();
			Lista<Arma>* getl_arma();
			void atirar();
			void setl_ini(ListaEntes* i);
			Ente* hitscan(Ente* e);
			void setMaxVidas(int x) { maxVidas = x; };
			int getMaxVidas() { return maxVidas; };
			void setAtirando(int x) { atirando = x; };
			bool getAtirando() { return atirando; };
			Lista<string>* getItens() { return itens; };
		};
	}
}
