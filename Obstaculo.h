#pragma once
#include "Entidade.h"

namespace Entidades

{

	class Obstaculo : public Entidade {
	protected:
		int danoso;
		bool colidivel;

	public:
		Obstaculo(float x, float y, Fmx::Types::TFmxObject* parent);
		~Obstaculo();
		virtual void move();
		int getDano() { return danoso; }
		bool getColidivel() { return colidivel; }
		void setColidivel(bool b) { colidivel = b; }
	};

}