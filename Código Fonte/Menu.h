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
#include "Ranking.h"
#include "Teste.h"
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Phys.SQLiteWrapper.Stat.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <string>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TLabel *Label1;
	TLabel *Label2;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TFDConnection *FDConnection1;
	TFDQuery *FDQuery1;
	TFDGUIxWaitCursor *FDGUIxWaitCursor1;
	void __fastcall selecionarBotao(TObject *Sender);
	void __fastcall desselecionarBotao(TObject *Sender);
	void __fastcall executarFase1(TObject *Sender);
	void __fastcall executarFase2(TObject *Sender);
	void __fastcall executarFase3(TObject *Sender);
	void __fastcall executarRanking(TObject *Sender);
	void __fastcall login(TObject *Sender);
	void __fastcall resumir(TObject *Sender);
	//TForm2* fase1;
private:	// User declarations
	 TForm2* fase1;
	 TForm3* fase2;
	 TForm4* fase3;
	 TForm5* ranking;
     TForm6* teste;
public:		//User declarations
	__fastcall TForm1(TComponent* Owner);
	void mostrarItens();
	System::UnicodeString usuario;
	void setUsuario(System::UnicodeString s);
    void atualizaPontos();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
