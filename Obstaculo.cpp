#include "Obstaculo.h"

using namespace Entidades;

Obstaculo::Obstaculo(float x, float y, Fmx::Types::TFmxObject* parent) : Entidade(3, TPointF(x, y), parent) {
	danoso = false;
	atacar = danoso;
	obstaculo = true;
	colidivel = true;
}

Obstaculo::~Obstaculo() {}

void Obstaculo::move() { 
	//cair();

	if (pos.x > 600 || pos.x < -100 || pos.y > 450 || pos.y < -100) {
        setVelX(0.0f);
		setVelY(0.0f);
    }
	else
	{
		pos.y += 4*vely;
		setPos(TPointF(pos.x, pos.y));
	}
}