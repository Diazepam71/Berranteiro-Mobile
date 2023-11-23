//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Construtor.h"
#include "ImpFase1.h"
#include "ImpFase2.h"
#include "ImpFase3.h"
#include "Menu.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall Construtor::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall Construtor::Construtor(bool CreateSuspended)
	: TThread(CreateSuspended)
{
	num = 0;
	cont = 0;
	fase = NULL;
	executando = 0;
	Parent = NULL;
	Owner = NULL;
	fase1 = NULL;
	fase2 = NULL;
	fase3 = NULL;
}
//---------------------------------------------------------------------------
void __fastcall Construtor::Execute()
{
	NameThreadForDebugging(System::String(L"cfx"));
	//---- Place thread code here ----
	executando = 1;
	//Synchronize(msg);
	if (num == 1) {
		fase1 = new ImpFase1(Parent, Owner);
		executando = 2;
		//Synchronize(msg);
		//Synchronize(atualizaUI);
		//Synchronize(msg);
		//dynamic_cast <TForm1*> (Owner)->setF1(fase1);
		//fase1->Show();
	}
	else if (num == 2) {
		fase2 = new ImpFase2(Parent, Owner);
		fase2->getLista()->reposLista(-4000, -600);
		fase2->getMapa2()->reposMapa(-4000, -600);
		executando = 2;
	}
	else if (num == 3) {
		fase3 = new ImpFase3(Parent, Owner);
		executando = 2;
	}
	//Synchronize(msg);
	executando = 3;
}

int Construtor::getNum() {return num;};

void Construtor::setNum(int x) {num = x;};

Fase* Construtor::getFase() {return fase;};

void Construtor::setFase(Fase* f0) {fase = f0;};

int Construtor::getExecutando() {return executando;};

void Construtor::setExecutando(int b) {executando = b;};

void Construtor::setOwner(System::Classes::TComponent* owner) {Owner = owner;};

void Construtor::setParent(Fmx::Types::TFmxObject* parent) {Parent = parent;};

void __fastcall Construtor::executaFase() {
	/*if (num == 1) {
		fase1 = new TForm2(Owner);
        dynamic_cast <TForm*> (Owner)->Hide();
		dynamic_cast <TForm1*> (Owner)->setF1(fase1);
		fase1->Show();
	}
	else if (num == 2) {
		fase2 = new TForm3(Owner);
        dynamic_cast <TForm*> (Owner)->Hide();
		dynamic_cast <TForm1*> (Owner)->setF2(fase2);
		fase2->Show();
	}
	else if (num == 3) {
		fase3 = new TForm4(Owner);
        dynamic_cast <TForm*> (Owner)->Hide();
		dynamic_cast <TForm1*> (Owner)->setF3(fase3);
		fase3->Show();
    } */
}

void __fastcall Construtor::msg() {
	ShowMessage(cont);
	cont++;
}

void __fastcall Construtor::atualizaUI() {
	//ShowMessage("UI - inicio");
	//dynamic_cast <TForm1*> (Owner)->executarFase1(dynamic_cast <TForm1*> (Owner)->Button1);
	//TForm1::executarFase1(dynamic_cast <TForm1*> (Owner)->Button1);
    //ShowMessage("UI - fim");
}
//---------------------------------------------------------------------------
