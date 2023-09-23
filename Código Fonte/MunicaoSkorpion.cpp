#include "MunicaoSkorpion.h"

using namespace Itens;

MunicaoSkorpion::MunicaoSkorpion(Jogador* jo, float sx, float sy, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner) : Item(jo, sx, sy, parent, owner) {
	textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Municao-Skorpion.png"));
	corpo->Bitmap->Assign(textura);
	corpo->Width = 20;
	corpo->Height = 20;
	corpo->Position->Point = TPointF(sx, sy);
	nome = "municaoskorpion";
	valor = 30;
}

MunicaoSkorpion::~MunicaoSkorpion() {}

void MunicaoSkorpion::pegar() {
	int i = 0;
	Arma* x;
	for (i = 1; i <= j->getl_arma()->getTam(); i -= -1) {
		x = j->getl_arma()->getElX(i)->getInfo();
		if (x->getNome() == "skorpion") {
			x->setAmmo(x->getAmmo() + valor);
			setVidas(0);
			string s = "Pegou " + to_string(valor) + " munições para Skorpion.";
			char arr[s.length() + 1];
			strcpy(arr, s.c_str());
			f->getInterface()->setInstrucao(System::UnicodeString(arr));
            corpo->Width = 0;
			corpo->Height = 0;
		}
	}

}