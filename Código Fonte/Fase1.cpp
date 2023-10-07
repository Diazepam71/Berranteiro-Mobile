//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Fase1.h"
#include "Menu.h"
#include "Pistola.h"
#include "Skorpion.h"
#include "MP5.h"
#include "Menu.h"
#include <string>
#include <System.Ioutils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.LgXhdpiPh.fmx", _PLAT_ANDROID)
using namespace Itens;

TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	//imagem = new TBitmap();
	//imagem->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Fase1.png"));
	//mapa = new Mapa(TPointF(0, 0), TPointF(4000, 1120), imagem, this);
	//mapa->imprimir();
	//TBitmap* img = new TBitmap();

	/*img->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Teste Tilemap2.png"));
	TPointF* ponto = (TPointF*) malloc(sizeof(TPointF));
	*ponto = TPointF(0, 352);
	p = new Plataforma(ponto, img, this);
	free(ponto);
	p->setPos(TPointF(0, 352)); */
	//p1 = mapa->getLista()->getElX(1)->getInfo();
	//p2 = mapa->getLista()->getElX(2)->getInfo();
	//p3 = mapa->getLista()->getElX(3)->getInfo();

	clock_t timer1 = clock();
	f1 = new ImpFase1(this, this);
	ShowMessage("ImpFase1: ");
	ShowMessage((float) (clock() - timer1) / CLOCKS_PER_SEC);
	ShowMessage("Resto: ");
	clock_t timer2 = clock();
	f1->getJogador()->setOwner(this);
	f1->setJogador1(f1->getJogador());
	f1->getInterface()->emergencia(dynamic_cast <TForm1*> (Owner)->Label1->StyledSettings);
	Button1->BringToFront();
	Button2->BringToFront();
	Button3->BringToFront();
	Button5->BringToFront();
	Button6->BringToFront();
	Button7->BringToFront();
    Button8->BringToFront();
	//dynamic_cast <TForm*> (Owner)->Hide();
	//this->Show();
	ShowMessage((float) (clock() - timer2) / CLOCKS_PER_SEC);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::loop(TObject *Sender)
{
    //ShowMessage("LOOP.");
	f1->executar();
	rolagem();
	if (Button6->Pressed == true) atacar(Button6);
	/*f1->getJogador()->move();
	f1->getJogador()->cair();
    f1->getInimigos()->getLista()->getElX(1)->getInfo()->move();
	f1->getInimigos()->getLista()->getElX(1)->getInfo()->cair();
	f1->getGCol()->executar(); */

}
//---------------------------------------------------------------------------

void __fastcall TForm2::pular(TObject *Sender)
{
	f1->getJogador()->setVelY(-10);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::esquerda(TObject *Sender)
{
	f1->getJogador()->setVelX(0);
    Button1->ResetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::direita(TObject *Sender)
{
	f1->getJogador()->setVelX(0);
	Button2->ResetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::quadro(TObject *Sender)
{
	clock_t t = clock();
	f1->executar();
	float time = clock() - t;
	time = time /CLOCKS_PER_SEC;
	string s;
	s = to_string(time);
    ShowMessage(time);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::esquerda2(TObject *Sender)
{
	f1->getJogador()->setVelX(-8);

}
//---------------------------------------------------------------------------

void __fastcall TForm2::direita2(TObject *Sender)
{
	f1->getJogador()->setVelX(8);

}
//---------------------------------------------------------------------------

void TForm2::rolagem() {
	if ((f1->getJogador()->getPos().y > 200 && f1->getJogador()->getVelY() > 0) || (f1->getJogador()->getPos().y < 80 && f1->getJogador()->getVelY() < 0)) {
		f1->getLista()->reposLista(0, -f1->getJogador()->getVelY());
		f1->getMapa2()->reposMapa(0, -f1->getJogador()->getVelY());
	}
	if ((f1->getJogador()->getPos().x > 400 && f1->getJogador()->getVelX() > 0)  || (f1->getJogador()->getPos().x < 100 && f1->getJogador()->getVelX() < 0)) {
		f1->getLista()->reposLista(-f1->getJogador()->getVelX(), 0);
        f1->getMapa2()->reposMapa(-f1->getJogador()->getVelX(), 0);
    }
}

void __fastcall TForm2::alert(TObject *Sender)
{
	//float f = f1->getMapa2()->getLista()->getElX(15)->getInfo()->getPos().x;
    //ShowMessage(f);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::trocar_arma(TObject *Sender)
{
	f1->getJogador()->setArmaSel(f1->getJogador()->getArmaSel() + 1);
	int x = f1->getJogador()->getl_arma()->getTam();
	int as = f1->getJogador()->getArmaSel();
	if (as > x) f1->getJogador()->setArmaSel(as - x);

	f1->getJogador()->getl_arma()->getElX(f1->getJogador()->getArmaSel())->getInfo()->getSomEquip()->Play();
    //ShowMessage(f1->getJogador()->getArmaSel());
}
//---------------------------------------------------------------------------

void __fastcall TForm2::atacar(TObject *Sender)
{
	f1->getJogador()->setAtacar(true);
    f1->getJogador()->verifImg();
	//Arma* x = f1->getJogador()->getl_arma()->getElX(f1->getJogador()->getArmaSel())->getInfo();
	//clock_t t1 = clock();
	//if (x->getSom()->State == TMediaState::Playing && t1 / (float) CLOCKS_PER_SEC - x->getClock() / (float) CLOCKS_PER_SEC >= 1.0 / x->getCad()) x->getSom()->Stop();
	f1->getJogador()->atirar();
	//dynamic_cast <TButton*> (Sender)->ResetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::atacar2(TObject *Sender)
{
	f1->getJogador()->setAtacar(false);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::recarregar(TObject *Sender)
{
	f1->getJogador()->getl_arma()->getElX(f1->getJogador()->getArmaSel())->getInfo()->recarregar();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::soltar_arma(TObject *Sender)
{
	Jogador* j1 = f1->getJogador();
	Arma* x = j1->getl_arma()->getElX(j1->getArmaSel())->getInfo();
    if (x->getNome() == "zero") return;
    if (x->getNome() == "pistola_d") {
        Arma* y = new Arma("pistola", this);
		j1->getl_arma()->incluirEl(y);
        y->setAmmo(x->getAmmo());
        j1->getl_arma()->removeElX(j1->getArmaSel());
		j1->setArmaSel(j1->getl_arma()->getTam());
		Item* i = f1->geraItem(j1->getPos().x + 100 - j1->getVirado() * 200, j1->getPos().y + 30, "pistola");
		static_cast <Pistola*> (i)->setammo(0);
		static_cast <Pistola*> (i)->setmagvar(0);
		if (x->getMagvar() > 12) x->setMagvar(12);
	}
    else {
        string s = x->getNome();
        j1->getl_arma()->removeElX(j1->getArmaSel());
        Item* i = f1->geraItem(j1->getPos().x + 100 - j1->getVirado() * 200, j1->getPos().y + 30, s);
        j1->setArmaSel(j1->getArmaSel() - 1);
        if (s == "skorpion") {
            static_cast <Skorpion*> (i)->setammo(x->getAmmo());
            static_cast <Skorpion*> (i)->setmagvar(x->getMagvar());
        }
        else if (s == "mp5") {
            static_cast <MP5*> (i)->setammo(x->getAmmo());
            static_cast <MP5*> (i)->setmagvar(x->getMagvar());
        }
        else if (s == "pistola") {
            static_cast <Pistola*> (i)->setammo(x->getAmmo());
            static_cast <Pistola*> (i)->setmagvar(x->getMagvar());
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::teclaApertada(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if (Key == vkHardwareBack) {
        Timer1->Enabled = false;
		Key = 0;
		dynamic_cast <TForm*> (this->Owner)->Show();
		this->Hide();
		dynamic_cast <TForm1*> (this->Owner)->atualizaPontos();
	}
}
//---------------------------------------------------------------------------

