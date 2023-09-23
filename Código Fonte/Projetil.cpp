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
	alcance = 800;
	distanciaPercorrida = 0;
	setAtacar(false);
	textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Fogo.png"));
	corpo->Bitmap->Assign(textura);
	corpo->Width = 16;
	corpo->Height = 16;
}
Projetil::~Projetil()
{
	atirador = NULL;
}
void Projetil::move()
{
	velx = 0;
	setAtacar(false);

	if(ativado == true)
	{
		setAtacar(true);
        if(direita==true)
			velx = 6;
        else
			velx = -6;

		distanciaPercorrida = distanciaPercorrida + 6;
		vely = sin(clock() / CLOCKS_PER_SEC * 8);
		
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

	if((distanciaPercorrida > alcance) && (pos != atirador->getPos()))
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