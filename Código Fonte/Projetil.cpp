#include "Projetil.h"
#include "Curupira.h"
#include <cmath>

using namespace Entidades;


Projetil::Projetil(float x, float y, Fmx::Types::TFmxObject* parent):
Entidade(10,TPointF(x, y), parent)
{
	atirador = NULL;
    direita = false;
	ativado = false;
	projetil = true;
    dano = 40;
	alcance = 800;
	distanciaPercorrida = 0;
	setAtacar(false);
	textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Fogo.png"));
	corpo->Bitmap->Assign(textura);
	corpo->Width = 16;
	corpo->Height = 16;
	relogio = clock();
}
Projetil::~Projetil()
{
	atirador = NULL;
}
void Projetil::move()
{
	velx = 0;
	setAtacar(false);

	/*if(vivo == false) if ((float)(clock() - relogio) / (float)CLOCKS_PER_SEC > 6.0) {
		setVidas(10);
	}*/

	if(ativado == true)
	{
		setAtacar(true);
        if(direita==true)
			velx = 6;
        else
			velx = -6;

		distanciaPercorrida = distanciaPercorrida + 6;
		vely = sin((float)((float)(clock() - relogio) / (float)CLOCKS_PER_SEC) * 11);
		
		//if (distanciaPercorrida < alcance) { setVelY(0); }

		pos.x = pos.x + velx;
		pos.y = pos.y + vely*3;
		setPos(TPointF(pos.x, pos.y));

	}
	else
	{
		if (atirador->getVirado() == 0) {
			if (atirador->getAtacar() == 1) setPos(TPointF(atirador->getPos().x + atirador->getTamX(), atirador->getPos().y + 40));
			else setPos(TPointF(atirador->getPos().x + atirador->getTamX() + this->getTamX(), atirador->getPos().y + 40));
		}
		else {
			if (atirador->getAtacar() == 1) setPos(TPointF(atirador->getPos().x, atirador->getPos().y + 40));
			else setPos(TPointF(atirador->getPos().x - this->getTamX(), atirador->getPos().y + 40));
		}
	}

	if((distanciaPercorrida > alcance))
	{
		distanciaPercorrida = 0;
		ativado = false;
		setPos(TPointF(atirador->getPos().x, atirador->getPos().y + 40));
	}
}

void Projetil::setAtivado(bool b)
{
	ativado = b;
}

bool Projetil::getAtivado()
{
	return ativado;
}

void Projetil::setDireita(bool b)
{
    direita = b;
}

void Projetil::setAtirador(Inimigo *i)
{
    atirador = i;
}

void Projetil::setVidas(int n) {
    if (n <= 0 && numVidas > 0) {
		comp = corpo->Width;
		alt = corpo->Height;
		setVivo(false);
		corpo->Width = 0;
		corpo->Height = 0;
		relogio = clock();
		ativado = false;
	}
	else if (n > 0 && numVidas <= 0) {
		setVivo(true);
		corpo->Width = comp;
        corpo->Height = alt;
		//corpo->Scale->X = 0.2;
		//corpo->Scale->Y = 0.2;
	}
	numVidas = n;

}