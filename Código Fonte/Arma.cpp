#include "Arma.h"
#include <System.Ioutils.hpp>
#include <iostream>

Arma::Arma(string n, System::Classes::TComponent* owner) {
	t0 = 0;
	tr = 0;
	nome = n;
	//inimigo = i;
	//ShowMessage("Construindo MPs...");
	e = new TMediaPlayer(owner);
	s = new TMediaPlayer(owner);
	d = new TMediaPlayer(owner);
	r = new TMediaPlayer(owner);
	r0 = new TMediaPlayer(owner);
	r1 = new TMediaPlayer(owner);
	Tesq = new TBitmap();
	Tdir = new TBitmap();
	Aesq = new TBitmap();
	Adir = new TBitmap();
	//ShowMessage("Definindo FileNames...");
	r0->FileName = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Load Gun.wav");

	//r0->FileName = r;
	d->FileName = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"dryfire1.wav");
	if (nome == "zero") {
		cad = 1;
		rec = 0;
		dano = 10;
		hitscan = 0;
		mag = -1;
		//ShowMessage("Carregando Imagens para 'zero'...");

		Tesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"J1Esquerda.png"));
		Tdir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"J1Direita.png"));
		Adir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"J1AtaqueDireita.png"));
		Aesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"J1AtaqueEsquerda.png"));

	}
	else if (nome == "skorpion" || nome == "skorpion-s") {
		cad = 10;
		dano = 20;
		rec = 1.25;
		alc = 640;
		hitscan = 1;
		mag = 30;
		magvar = 30;
		ammo = 180;
		if(nome == "skorpion")
		{
			Tesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Skorpion-E.png"));
			Tdir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Skorpion-D.png"));
			Adir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Skorpion-AD.png"));
			Aesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Skorpion-AE.png"));
		}
		else
		{
			mag = 180;
			magvar = 180;
		}
		//if (!s->loadFromFile("Midia/Musicas/sbarrel1.ogg")) std::cout << "ERRO.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nERRO.\n";
		//e->loadFromFile("Midia/Musicas/Load Gun.wav");
		s->FileName = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"sbarrel1.ogg");
		r1->FileName = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"sbarrel1.ogg");
		e->FileName = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Load Gun.wav");
	}
	else if (nome == "pistola") {
		cad = 5;
		dano = 10;
		rec = 0.75;
		alc = 480;
		hitscan = 1;
		mag = 12;
		magvar = 12;
		ammo = 60;

		Tesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Pistola-E.png"));
		Tdir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Pistola-D.png"));
		Adir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Pistola-AD.png"));
		Aesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Pistola-AE.png"));


		s->FileName = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Pistol.wav");
		r1->FileName = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Pistol.wav");
		e->FileName = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Load Gun.wav");
	}
	else if (nome == "mp5" || nome == "mp5-s") {
		cad = 18;
		dano = 8;
		rec = 1;
		alc = 560;
		hitscan = 1;
		mag = 32;
		magvar = 32;
		ammo = 320;
		if(nome == "mp5")
		{
			Tesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"MP5-E.png"));
			Tdir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"MP5-D.png"));
			Adir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"MP5-AD.png"));
			Aesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"MP5-AE.png"));
		}
		else
		{
			mag = 320;
			magvar = 320;
		}
		s->FileName = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"MP5.wav");
        r1->FileName = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"MP5.wav");
		e->FileName = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Load Gun.wav");
	}
    //ShowMessage("Construcao concluida!");
}

Arma::~Arma() {
	delete s;
	delete e;
	delete d;
	delete r;
	delete r0;
	delete Aesq;
	delete Adir;
	delete Tdir;
    delete Tesq;
}

TBitmap* Arma::getTdir() { return Tdir; }

TBitmap* Arma::getTesq() { return Tesq; }

TBitmap* Arma::getAdir() { return Adir; }

TBitmap* Arma::getAesq() { return Aesq; }

void Arma::recarregar() {
	if (ammo > 0) {
		r0->Play();
		tr = clock();
		recarregando = 1;
	}
}

void Arma::verifReload() {
	clock_t at = clock();
	if (at / (float)CLOCKS_PER_SEC - tr / (float)CLOCKS_PER_SEC >= rec && recarregando == 1) {
		if (ammo > mag) magvar = mag;
		else magvar = ammo;
		dry = 0;
		recarregando = 0;
	}
	else if (recarregando == 1) dry = 1;
}