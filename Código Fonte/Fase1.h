//---------------------------------------------------------------------------

#ifndef Fase1H
#define Fase1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include "Mapa.h"
#include "ImpFase1.h"
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
using namespace Fases;
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TTimer *Timer1;
	TButton *Button4;
	TTimer *Timer2;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	void __fastcall loop(TObject *Sender);
	void __fastcall pular(TObject *Sender);
	void __fastcall esquerda(TObject *Sender);
	void __fastcall direita(TObject *Sender);
	void __fastcall quadro(TObject *Sender);
	void __fastcall esquerda2(TObject *Sender);
	void __fastcall direita2(TObject *Sender);
	void __fastcall alert(TObject *Sender);
	void __fastcall trocar_arma(TObject *Sender);
	void __fastcall atacar(TObject *Sender);
	void __fastcall atacar2(TObject *Sender);
	void __fastcall recarregar(TObject *Sender);
	void __fastcall soltar_arma(TObject *Sender);
	void __fastcall teclaApertada(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
private:	// User declarations
	//TBitmap* imagem;
	//Mapa* mapa;
	//Plataforma* p, *p1, *p2, *p3, *p01, *p02, *p03;
	ImpFase1* f1;
	//Interface* interf;
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
	void rolagem();
	ImpFase1* getF1() {return f1;};

};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
