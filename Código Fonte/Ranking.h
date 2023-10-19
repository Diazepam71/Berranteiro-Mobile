//---------------------------------------------------------------------------

#ifndef RankingH
#define RankingH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.BatchMove.hpp>
#include <FireDAC.Comp.BatchMove.Text.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Phys.SQLiteWrapper.Stat.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <FMX.ListView.Adapters.Base.hpp>
#include <FMX.ListView.Appearances.hpp>
#include <FMX.ListView.hpp>
#include <FMX.ListView.Types.hpp>
#include <FMX.Types.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TListView *ListView1;
	TListView *ListView2;
	TFDGUIxWaitCursor *FDGUIxWaitCursor1;
	TFDConnection *FDConnection1;
	TFDQuery *FDQuery1;
	TTimer *Timer1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton5;
	void __fastcall inicializa(TObject *Sender);
	void __fastcall criaTabela(TObject *Sender);
	void __fastcall msg(TObject *Sender);
	void __fastcall teclaApertada(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall mostra_f1(TObject *Sender);
	void __fastcall mostra_f2(TObject *Sender);
	void __fastcall mostra_f3(TObject *Sender);
	void __fastcall mostra_pontos(TObject *Sender);
	void __fastcall mostra_tempo(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
