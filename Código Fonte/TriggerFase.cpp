//---------------------------------------------------------------------------

#pragma hdrstop

#include "TriggerFase.h"
#include "Fase1.h"
#include "Fase2.h"
#include "Fase3.h"
#include "Menu.h"

TriggerFase::TriggerFase(int fase, Jogador* jo, float x, float y,
Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner)
: Item(jo, x, y, parent, owner) {
	fNova = fase;
	nome = "trigger_fase";
	fAtual = NULL;
	if (fase == 0) {
		textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Bolo.png"));
		corpo->Bitmap->Assign(textura);
		corpo->Width = 100;
        corpo->Height = 104;
	}
	else {
        textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Nada.png"));
		corpo->Bitmap->Assign(textura);
		corpo->Width = 100;
		corpo->Height = 100;
    }

	corpo->Position->Point = TPointF(x, y);
    Owner = owner;
}

TriggerFase::~TriggerFase() {
	if (fNova == 1) {
		dynamic_cast <TForm1*> (Owner->Owner)->setF2(NULL);
		dynamic_cast <TForm1*> (Owner->Owner)->setF3(NULL);
	}
	else if (fNova == 2) {
		dynamic_cast <TForm1*> (Owner->Owner)->setF1(NULL);
		dynamic_cast <TForm1*> (Owner->Owner)->setF2(NULL);
	}
	else if (fNova == 3) {
		dynamic_cast <TForm1*> (Owner->Owner)->setF2(NULL);
		dynamic_cast <TForm1*> (Owner->Owner)->setF1(NULL);
	}
	if (fAtual) delete fAtual;
}

void TriggerFase::setFAtual(Fase* f) {
	fAtual = f;
}

void TriggerFase::setFaseNova(int fase) {
	fNova = fase;
}

void TriggerFase::pegar() {
	dynamic_cast <TForm1*> (Owner->Owner)->atualizaTempo();
	if (fNova == 0) {
		dynamic_cast <TForm1*> (Owner->Owner)->atualizaPontos();
		dynamic_cast <TForm1*> (Owner->Owner)->setF1(NULL);
		dynamic_cast <TForm1*> (Owner->Owner)->setF2(NULL);
		dynamic_cast <TForm1*> (Owner->Owner)->setF3(NULL);
        dynamic_cast <TForm*> (Owner)->Hide();
		dynamic_cast <TForm*> (Owner->Owner)->Show();
		delete Owner;
    }
	else if (fNova == 1) {
		dynamic_cast <TForm1*> (Owner->Owner)->setF2(NULL);
		dynamic_cast <TForm1*> (Owner->Owner)->setF3(NULL);
	}
	else if (fNova == 2) {
		dynamic_cast <TForm1*> (Owner->Owner)->setF1(NULL);
		dynamic_cast <TForm1*> (Owner->Owner)->setF3(NULL);
	}
	else if (fNova == 3) {
		dynamic_cast <TForm1*> (Owner->Owner)->setF2(NULL);
		dynamic_cast <TForm1*> (Owner->Owner)->setF1(NULL);
	}
	if (fNova == 1) {
		TForm2* f1 = new TForm2(Owner->Owner);
		dynamic_cast <TForm1*> (Owner->Owner)->setF1(f1);
		f1->Show();
		dynamic_cast <TForm*> (Owner)->Hide();
		dynamic_cast <TForm1*> (Owner->Owner)->atualizaPontos();
		delete Owner;
	}
	else if (fNova == 2) {
		TForm3* f1 = new TForm3(Owner->Owner);
		dynamic_cast <TForm1*> (Owner->Owner)->setF2(f1);
		f1->Show();
		dynamic_cast <TForm*> (Owner)->Hide();
		dynamic_cast <TForm1*> (Owner->Owner)->atualizaPontos();
		delete Owner;
	}
	else if (fNova == 3) {
		TForm4* f1 = new TForm4(Owner->Owner);
		dynamic_cast <TForm1*> (Owner->Owner)->setF3(f1);
		f1->Show();
		dynamic_cast <TForm*> (Owner)->Hide();
        dynamic_cast <TForm1*> (Owner->Owner)->atualizaPontos();
		delete Owner;
	}
	corpo->Width = 0;
	corpo->Height = 0;
    setVidas(0);
}

void TriggerFase::setWidth(float f) {
	corpo->Width = f;
}

void TriggerFase::setHeight(float f) {
    corpo->Height = f;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
