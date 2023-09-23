#include "Onca.h"
#include <System.Ioutils.hpp>

using namespace Entidades;
using namespace Personagens;

Onca::Onca(Jogador* j1, float x, float y, Fmx::Types::TFmxObject* parent) :
Inimigo(j1, x, y, parent)
{
    dano = 25;
    numVidas = 50;
    agressividade = false;
    ataqueDistancia = false;
    voa = false;

	//corpo.setTextureRect(sf::IntRect(0, 0, 497, 340));
	//corpo.setScale(0.2, 0.2);

	Tdir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"OncaD.png"));
	Tesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"OncaE.png"));
	Adir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"OncaAtaqueD.png"));
	Aesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"OncaAtaqueE.png"));

	corpo->Width = 100;
	corpo->Height = 68;
	corpo->Bitmap->Assign(Tdir);
	//corpo->Scale->Point = (TPointF(0.2, 0.2));
}

Onca::~Onca(){}

void Onca::viradoEsq()
{
	setTextura(Tesq);
	corpo->Width = 100;
	corpo->Height = 68;
}
void Onca::viradoDir()
{
	setTextura(Tdir);
	corpo->Width = 100;
	corpo->Height = 68;
}

void Onca::ataqueDir()
{
	setTextura(Adir);
	corpo->Width = 102;
	corpo->Height = 63;
}

void Onca::ataqueEsq()
{
	setTextura(Aesq);
	corpo->Width = 102;
	corpo->Height = 63;
}

 void Onca::ataque(TPointF posiJogador)
 {
	float v;

	velx = 0.0;

    calculaAgressividade();

    if (agressividade==true) { v = 4; }
	else { v = 1.5; }

	if((posiJogador.x - pos.x)<0) {  velx = velx - v; }

	else if((posiJogador.x - pos.x)>0) { velx = velx + v; }

    if(vely==0) { vely = -4; }
    


    /*float dt = relogio2.getElapsedTime().asSeconds();
    if(dt>=1.0)
    {
        relogio2.restart();
        horaAtaque = false;
    }*/

 }

 void Onca::calculaAgressividade()
 {
    srand(time(NULL));

    int i = rand()%10;

    if(i==3 || i==7)
    {
        agressividade = true;
    }
 }