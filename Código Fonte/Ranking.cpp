//---------------------------------------------------------------------------

#include <fmx.h>
#include <System.Ioutils.hpp>
#pragma hdrstop

#include "Ranking.h"
#include "Menu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.LgXhdpiPh.fmx", _PLAT_ANDROID)

TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
	FDConnection1->Params->Values["Database"] =
		System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath
		(), "Ranking.db");
	FDConnection1->Params->Database = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath
		(), L"Ranking.db");
	FDQuery1->Active = false;
	FDQuery1->SQL->Clear();
	FDQuery1->SQL->Text = "select Nome, Pontos_F1 from Ranking order by Pontos_F1 desc";
	FDQuery1->Active = true;
	for (int i = 0; i < FDQuery1->RecordCount; i-=-1) {
		ListView1->Items->Insert(i)->Text = FDQuery1->FieldByName("Nome")->AsString;
		ListView2->Items->Insert(i)->Text = FDQuery1->FieldByName("Pontos_F1")->AsString;
		FDQuery1->MoveBy(1);
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm5::inicializa(TObject *Sender)
{
	#if defined(_PLAT_IOS) || defined(_PLAT_ANDROID)
    FDConnection1->Params->Values["Database"] =
        System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath
		(), "Ranking.db");
	#endif
	//ShowMessage("Arquivo Escolhido.");
}
//---------------------------------------------------------------------------
void __fastcall TForm5::criaTabela(TObject *Sender)
{
	//FDConnection1->ExecSQL("create table if not exists Ranking (\"Nome\" TEXT, \"Senha\" TEXT, \"Pontos\" INTEGER);");
	//ShowMessage("Tabela Criada.");
}
//---------------------------------------------------------------------------
void __fastcall TForm5::msg(TObject *Sender)
{
	//ShowMessage("Construção Finalizada");
}
//---------------------------------------------------------------------------


void __fastcall TForm5::teclaApertada(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if (Key == vkHardwareBack) {
		Key = 0;
		dynamic_cast <TForm*> (this->Owner)->Show();
		this->Hide();
		dynamic_cast <TForm1*> (this->Owner)->mostrarItens();
	}
}
//---------------------------------------------------------------------------

