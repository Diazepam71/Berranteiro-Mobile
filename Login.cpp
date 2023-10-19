//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Login.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.LgXhdpiPh.fmx", _PLAT_ANDROID)

TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
	Menu = NULL;
	FDConnection1->Params->Values["Database"] =
		System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath
		(), "Ranking.db");
	FDConnection1->Params->Database = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath
		(), L"Ranking.db");
}
//---------------------------------------------------------------------------
void __fastcall TForm7::entrar(TObject *Sender)
{
	FDQuery1->Active = false;
	FDQuery1->SQL->Clear();
	FDQuery1->SQL->Text = "select count(*) as res from Ranking where Nome = '"+Edit1->Text+"';";
	FDQuery1->Active = true;
	if (FDQuery1->FieldByName("res")->AsString != "1") {
		 ShowMessage("Nome não cadastrado.");
		 return;
	}
    FDQuery1->Active = false;
	FDQuery1->SQL->Clear();
	FDQuery1->SQL->Text = "select count(*) as res from Ranking where Senha = '"+Edit2->Text+"';";
	FDQuery1->Active = true;
    if (FDQuery1->FieldByName("res")->AsString == "0") {
		 ShowMessage("Senha não cadastrada.");
		 return;
	}
	else {
		if (Menu == NULL) Menu = new TForm1(this);
		Menu->Show();
		this->Hide();
	}
	Menu->setUsuario(Edit1->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm7::cadastrar(TObject *Sender)
{
	FDQuery1->Active = false;
	FDQuery1->SQL->Clear();
	FDQuery1->SQL->Text = "select count(*) as res from Ranking where Nome = '"+Edit1->Text+"';";
	FDQuery1->Active = true;
	if (FDQuery1->FieldByName("res")->AsString != "0") {
		 ShowMessage("Nome já cadastrado.");
		 return;
	}
    FDQuery1->Active = false;
	FDQuery1->SQL->Clear();
	FDQuery1->SQL->Text = "insert into ranking values('"+Edit1->Text+"', '"+Edit2->Text+"', '0', '0', '0', '99:59:59', '99:59:59', '99:59:59');";
	FDQuery1->ExecSQL();
	if (Menu == NULL) Menu = new TForm1(this);
	Menu->Show();
	this->Hide();
	Menu->setUsuario(Edit1->Text);
}
//---------------------------------------------------------------------------
