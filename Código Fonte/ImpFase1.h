#pragma once
#include "Fase.h"

namespace Fases
{

	class ImpFase1: public Fase
    {
	private:
        //System::Classes::TComponent* Owner;

        public:
			ImpFase1(Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner);
			ImpFase1(GerenciadorColisao *c, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner);
			~ImpFase1();
            void executar();
            void geraInimigos();
			void geraObstaculos();
			void geraTrepadeira(float x, float y);
			void geraItens();
    };

}