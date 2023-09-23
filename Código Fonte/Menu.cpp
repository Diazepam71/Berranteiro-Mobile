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
	fase3 = new TForm4(this);
	//Label2->Visible = false;
	fase3->Show();
	Hide();
	ShowMessage("Total: ");
	ShowMessage((float) (clock() - timer) /CLOCKS_PER_SEC);
}
//---------------------------------------------------------------------------

