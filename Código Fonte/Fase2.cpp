//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Fase2.h"
#include "Menu.h"
#include "Pistola.h"
#include "Skorpion.h"
#include "MP5.h"
using namespace Itens;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.LgXhdpiPh.fmx", _PLAT_ANDROID)

TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
    clock_t timer1 = clock();
	f1 = new ImpFase2(this, this);
	f1->getLista()->reposLista(-4000, -600);
    f1->getMapa2()->reposMapa(-4000, -600);
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
void __fastcall TForm3::soltar_arma(TObject *Sender)
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
void __fastcall TForm3::trocar_arma(TObject *Sender)
{
    f1->getJogador()->setArmaSel(f1->getJogador()->getArmaSel() + 1);
	int x = f1->getJogador()->getl_arma()->getTam();
	int as = f1->getJogador()->getArmaSel();
	if (as > x) f1->getJogador()->setArmaSel(as - x);

	f1->getJogador()->getl_arma()->getElX(f1->getJogador()->getArmaSel())->getInfo()->getSomEquip()->Play();

}
//---------------------------------------------------------------------------
void __fastcall TForm3::pular(TObject *Sender)
{
	f1->getJogador()->setVelY(-10);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::esquerda(TObject *Sender)
{
	f1->getJogador()->setVelX(0);
	Button1->ResetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::esquerda2(TObject *Sender)
{
	f1->getJogador()->setVelX(-8);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::direita(TObject *Sender)
{
    f1->getJogador()->setVelX(0);
	Button2->ResetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::direita2(TObject *Sender)
{
	f1->getJogador()->setVelX(8);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::recarregar(TObject *Sender)
{
	f1->getJogador()->getl_arma()->getElX(f1->getJogador()->getArmaSel())->getInfo()->recarregar();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::atacar2(TObject *Sender)
{
	f1->getJogador()->setAtacar(false);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::atacar(TObject *Sender)
{
    f1->getJogador()->setAtacar(true);
    f1->getJogador()->verifImg();
	f1->getJogador()->atirar();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::loop(TObject *Sender)
{
    f1->executar();
	rolagem();
	if (Button6->Pressed == true) atacar(Button6);
}
//---------------------------------------------------------------------------
void TForm3::rolagem() {
    if ((f1->getJogador()->getPos().y > 200 && f1->getJogador()->getVelY() > 0) || (f1->getJogador()->getPos().y < 80 && f1->getJogador()->getVelY() < 0)) {
		f1->getLista()->reposLista(0, -f1->getJogador()->getVelY());
		f1->getMapa2()->reposMapa(0, -f1->getJogador()->getVelY());
	}
	if ((f1->getJogador()->getPos().x > 400 && f1->getJogador()->getVelX() > 0)  || (f1->getJogador()->getPos().x < 100 && f1->getJogador()->getVelX() < 0)) {
		f1->getLista()->reposLista(-f1->getJogador()->getVelX(), 0);
        f1->getMapa2()->reposMapa(-f1->getJogador()->getVelX(), 0);
	}
}
