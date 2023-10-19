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
	SpeedButton1->BringToFront();
	SpeedButton2->BringToFront();
	SpeedButton3->BringToFront();

    SpeedButton1->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::Blue;
	SpeedButton2->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::Black;
	SpeedButton3->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::Black;
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


void __fastcall TForm5::mostra_f1(TObject *Sender)
{
	SpeedButton1->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::Blue;
	SpeedButton2->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::Black;
	SpeedButton3->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::Black;

	ListView1->Items->Clear();
	ListView2->Items->Clear();
	if (SpeedButton4->TextSettings->FontColor != unsigned(0xff000000)) {
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
	else if (SpeedButton5->TextSettings->FontColor != unsigned(0xff000000)) {
		FDQuery1->Active = false;
		FDQuery1->SQL->Clear();
		FDQuery1->SQL->Text = "select Nome, Tempo_F1 from Ranking where Tempo_F1 not null order by Tempo_F1 asc";
		FDQuery1->Active = true;
		for (int i = 0; i < FDQuery1->RecordCount; i-=-1) {
			ListView1->Items->Insert(i)->Text = FDQuery1->FieldByName("Nome")->AsString;
			ListView2->Items->Insert(i)->Text = FDQuery1->FieldByName("Tempo_F1")->AsString;
			FDQuery1->MoveBy(1);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm5::mostra_f2(TObject *Sender)
{
	SpeedButton2->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::Blue;
	SpeedButton1->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::Black;
	SpeedButton3->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::Black;

	ListView1->Items->Clear();
	ListView2->Items->Clear();
	if (SpeedButton4->TextSettings->FontColor != unsigned(0xff000000)) {
		FDQuery1->Active = false;
		FDQuery1->SQL->Clear();
		FDQuery1->SQL->Text = "select Nome, Pontos_F2 from Ranking order by Pontos_F2 desc";
		FDQuery1->Active = true;
		for (int i = 0; i < FDQuery1->RecordCount; i-=-1) {
			ListView1->Items->Insert(i)->Text = FDQuery1->FieldByName("Nome")->AsString;
			ListView2->Items->Insert(i)->Text = FDQuery1->FieldByName("Pontos_F2")->AsString;
			FDQuery1->MoveBy(1);
		}
	}
	else if (SpeedButton5->TextSettings->FontColor != unsigned(0xff000000)) {
		FDQuery1->Active = false;
		FDQuery1->SQL->Clear();
		FDQuery1->SQL->Text = "select Nome, Tempo_F2 from Ranking where Tempo_F2 not null order by Tempo_F2 asc";
		FDQuery1->Active = true;
		for (int i = 0; i < FDQuery1->RecordCount; i-=-1) {
			ListView1->Items->Insert(i)->Text = FDQuery1->FieldByName("Nome")->AsString;
			ListView2->Items->Insert(i)->Text = FDQuery1->FieldByName("Tempo_F2")->AsString;
			FDQuery1->MoveBy(1);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm5::mostra_f3(TObject *Sender)
{
	SpeedButton3->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::Blue;
	SpeedButton2->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::Black;
	SpeedButton1->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::Black;

	ListView1->Items->Clear();
	ListView2->Items->Clear();
	if (SpeedButton4->TextSettings->FontColor != unsigned(0xff000000)) {
		FDQuery1->Active = false;
		FDQuery1->SQL->Clear();
		FDQuery1->SQL->Text = "select Nome, Pontos_F3 from Ranking order by Pontos_F3 desc";
		FDQuery1->Active = true;
		for (int i = 0; i < FDQuery1->RecordCount; i-=-1) {
			ListView1->Items->Insert(i)->Text = FDQuery1->FieldByName("Nome")->AsString;
			ListView2->Items->Insert(i)->Text = FDQuery1->FieldByName("Pontos_F3")->AsString;
			FDQuery1->MoveBy(1);
		}
	}
	else if (SpeedButton5->TextSettings->FontColor != unsigned(0xff000000)) {
		FDQuery1->Active = false;
		FDQuery1->SQL->Clear();
		FDQuery1->SQL->Text = "select Nome, Tempo_F3 from Ranking where Tempo_F3 not null order by Tempo_F3 asc";
		FDQuery1->Active = true;
		for (int i = 0; i < FDQuery1->RecordCount; i-=-1) {
			ListView1->Items->Insert(i)->Text = FDQuery1->FieldByName("Nome")->AsString;
			ListView2->Items->Insert(i)->Text = FDQuery1->FieldByName("Tempo_F3")->AsString;
			FDQuery1->MoveBy(1);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm5::mostra_pontos(TObject *Sender)
{
	SpeedButton4->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::Blue;
	SpeedButton5->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::Black;

	if (SpeedButton1->TextSettings->FontColor != unsigned(0xff000000)) mostra_f1(SpeedButton4);
	else if (SpeedButton2->TextSettings->FontColor != unsigned(0xff000000)) mostra_f2(SpeedButton4);
	else if (SpeedButton3->TextSettings->FontColor != unsigned(0xff000000)) mostra_f3(SpeedButton4);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::mostra_tempo(TObject *Sender)
{
	SpeedButton5->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::Blue;
	SpeedButton4->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::Black;

	if (SpeedButton1->TextSettings->FontColor != unsigned(0xff000000)) mostra_f1(SpeedButton5);
	else if (SpeedButton2->TextSettings->FontColor != unsigned(0xff000000)) mostra_f2(SpeedButton5);
	else if (SpeedButton3->TextSettings->FontColor != unsigned(0xff000000)) mostra_f3(SpeedButton5);
}
//---------------------------------------------------------------------------

