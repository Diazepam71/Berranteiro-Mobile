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
	construtor = NULL;
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
	setVidas(0);
	vivo = false;
	dynamic_cast <TForm1*> (Owner->Owner)->atualizaTempo();
	dynamic_cast <TForm1*> (Owner->Owner)->atualizaPontos();
	if (fNova == 0) {
		//dynamic_cast <TForm1*> (Owner->Owner)->atualizaPontos();
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

	//construtor = new Construtor(1);
	//construtor->setNum(fNova);
	//construtor->setOwner(Owner->Owner);
	//construtor->setParent(Owner->Owner);

	if (fNova == 1) {
		/*TForm2* f1 = new TForm2(Owner->Owner);
		dynamic_cast <TForm1*> (Owner->Owner)->setF1(f1);
		f1->Show();
		dynamic_cast <TForm*> (Owner)->Hide();
		dynamic_cast <TForm1*> (Owner->Owner)->atualizaPontos();
		delete Owner;*/
		dynamic_cast <TForm1*> (Owner)->Hide();
		dynamic_cast <TForm1*> (Owner->Owner)->Show();
		dynamic_cast <TForm1*> (Owner->Owner)->executarFase1(dynamic_cast <TForm1*> (Owner)->Button1);
		delete Owner;
	}
	else if (fNova == 2) {

		/*TForm3* f1 = new TForm3(Owner->Owner);
		dynamic_cast <TForm1*> (Owner->Owner)->setF2(f1);
		f1->Show();
		dynamic_cast <TForm*> (Owner)->Hide();

		delete Owner;*/
		//ShowMessage("fNova == 2");
		//ShowMessage("Carregando a fase...");
		//dynamic_cast <TForm1*> (Owner->Owner)->atualizaPontos();
		//ShowMessage("AtualizaPontos");
		dynamic_cast <TForm1*> (Owner->Owner)->executarFase2(dynamic_cast <TForm1*> (Owner->Owner)->Button2);
		dynamic_cast <TForm*> (Owner)->Hide();
		dynamic_cast <TForm1*> (Owner->Owner)->ShowCarregando();
		//ShowMessage("Show.");

		delete Owner;
	}
	else if (fNova == 3) {
		dynamic_cast <TForm1*> (Owner->Owner)->executarFase3(dynamic_cast <TForm1*> (Owner->Owner)->Button3);
		dynamic_cast <TForm*> (Owner)->Hide();
		dynamic_cast <TForm1*> (Owner->Owner)->ShowCarregando();
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
