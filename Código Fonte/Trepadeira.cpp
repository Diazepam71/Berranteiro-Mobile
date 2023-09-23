#include "Trepadeira.h"
#include <System.Ioutils.hpp>
#include <time.h>

using namespace Entidades;

Trepadeira::Trepadeira(float x, float y, Fmx::Types::TFmxObject* parent): Obstaculo(x,y, parent)
{
    srand(time(NULL));
    espinhosa = rand() % 2;
    if (espinhosa == 1) espinhosa += 4;
    danoso = espinhosa;
    atacar = danoso;
    //corpo.setTextureRect(sf::IntRect(0, 0, 512, 512));
	textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Trepadeira.png"));
	corpo->Bitmap->Assign(textura);
	corpo->Width = 102;
	corpo->Height = 102;
    
}

Trepadeira::~Trepadeira() {}

const bool Trepadeira::getEspinhosa() { return espinhosa; }