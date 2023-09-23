#pragma once
#include "Fase.h"
#include "Curupira.h"

namespace Fases
{

	class ImpFase2: public Fase
    {
	private:
        //System::Classes::TComponent* Owner;

        public:
			ImpFase2(Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner);
			ImpFase2(GerenciadorColisao *c, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner);
			~ImpFase2();
            void executar();
            void geraInimigos();
			void geraObstaculos();
			Curupira* geraCurupira(float x, float y);
			void geraItens();
    };

}
