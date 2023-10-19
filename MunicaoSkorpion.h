#pragma once
#include "Item.h"
#include "Jogador.h"
#include "Fase.h"
using namespace Personagens;
using namespace Fases;

namespace Itens {

	class MunicaoSkorpion : public Item {
	private:
		Fase* f;
		int valor;
		clock_t inicio;

	public:
		MunicaoSkorpion(Jogador* jo, float sx, float sy, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner);
		~MunicaoSkorpion();
		void pegar();
		void setFase(Fase* f0) { f = f0; }
		void setValor(int x) { valor = x; }
        void setVidas(int n);
	};
}