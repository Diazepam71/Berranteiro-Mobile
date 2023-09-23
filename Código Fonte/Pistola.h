#pragma once
#include "Item.h"
#include "Jogador.h"
#include "Fase.h"
using namespace Personagens;
using namespace Fases;

namespace Itens {

	class Pistola : public Item {
	private:
		Fase* f;
		float ammo, magvar;
        System::Classes::TComponent* Owner;

	public:
		Pistola(Jogador* jo, float sx, float sy, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner);
		~Pistola();
		void pegar();
		void setFase(Fase* f0) { f = f0; }
		void setammo(float x) { ammo = x; }
		void setmagvar(float x) { magvar = x; }
        void findar();
	};
}
