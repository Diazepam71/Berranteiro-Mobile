#include "MunicaoMP5.h"

using namespace Itens;

MunicaoMP5::MunicaoMP5(Jogador* jo, float sx, float sy, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner) : Item(jo, sx, sy, parent, owner) {
	textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Municao-MP5.png"));
	corpo->Bitmap->Assign(textura);
	corpo->Width = 16;
	corpo->Height = 26;
	corpo->Position->Point = TPointF(sx, sy);
	nome = "municaomp5";
	valor = 32;
}

MunicaoMP5::~MunicaoMP5() {}

void MunicaoMP5::pegar() {
	int i = 0;
	Arma* x;
	for (i = 1; i <= j->getl_arma()->getTam(); i -= -1) {
		x = j->getl_arma()->getElX(i)->getInfo();
		if (x->getNome() == "mp5") {
			x->setAmmo(x->getAmmo() + valor);
			setVidas(0);
			string s = "Pegou " + to_string(valor) + " munições para MP5.";
			char arr[s.length() + 1];
			strcpy(arr, s.c_str());
			f->getInterface()->setInstrucao(System::UnicodeString(arr));
            corpo->Width = 0;
			corpo->Height = 0;
		}
	}

}