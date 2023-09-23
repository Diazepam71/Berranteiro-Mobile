#include "MP5.h"
#include "Arma.h"
using namespace Itens;

MP5::MP5(Jogador* jo, float sx, float sy, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner): Item(jo, sx, sy, parent, owner) {
	//if (!textura.loadFromFile("Midia/Imagens/Skorpion.png")) std::cout << "ERRO.\n";
	textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"MP5.png"));
	corpo->Bitmap->Assign(textura);
	/*corpo.setTextureRect(sf::IntRect(0, 0, 300, 76));
	corpo.setTexture(textura);
	corpo.setPosition(sx, sy);
	corpo.setScale(0.4f, 0.4f); */
	corpo->Width = 80;
	corpo->Height = 28;
	//corpo->Scale->Point = TPointF(0.4, 0.4);
    corpo->Position->Point = TPointF(sx, sy);
	nome = "mp5";
	ammo = 32;
	magvar = 32;
	Owner = owner;
    //som->FileName = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Load Gun.wav");
}

MP5::~MP5() {}

void MP5::pegar() {
	int i;
	Arma* x;
	bool flag = 0;
	for (i = 1; i <= j->getl_arma()->getTam(); i -= -1) {
		x = j->getl_arma()->getElX(i)->getInfo();
		if (x->getNome() == "mp5") {
			x->setAmmo(x->getAmmo() + 128);
			flag = 1;
			f->getInterface()->setInstrucao(System::UnicodeString("Pegou outra MP5 - Municao aproveitada."));
			setVidas(0);
			return;
		}
	}
	if (j->getl_arma()->getTam() >= 3) {
		f->getInterface()->setInstrucao(System::UnicodeString("INVENTÁRIO CHEIO."));
		return;
	}
	if (flag == 0) {
		Arma* sk = new Arma("mp5", Owner);
		sk->setAmmo(ammo);
		sk->setMagvar(magvar);
		j->getl_arma()->incluirEl(sk);
		f->getInterface()->setInstrucao(System::UnicodeString("Pegou uma MP5."));
	}

	setVidas(0);

}

void MP5::findar() {
	corpo->Width = 0;
	corpo->Height = 0;

}
