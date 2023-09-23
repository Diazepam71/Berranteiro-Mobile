#pragma once
#include "Obstaculo.h"

namespace Entidades {

	class Espinho : public Obstaculo {
	private:
		int afiado;
		int qtd;

	public:
		Espinho(float x, float y, int tam, Fmx::Types::TFmxObject* parent);
		~Espinho();
		int getAfiado();

	};
}

