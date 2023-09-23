#include "Obstaculo.h"

namespace Entidades
{
    class Trepadeira: public Obstaculo
    {
    private:
        bool espinhosa;

		public:
			Trepadeira(float x, float y, Fmx::Types::TFmxObject* parent);
            ~Trepadeira();
            const bool getEspinhosa();
    };
}