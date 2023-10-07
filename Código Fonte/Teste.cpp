//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Teste.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.LgXhdpiPh.fmx", _PLAT_ANDROID)
#pragma resource ("*.GGlass.fmx", _PLAT_ANDROID)
#pragma resource ("*.Moto360.fmx", _PLAT_ANDROID)
#pragma resource ("*.SSW3.fmx", _PLAT_ANDROID)

TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
	//TPointF p (100, 100);
	//k = new Ente (p);
	//FullScreen = true;
	j = NULL;
	pColi = NULL;
	o = NULL;
	lista = new ListaEntes();
    FDConnection1->Params->Values["Database"] =
		System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath
		(), L"Ranking.db");
	FDConnection1->Params->Database = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath
		(), L"Ranking.db");

}
//---------------------------------------------------------------------------
void __fastcall TForm6::revolucao(TObject *Sender)
{
	FDQuery1->Active = false;
	FDQuery1->SQL->Clear();
	FDQuery1->SQL->Text = "select Nome, Pontos from Ranking order by Pontos desc";
	FDQuery1->Active = true;
    Label1->Text = FDQuery1->FieldByName("Nome")->AsString;
	Button1->Text = "Revolução iniciada.\n";
	this->Fill->Assign(Brush1->Brush);
	//Image1->Bitmap->LoadFromFile("J1Direita.png");
	//Image1->Bitmap->LoadFromFile(TPath::Combine(TPath::GetDocumentsPath(), 'J1Direita.png'));
	Image1->Bitmap->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"J1Direita.png"));
	//if (Image1->Canvas != NULL) Dialogs::ShowMessage("Canvas != NULL.");
	/*Image2 = new TImage(this);
    Image2->Height = 340;
	Image2->Width = 497;
	Image2->Position->X = 200;
	Image2->Position->Y = 100;
    Image2->Parent = this;
	Image2->Bitmap->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Onca.png"));


    //Image2->Align = TAlignLayout::Left;
	Image2->Bitmap->Canvas->BeginScene();
	Image2->Bitmap->Canvas->DrawBitmap(Image2->Bitmap, TRectF(0,0,497,340), TRectF(200, 100, 697, 440), 1.0);
	Image2->Bitmap->Canvas->EndScene();    */
	TPointF p (200, 100);
	//k = new Ente(p, this);
	//k->imprimir();
	j = new Jogador(this);
	//j->setPosX(200);
	//j->setPosY(100);
	j->setPos(p);
	o = new Onca(j, 500, 100, this);
	lista->add(o);
	//pColi = new GerenciadorColisao(lista, j);
}
//---------------------------------------------------------------------------
void __fastcall TForm6::teclaApertada(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if (Key == vkHardwareBack) {
		//this->MessageDlg("Sair?", TMsgDlgType::mtConfirmation);
		this->Fill->Assign(Brush2->Brush);
		Button1->Text = "Começar a Revolução";
		Key = 0;
		delete k;
        k = NULL;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm6::esquerda(TObject *Sender)
{
	//Image1->Position->X -= 2;
	j->setVelX(0);
	Button2->ResetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::direita(TObject *Sender)
{
	//Image1->Position->X += 2;
	j->setVelX(0);
	Button3->ResetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::loop(TObject *Sender)
{
	/*if (Button2->Pressed == true) if (j) j->setVelX(-2);
	if (Button3->Pressed == true) {
		if (j) j->setVelX(2);

	}
	if (Button2->Pressed == false && Button3->Pressed == false) if (j) j->setVelX(0);
	//if (k != NULL) k->getCorpo()->Canvas->DrawBitmap(k->getCorpo()->Bitmap, k->getCorpo()->BoundsRect, k->getPos(), 1);
	//if (k) k->imprimir();  */
	if (j) {
		j->move();
		j->cair();
	}
	if (o) {
		o->move();
        o->cair();
	}
	if (pColi) pColi->executar();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm6::moveEsq2(TObject *Sender)
{
    if (j) j->setVelX(-5);
}
//---------------------------------------------------------------------------

void __fastcall TForm6::moveDir2(TObject *Sender)
{
	if (j) j->setVelX(5);
}
//---------------------------------------------------------------------------



void __fastcall TForm6::fechar(TObject *Sender, TCloseAction &Action)
{
	delete lista;
	if (k) delete k;
	if (j) delete j;
    if (o) delete o;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::pular(TObject *Sender)
{
	if (j) j->setVelY(-6);
    Button4->ResetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::inicializa(TObject *Sender)
{
	FDConnection1->Params->Values["Database"] =
		System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath
		(), L"Ranking.db");
	FDConnection1->Params->Database = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath
		(), L"Ranking.db");
	ShowMessage("Arquivo Escolhido.");
}
//---------------------------------------------------------------------------


