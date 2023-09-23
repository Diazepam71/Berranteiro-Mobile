#pragma once
#include "Inimigo.h"

namespace Entidades
{

    namespace Personagens
    {

        class Onca: public Inimigo
        {
            private:
                bool agressividade;
            public:
				Onca(Jogador* j1, float x, float y, Fmx::Types::TFmxObject* parent);
                ~Onca();
                void viradoEsq();
                void viradoDir();
                void ataqueDir();
                void ataqueEsq();
                void ataque(TPointF posiJogador);
                void calculaAgressividade();

        };

    }

}