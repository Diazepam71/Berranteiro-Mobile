#include "Inimigo.h"

namespace Entidades
{

    namespace Personagens

    {

        class Arara: public Inimigo
        {
            private:
                int aumentaVel;

            public:
                Arara(Jogador* j1, float x, float y, Fmx::Types::TFmxObject* parent);
                ~Arara();
				void ataque(TPointF posiJogador);
                void viradoEsq();
                void viradoDir();
                void ataqueDir();
                void ataqueEsq();
                void calculaAvanco();

        };

    }

}