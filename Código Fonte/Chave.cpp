#include "Chave.h"
#include "Arma.h"
#include <string.h>
using namespace Itens;

Chave::Chave(Jogador* jo, float sx, float sy, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner) : Item(jo, sx, sy, parent, owner) {
	textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Chave.png"));
	corpo->Bitmap->Assign(textura);
	corpo->Width = 65;
	corpo->Height = 29;
	corpo->Position->Point = TPointF(sx, sy);
	nome = "chave";
	s = new string;
	f = NULL;
}

Chave::~Chave() {
	delete s;
}

void Chave::setString(string s0) { *s = s0; };

void Chave::pegar() {
	j->getItens()->incluirEl(s);
	setVivo(false);
	string s1 = "CHAVE " + *s + " OBTIDA!";
	char arr[s1.length() + 1];
	strcpy(arr, (s1.c_str()));
	f->getInterface()->setInstrucao(System::UnicodeString(arr));
    findar();
}

void Chave::setVidas(int n) {}

void Chave::findar() {
    corpo->Width = 0;
	corpo->Height = 0;
}