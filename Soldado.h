#pragma once
#include "Inimigo.h"
#include "Arma.h"
#include "Fase.h"

using namespace Fases;
namespace Entidades
{
    namespace Personagens
    {
        class Soldado : public Inimigo
        {
            private:
                //sf::Texture Tesq, Tdir, Adir, Aesq;
                Arma *arma;
                int skin;
				TMediaPlayer* s1;
                bool corre;
				clock_t relogio;
                float dt;
                int contador;
				Fase* f;
				string item;

            public:
				Soldado(Jogador *j1, float x, float y, int s, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner);
                ~Soldado();
                void move();
                void viradoEsq();
                void viradoDir();
                void ataqueDir();
                void ataqueEsq();
				void afastar(TPointF posiJogador);
                void ataque(TPointF posiJogador);
                void setVidas(int n);
				void setFase(Fase* f0) { f = f0; };
                void setItem(string s) {item = s;};

			    //void atirar();
			    Ente* hitscan(Ente* e);
			    //void setAtirando(int x) { atirando = x; };
			    //bool getAtirando() { return atirando; };
        };
    }
}