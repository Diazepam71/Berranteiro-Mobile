#include "Personagem.h"

using namespace Entidades;
using namespace Personagens;

Personagem::Personagem(const int v, const int id, float x, float y, Fmx::Types::TFmxObject* parent) : Entidade(v, TPointF(x, y), parent)
{
	//dano = 0;
	Tdir = new TBitmap();
	Tesq = new TBitmap();
	Adir = new TBitmap();
	Aesq = new TBitmap();
    virado = 0;
}

Personagem::~Personagem(){
	delete Tdir;
	delete Tesq;
	delete Aesq;
	delete Adir;
}

void Personagem::verifImg()
{
	if(velx>0)
    {
        virado = 0;
        if(atacar==true)
        {
            ataqueDir();
        }
        else
        {
            viradoDir();
        }
    }
	else if(velx<0)
    {
        virado = 1;
        if(atacar==true)
        {
            ataqueEsq();
        }
        else
        {
            viradoEsq();
        }
    }
    else if (velx == 0) {
        if (virado == 1 && atacar == true) ataqueEsq();
        else if (virado == 0 && atacar == true) ataqueDir();
        else if (virado == 1 && atacar == false) viradoEsq();
        else if (virado == 0 && atacar == false) viradoDir();
    }
}

bool Personagem::getVirado() { return virado; }
