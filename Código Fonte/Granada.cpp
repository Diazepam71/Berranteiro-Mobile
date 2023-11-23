//---------------------------------------------------------------------------

#pragma hdrstop

#include "Granada.h"
#include "Arma.h"
using namespace Fases;

Granada::Granada(Jogador* jo, float x, float y, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner)
: Item(jo, x, y, parent, owner) {
	textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Granada.png"));
	corpo->Bitmap->Assign(textura);
	corpo->Width = 14;
	corpo->Height = 18;
	corpo->Position->Point = TPointF(x, y);
	nome = "granada";
	ativa = 0;
	explode = 1;
	inicio = clock();
	explodindo = 0;
	f = NULL;
	flag = 0;
	Owner = owner;
	numVidas = 3;
	qtd = 1;
}

Granada::~Granada() {}

void Granada::pegar() {
	if (ativa == 1) return;
    if ((((float) clock() - inicio) / CLOCKS_PER_SEC) < 1) return;

	int i;
	Arma* x;
	bool flag = 0;
	for (i = 1; i <= j->getl_arma()->getTam(); i -= -1) {
		x = j->getl_arma()->getElX(i)->getInfo();
		if (x->getNome() == "granada") {
			x->setAmmo(x->getAmmo() + qtd);
			x->setMagvar(x->getMagvar() + qtd);
			flag = 1;
			f->getInterface()->setInstrucao(System::UnicodeString("Pegou "+System::UnicodeString(qtd)+" outra(s) Granada(s)."));
			explode = 0;
			setVidas(0);
			return;
		}
	}
	if (j->getl_arma()->getTam() >= 3) {
		f->getInterface()->setInstrucao(System::UnicodeString("INVENTARIO CHEIO."));
		return;
	}
	if (flag == 0) {
		Arma* sk = new Arma("granada", Owner);
		j->getl_arma()->incluirEl(sk);
        j->getl_arma()->getElX(j->getl_arma()->getTam())->getInfo()->setAmmo(qtd);
		f->getInterface()->setInstrucao(System::UnicodeString("Pegou "+System::UnicodeString(qtd)+" Granada(s)."));
	}
	explode = 0;
	setVidas(0);
}

void Granada::setVidas(int n) {
	if (numVidas > 0 && n <= 0) {
		if (((float) clock() - inicio) / CLOCKS_PER_SEC < 1) return;
		if (explode == 1) explodir();
		corpo->Width = 0;
		corpo->Height = 0;
		vivo = false;
	}
	numVidas = n;
}

void Granada::explodir() {
	if (explode == 1) f->geraExplosao(pos.x - 70, pos.y - 70, 1);
	explode = 0;
	setVidas(0);
}

void Granada::move() {
	if (numVidas <= 0) return;
    if (pos.x > 800 || pos.x < -100 || pos.y > 500 || pos.y < -100) {
		setVelX(0.0f);
		setVelY(-0.3f);
		cair();
	}
	else
	{
		pos.x += velx;
		pos.y += vely;
        if (flag == 1 && vely == 0) velx = 0;
		if (flag == 0 && vely == 0) flag = 1;
		setPos(TPointF(pos.x, pos.y));
	}
	if (ativa == 1 && (((float) clock() - inicio) /CLOCKS_PER_SEC) > 3 && explode == 1) explodir();
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
