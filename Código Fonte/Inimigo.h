#pragma once
#include "Personagem.h"
#include "Jogador.h"
#include <time.h>

namespace Entidades
{

    namespace Personagens

    {

        class Inimigo : public Personagem
        {
        protected:
            Jogador* jogador1;
			//Jogador* jogador2;
            int movAl;
            bool horaAtaque;
            bool ataqueDistancia;
            bool voa;
            clock_t inicio, atual;
            float dano;

        public:
			Inimigo(Jogador* j1, float x, float y, Fmx::Types::TFmxObject* parent);
            ~Inimigo();
            virtual void move();
			void persegueJogador(TPointF posiJogador, float x);
            void movimentoAleatorio();
			virtual void ataque(TPointF posiJogador);
			void congela();
            float getDano() { return dano; };
            void setDano(float x) { dano = x; };
        };

    }

}