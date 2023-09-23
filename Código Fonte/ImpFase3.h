//---------------------------------------------------------------------------

#ifndef ImpFase3H
#include "Fase.h"
#include "Curupira.h"

namespace Fases
{

	class ImpFase3: public Fase
    {
	private:
        //System::Classes::TComponent* Owner;

        public:
			ImpFase3(Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner);
			ImpFase3(GerenciadorColisao *c, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner);
			~ImpFase3();
            void executar();
            void geraInimigos();
			void geraObstaculos();
			Curupira* geraCurupira(float x, float y);
			void geraItens();
    };

}
#define ImpFase3H
//---------------------------------------------------------------------------
#endif
