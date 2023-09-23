//---------------------------------------------------------------------------

#ifndef Fase2H
#define Fase2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include "ImpFase2.h"
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button5;
	TButton *Button8;
	TButton *Button4;
	TTimer *Timer2;
	TButton *Button6;
	TButton *Button7;
	TTimer *Timer1;
	void __fastcall soltar_arma(TObject *Sender);
	void __fastcall trocar_arma(TObject *Sender);
	void __fastcall pular(TObject *Sender);
	void __fastcall esquerda(TObject *Sender);
	void __fastcall esquerda2(TObject *Sender);
	void __fastcall direita(TObject *Sender);
	void __fastcall direita2(TObject *Sender);
	void __fastcall recarregar(TObject *Sender);
	void __fastcall atacar2(TObject *Sender);
	void __fastcall atacar(TObject *Sender);
	void __fastcall loop(TObject *Sender);
private:	// User declarations
    ImpFase2* f1;
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
    void rolagem();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
