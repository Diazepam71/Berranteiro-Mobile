#pragma once
#include "GerenciadorColisao.h"
#include "ListaEntes.h"
#include "Mapa.h"
#include "Onca.h"
#include "Arara.h"
#include "Espinho.h"
#include "Pedra.h"
#include "Trepadeira.h"
//#include "Curupira.h"
#include "Obstaculo.h"
#include "Interface.h"
#include "Item.h"
//#include "Soldado.h"
#include <time.h>
using namespace Entidades;
using namespace Personagens;
using namespace Gerenciadores;
using namespace Listas;

namespace Fases
{

    class Fase
    {
        protected:
			GerenciadorColisao *pColi;
            ListaEntes *lista;
            ListaEntes *inimigos;
			Jogador* j1;
            Mapa* mapa2;
			Interface* interf;
			clock_t relogio, dropclock;
			TBitmap* imagem;
			Fmx::Types::TFmxObject* Parent;
			System::Classes::TComponent* Owner;
            Lista<Obstaculo>* obs;

        public:
            Fase();
			Fase(Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner);
			~Fase();
            virtual void executar() = 0;
			void setJogador1(Jogador *j);
            void setEntes(ListaEntes *l);
            void setInimigos(ListaEntes *i);
            void setMapa2(Mapa* m);
            Mapa* getMapa2();
			void setColi(GerenciadorColisao* c);
            ListaEntes* getLista();
            ListaEntes* getInimigos();
			Jogador* getJogador();
            void setParent(Fmx::Types::TFmxObject* parent);
			void geraOnca(float x, float y);
			void geraArara(float x, float y);
			void geraPedra(float x, float y);
			void geraEspinho(float x, float y, int tam);
			Item* geraItem(float x, float y, string nome);
			void geraSoldado(float x, float y, int s);
			void moveLista();
            GerenciadorColisao* getGCol() {return pColi;};
			Interface* getInterface();
			//void jogador_soltarArma();
    };

}