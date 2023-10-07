//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Menu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.LgXhdpiPh.fmx", _PLAT_ANDROID)

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	fase1 = NULL;
	fase2 = NULL;
	fase3 = NULL;
    FDConnection1->Params->Values["Database"] =
		System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath
		(), "Ranking.db");
	FDConnection1->Params->Database = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath
		(), L"Ranking.db");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::selecionarBotao(TObject *Sender)
{
	dynamic_cast <TButton*> (Sender)->FontColor = TAlphaColor(TAlphaColorRec::Blue);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::desselecionarBotao(TObject *Sender)
{
	dynamic_cast <TButton*> (Sender)->FontColor = TAlphaColor(TAlphaColorRec::White);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::executarFase1(TObject *Sender)
{
	clock_t timer = clock();
	//Button1->Visible = false;
	//Label1->Visible = false;
	//Label2->Visible = true;
	if (fase2) {
		delete fase2;
		fase2 = NULL;
	}
	if (fase3) {
		delete fase3;
		fase3 = NULL;
	}
	fase1 = new TForm2(this);
	//Label2->Visible = false;
	fase1->Show();
	Hide();
	ShowMessage("Total: ");
	ShowMessage((float) (clock() - timer) /CLOCKS_PER_SEC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::executarFase2(TObject *Sender)
{
	clock_t timer = clock();
	//Button1->Visible = false;
	//Label1->Visible = false;
	//Label2->Visible = true;
	if (fase1) {
		delete fase1;
		fase1 = NULL;
	}
	if (fase3) {
		delete fase3;
		fase3 = NULL;
	}
	fase2 = new TForm3(this);
	//Label2->Visible = false;
	fase2->Show();
	Hide();
	ShowMessage("Total: ");
	ShowMessage((float) (clock() - timer) /CLOCKS_PER_SEC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::executarFase3(TObject *Sender)
{
    clock_t timer = clock();
	//Button1->Visible = false;
	//Label1->Visible = false;
	//Label2->Visible = true;
	if (fase1) {
		delete fase1;
		fase1 = NULL;
	}
	if (fase2) {
		delete fase2;
		fase2 = NULL;
	}
	fase3 = new TForm4(this);
	//Label2->Visible = false;
	fase3->Show();
	Hide();
	ShowMessage("Total: ");
	ShowMessage((float) (clock() - timer) /CLOCKS_PER_SEC);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::executarRanking(TObject *Sender)
{
	ranking = new TForm5(this);
	ranking->Show();
	//teste = new TForm6(this);
    //teste->Show();
	this->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::login(TObject *Sender)
{
	dynamic_cast <TForm*> (this->Owner)->Show();
	this->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::resumir(TObject *Sender)
{
	if (fase1 == NULL && fase2 == NULL && fase3 == NULL) return;
	if (fase1) {
		fase1->Show();
		fase1->Timer1->Enabled = true;
	}
	else if (fase2) {
		fase2->Show();
		fase2->Timer1->Enabled = true;
	}
	else if (fase3) {
		fase3->Show();
		fase3->Timer1->Enabled = true;
	}
    this->Hide();
}
//---------------------------------------------------------------------------
void TForm1::mostrarItens() {
	Label1->BringToFront();
	Label1->Visible = true;
	Button1->BringToFront();
	Button1->Visible = true;
	Button2->BringToFront();
	Button2->Visible = true;
	Button3->BringToFront();
	Button3->Visible = true;
	Button4->BringToFront();
	Button4->Visible = true;
	Button5->BringToFront();
	Button5->Visible = true;
	Button6->BringToFront();
	Button6->Visible = true;
}

void TForm1::setUsuario(System::UnicodeString s) { usuario = s; };

void TForm1::atualizaPontos() {
	int total = 0;
	if (fase1) total = fase1->getF1()->getJogador()->getPontos();
	else if (fase2) total = fase2->getF2()->getJogador()->getPontos();
	else if (fase3) total = fase3->getF3()->getJogador()->getPontos();


    FDQuery1->Active = false;
	FDQuery1->SQL->Clear();
	if (fase1) FDQuery1->SQL->Text = "select Pontos_F1 as pontos from Ranking where Nome = '"+usuario+"';";
	else if (fase2) FDQuery1->SQL->Text = "select Pontos_F2 as pontos from Ranking where Nome = '"+usuario+"';";
	else if (fase3) FDQuery1->SQL->Text = "select Pontos_F3 as pontos from Ranking where Nome = '"+usuario+"';";
	FDQuery1->Active = true;

	if (FDQuery1->FieldByName("pontos")->AsInteger >= total) return;



	FDQuery1->Active = false;
	FDQuery1->SQL->Clear();
	if (fase1) FDQuery1->SQL->Text = "update Ranking set Pontos_F1 = "+System::UnicodeString((int) fase1->getF1()->getJogador()->getPontos())+" where Nome = '"+usuario+"';";
	else if (fase2) FDQuery1->SQL->Text = "update Ranking set Pontos_F2 = "+System::UnicodeString((int) fase2->getF2()->getJogador()->getPontos())+" where Nome = '"+usuario+"';";
	else if (fase3) FDQuery1->SQL->Text = "update Ranking set Pontos_F3 = "+System::UnicodeString((int) fase3->getF3()->getJogador()->getPontos())+" where Nome = '"+usuario+"';";
	FDQuery1->ExecSQL();
}

