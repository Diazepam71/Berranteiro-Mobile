#include "Espinho.h"
#include <System.Ioutils.hpp>
using namespace Entidades;
#include <time.h>

Espinho::Espinho(float x, float y, int q, Fmx::Types::TFmxObject* parent): Obstaculo(x, y, parent) {
	qtd = q;
	srand(time(NULL));
	//danoso = true;
	afiado = rand() % 10 + 10;
	atacar = true;
	danoso = afiado;
	TBitmap* tmp = new TBitmap();
	tmp->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Espinhos.png"));
	textura->Resize(16 * qtd, 16);
	textura->CopyFromBitmap(tmp, System::Types::TRect(0,0,16*qtd,16),0,0);
	corpo->Width = 32 * qtd;
	corpo->Height = 32;
	setTextura(textura);
	corpo->Bitmap->Assign(textura);
	//corpo.setTextureRect(sf::IntRect(0, 0, 16*qtd, 16));
	
	//corpo.setScale(2, 2);
}

Espinho::~Espinho() {}

int Espinho::getAfiado() { return afiado; }