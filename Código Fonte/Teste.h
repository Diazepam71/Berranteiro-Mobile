//---------------------------------------------------------------------------

#ifndef TesteH
#define TesteH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <System.Ioutils.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Objects.hpp>
#include "Jogador.h"
#include "Onca.h"
#include "GerenciadorColisao.h"
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Phys.SQLiteWrapper.Stat.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.Comp.UI.hpp>
using namespace Personagens;
using namespace Gerenciadores;
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TBrushObject *Brush1;
	TImage *Image1;
	TImageControl *ImageControl1;
	TBrushObject *BrushObject1;
	TBrushObject *Brush2;
	TButton *Button2;
	TButton *Button3;
	TTimer *Timer1;
	TButton *Button4;
	TBindingsList *BindingsList1;
	TFDConnection *FDConnection1;
	TLabel *Label1;
	TFDQuery *FDQuery1;
	TFDGUIxWaitCursor *FDGUIxWaitCursor1;
	void __fastcall revolucao(TObject *Sender);
	void __fastcall teclaApertada(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall esquerda(TObject *Sender);
	void __fastcall direita(TObject *Sender);
	void __fastcall loop(TObject *Sender);
	void __fastcall moveEsq2(TObject *Sender);
	void __fastcall moveDir2(TObject *Sender);
	void __fastcall fechar(TObject *Sender, TCloseAction &Action);
	void __fastcall pular(TObject *Sender);
	void __fastcall inicializa(TObject *Sender);
private:	// User declarations
	Ente* k;
	Jogador* j;
	Onca* o;
	ListaEntes* lista;
	GerenciadorColisao* pColi;
    TImage* Image2;
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
