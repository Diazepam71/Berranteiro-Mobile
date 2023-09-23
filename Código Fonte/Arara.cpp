#include "Arara.h"

using namespace Entidades;
using namespace Personagens;

Arara::Arara(Jogador* j1, float x, float y, Fmx::Types::TFmxObject* parent) :
Inimigo(j1, x, y, parent)
{
    dano = 15;
    numVidas = 30;
    aumentaVel = 0;
    ataqueDistancia = false;
	voa = true;

	Tdir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"AraraD.PNG"));
	Tesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"AraraE.png"));
	Adir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"AraraAtaqueD.png"));
	Aesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"AraraAtaqueE.png"));

	corpo->Width = 102;
	corpo->Height = 44;
	corpo->Bitmap->Assign(Tesq);
}

Arara::~Arara() {}

void Arara::viradoEsq()
{
	setTextura(Tesq);
    corpo->Width = 102;
	corpo->Height = 44;
}
void Arara::viradoDir()
{
	setTextura(Tdir);
    corpo->Width = 102;
	corpo->Height = 44;
}

void Arara::ataqueDir()
{
	setTextura(Adir);
	corpo->Width = 102;
	corpo->Height = 64;
}

void Arara::ataqueEsq()
{
	setTextura(Aesq);
	corpo->Width = 102;
	corpo->Height = 64;
}

void Arara::ataque(TPointF posiJogador)
{
    int verif, v = 4;

	velx = 0.0;

    srand(time(NULL));
    verif = rand()%2;
    
    if(verif==2)
    {
        calculaAvanco();
        v = v + aumentaVel;
    }

	if((posiJogador.x - pos.x)<0) {  velx = velx - v; }

	else if((posiJogador.x - pos.x)>0) { velx = velx + v; }

	if((posiJogador.y - pos.y)>0) { vely = v; }

	else if((posiJogador.y - pos.y)<0) { vely = 0 - v; }

    else
		vely = 0;

}

void Arara::calculaAvanco()
{
    srand(time(NULL));
    aumentaVel = rand()%3;
}