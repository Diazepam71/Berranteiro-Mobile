#include "Medpack.h"
#include "Arma.h"
#include <string>
using namespace Itens;

Medpack::Medpack(Jogador* jo, float sx, float sy, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner) : Item(jo, sx, sy, parent, owner) {
	textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"CorCheio.png"));
	corpo->Bitmap->Assign(textura);
	corpo->Width = 16;
	corpo->Height = 16;
	corpo->Position->Point = TPointF(sx, sy);
	//corpo.setScale(0.4f, 0.4f);
	nome = "medpack";
	valor = 10;
}

Medpack::~Medpack() {}

void Medpack::pegar() {
	if (j->getVidas() < j->getMaxVidas()) j->setVidas(j->getVidas() + valor);
	if (j->getVidas() > j->getMaxVidas()) j->setVidas(j->getMaxVidas());
	setVidas(0);
	string x;
	x = to_string(valor);
	string s =  "+"+x+" HP.";
	char arr[s.length() + 1];
	strcpy(arr, s.c_str());
	f->getInterface()->setInstrucao(System::UnicodeString(arr));
}

void Medpack::setValor(int f0) {
	valor = f0;
}