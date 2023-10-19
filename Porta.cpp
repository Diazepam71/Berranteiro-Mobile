#include "Porta.h"
#include "Interface.h"

Porta::Porta(Jogador* jo, float sx, float sy, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner): Item(jo, sx, sy, parent, owner) {
	textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"PortaFechada.png"));
	corpo->Bitmap->Assign(textura);
	corpo->Width = 80;
	corpo->Height = 96;
	corpo->Position->Point = TPointF(sx, sy);
	nome = "porta";
	ativ = "\n";
	aberta = 0;
}

Porta::~Porta() {}

void Porta::pegar() {
	if (aberta == 0) for (int i = 1; i <= j->getItens()->getTam(); i++) if (*(j->getItens()->getElX(i)->getInfo()) == ativ) {
		textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"PortaAberta.png"));
        corpo->Bitmap->Assign(textura);
		aberta = 1;
		f->getInterface()->setInstrucao(System::UnicodeString("PORTA ABERTA!"));
	}
	if (aberta == 0) {
		string s = "OBTER A CHAVE " + ativ;
		char arr[s.length() + 1];
		strcpy(arr, s.c_str());
		f->getInterface()->setInstrucao(System::UnicodeString(arr));
		j->colisaoMapaObs(static_cast <Entidade*> (this));
		j->setVelY(j->getVelY() - 0.3);
	}
}

void Porta::setVidas(int n) {}