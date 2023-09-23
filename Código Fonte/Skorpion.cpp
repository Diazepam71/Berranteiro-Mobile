#include "Skorpion.h"
#include "Arma.h"
using namespace Itens;

Skorpion::Skorpion(Jogador* jo, float sx, float sy, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner): Item(jo, sx, sy, parent, owner) {
	//if (!textura.loadFromFile("Midia/Imagens/Skorpion.png")) std::cout << "ERRO.\n";
	textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Skorpion.png"));
    corpo->Bitmap->Assign(textura);
	/*corpo.setTextureRect(sf::IntRect(0, 0, 300, 76));
	corpo.setTexture(textura);
	corpo.setPosition(sx, sy);
	corpo.setScale(0.4f, 0.4f); */
	corpo->Width = 120;
	corpo->Height = 30;
	//corpo->Scale->Point = TPointF(0.4, 0.4);
    corpo->Position->Point = TPointF(sx, sy);
	nome = "skorpion";
	ammo = 30;
	magvar = 30;
	Owner = owner;
    //som->FileName = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Load Gun.wav");
}

Skorpion::~Skorpion() {}

void Skorpion::pegar() {
	int i;
	Arma* x;
	bool flag = 0;
	for (i = 1; i <= j->getl_arma()->getTam(); i -= -1) {
		x = j->getl_arma()->getElX(i)->getInfo();
		if (x->getNome() == "skorpion") {
			x->setAmmo(x->getAmmo() + 90);
			flag = 1;
			f->getInterface()->setInstrucao(System::UnicodeString("Pegou outra Skorpion - Municao aproveitada."));
			setVidas(0);
			return;
		}
	}
	if (j->getl_arma()->getTam() >= 3) {
		f->getInterface()->setInstrucao(System::UnicodeString("INVENTÁRIO CHEIO."));
		return;
	}
	if (flag == 0) {
		Arma* sk = new Arma("skorpion", Owner);
		sk->setAmmo(ammo);
		sk->setMagvar(magvar);
		j->getl_arma()->incluirEl(sk);
		f->getInterface()->setInstrucao(System::UnicodeString("Pegou uma Skorpion."));
	}

	setVidas(0);

}

void Skorpion::findar() {
	corpo->Width = 0;
	corpo->Height = 0;

}