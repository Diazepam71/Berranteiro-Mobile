#include "Entidade.h"
#include <iostream>
using namespace std;

using namespace Entidades;

Entidade::Entidade(const int v, TPointF p, Fmx::Types::TFmxObject* parent):
Ente(p, parent)
{
	//pos = xy;
	//corpo.setFillColor(sf::Color::Blue);
	velx = 0.0;
	vely = 0.0;
	vivo = true;
	atacar = false;
	obstaculo = false;
	item = false;
	numVidas = v;
}

Entidade::~Entidade() {}

void Entidade::setVelX(float x) { velx = x; }

void Entidade::setVelY(float y) { vely = y; }

void Entidade::cair() {
	vely = vely + 0.3;
}

bool Entidade::getVivo() { return vivo; }

void Entidade::setVivo(bool v) { vivo = v; }

bool Entidade::getAtacar() { return atacar; }

void Entidade::setAtacar(bool a) { atacar = a; }

void Entidade::operator++()
{
	numVidas++;
}
void Entidade::operator--()
{
	numVidas--;
	if(numVidas<=0) {
		setVivo(false);
		corpo->Scale->X = 0;
		corpo->Scale->Y = 0;
	}
}

void Entidade::setVidas(int n) { 
	numVidas = n;
	if (numVidas <= 0) {
		setVivo(false);
		corpo->Width = 0;
		corpo->Height = 0;
	}
	else {
		setVivo(true);
		//corpo->Scale->X = 0.2;
		//corpo->Scale->Y = 0.2;
	}
}

bool Entidade::getObstaculo()
{
	return obstaculo;
}