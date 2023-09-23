//---------------------------------------------------------------------------

#ifndef MenuH
#define MenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include "Fase1.h"
#include "Fase2.h"
#include "Fase3.h"
#include "Teste.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TLabel *Label1;
	TLabel *Label2;
	TButton *Button2;
	TButton *Button3;
	void __fastcall selecionarBotao(TObject *Sender);
	void __fastcall desselecionarBotao(TObject *Sender);
	void __fastcall executarFase1(TObject *Sender);
	void __fastcall executarFase2(TObject *Sender);
	void __fastcall executarFase3(TObject *Sender);
	//TForm2* fase1;
private:	// User declarations
	 TForm2* fase1;
	 TForm3* fase2;
	 TForm4* fase3;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
