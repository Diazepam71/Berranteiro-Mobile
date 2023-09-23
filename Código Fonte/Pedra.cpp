#include "Pedra.h"
#include <System.Ioutils.hpp>
#include <time.h>

using namespace Entidades;

Pedra::Pedra(float x, float y, Fmx::Types::TFmxObject* parent) : Obstaculo(x, y, parent) {
	srand(time(NULL));
	massa = 10;
	danoso = false;
	atacar = danoso;
	int opc = rand() % 2;
	//if (opc == 0) setTextura("Midia/Imagens/Pedra1.png");
	//else setTextura("Midia/Imagens/Pedra2.png");
	setPos(TPointF(x, y));
	//corpo.setPosition(x, y);

	//corpo.setTextureRect(sf::IntRect(0, 0, 491, 338));
	if (opc == 0) {
		textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Pedra1.png"));
		corpo->Bitmap->Assign(textura);
    }

	else {
		textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Pedra2.png"));
		corpo->Bitmap->Assign(textura);
    }
	corpo->Width = 98;
	corpo->Height = 68;
}

Pedra::~Pedra() {}
