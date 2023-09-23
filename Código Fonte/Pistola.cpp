#include "Pistola.h"
#include "Arma.h"
using namespace Itens;

Pistola::Pistola(Jogador* jo, float sx, float sy, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner): Item(jo, sx, sy, parent, owner) {
	//if (!textura.loadFromFile("Midia/Imagens/Skorpion.png")) std::cout << "ERRO.\n";
	textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Pistola.png"));
    corpo->Bitmap->Assign(textura);
	/*corpo.setTextureRect(sf::IntRect(0, 0, 300, 76));
	corpo.setTexture(textura);
	corpo.setPosition(sx, sy);
	corpo.setScale(0.4f, 0.4f); */
	corpo->Width = 52;
	corpo->Height = 28;
	//corpo->Scale->Point = TPointF(0.4, 0.4);
	corpo->Position->Point = TPointF(sx, sy);
	nome = "pistola";
	ammo = 24;
	magvar = 12;
	Owner = owner;
    //som->FileName = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Load Gun.wav");
}

Pistola::~Pistola() {}

void Pistola::pegar() {
	bool chk = 0;
	int i = 1;
	for (i = 1; i <= j->getl_arma()->getTam(); i++) {
		if (j->getl_arma()->getElX(i)->getInfo()->getNome() == "pistola") {
			chk = 1;
			break;
		}
	}

	if (chk == 0) {
		if (j->getl_arma()->getTam() >= 3) {
			f->getInterface()->setInstrucao(System::UnicodeString("INVENTÁRIO CHEIO."));
			return;
		}
		Arma* sk = new Arma("pistola", Owner);
		sk->setAmmo(ammo);
		sk->setMagvar(magvar);
		j->getl_arma()->incluirEl(sk);
		f->getInterface()->setInstrucao(System::UnicodeString("Pegou uma Pistola."));
	}

	else {
		Arma* x = j->getl_arma()->getElX(i)->getInfo();
		x->setAmmo(x->getAmmo() + ammo);
		x->setCad(x->getCad() * 2);
		x->setRec(x->getRec() * 3);
		x->setMag(x->getMag() * 2);
		x->setMagvar(x->getMagvar() + magvar);
		x->setNome("pistola_d");
		x->setAesq(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"2Pistolas-AE.png"));
		x->setTesq(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"2Pistolas-E.png"));
		x->setAdir(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"2Pistolas-AD.png"));
		x->setTdir(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"2Pistolas-D.png"));
		f->getInterface()->setInstrucao(System::UnicodeString("Pegou uma segunda Pistola."));
	}

	setVidas(0);

}

void Pistola::findar() {
	corpo->Width = 0;
	corpo->Height = 0;

}
