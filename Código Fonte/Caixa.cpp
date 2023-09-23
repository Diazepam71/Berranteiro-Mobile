#include "Caixa.h"
#include "Arma.h"
#include "Fase.h"
#include "Chave.h"
using namespace Fases;
using namespace Itens;

Caixa::Caixa(Jogador* jo, float sx, float sy, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner) : Item(jo, sx, sy, parent, owner) {
	textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Caixa.png"));
	corpo->Bitmap->Assign(textura);
	corpo->Width = 52;
	corpo->Height = 52;
	corpo->Position->Point = TPointF(sx, sy);
	numVidas = 10;
	nome = "caixa";
	som = new TMediaPlayer(owner);
	som->FileName = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"bustcrate1.wav");
	i1 = "\n";
	i2 = "\n";
}

Caixa::~Caixa() {}

void Caixa::pegar() {
	j->colisaoMapaObs(this);
}

void Caixa::findar() {
	som->Play();
	corpo->Width = 0;
	corpo->Height = 0;
	srand(time(NULL));
	int x=0;
	Item* i = NULL;
	if (i1 != "\n") {
		//f->geraItem(pos.x - 50, pos.y - 20, i1);
		if (i1[0] == 'c' && i1[1] == 'h') {
			string aux, aux2;
			for (int x = 0; x < 5; x++) aux.push_back(i1[x]);
			i = f->geraItem(pos.x - 50, pos.y - 20, aux);
			aux2.push_back(i1[6]);
			aux2.push_back(i1[7]);
			static_cast <Chave*> (i)->setString(aux2);
		}
		else f->geraItem(pos.x - 50, pos.y - 20, i1);
	}
	

	else {
		int x = rand() % 5;
		if (x == 0) f->geraItem(pos.x - 50, pos.y - 20, "municaoskorpion");
		else if (x == 1) f->geraItem(pos.x - 50, pos.y - 20, "medpack");
		else if (x == 2) f->geraItem(pos.x - 50, pos.y - 20, "pistola");
		else if (x == 3) f->geraItem(pos.x - 50, pos.y - 20, "municaomp5");
	}
	
	if (i2 != "\n") f->geraItem(pos.x + 50, pos.y - 20, i2);

	else {
		x = rand() % 5;
		if (x == 0) f->geraItem(pos.x + 50, pos.y - 20, "municaoskorpion");
		else if (x == 1) f->geraItem(pos.x + 50, pos.y - 20, "medpack");
		else if (x == 2) f->geraItem(pos.x + 50, pos.y - 20, "pistola");
		else if (x == 3) f->geraItem(pos.x + 50, pos.y - 20, "municaomp5");
	}
	
}

void Caixa::setI1(string s) { i1 = s; }

void Caixa::setI2(string s) { i2 = s; }

void Caixa::setFase(Fase* k) { f = k; }

string Caixa::getI1() { return i1; }

string Caixa::getI2() { return i2; }
