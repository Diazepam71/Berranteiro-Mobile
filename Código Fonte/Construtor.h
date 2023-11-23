//---------------------------------------------------------------------------

#ifndef ConstrutorH
#define ConstrutorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "Fase.h"
#include "Fase1.h"
#include "Fase2.h"
#include "Fase3.h"
using namespace Fases;
//---------------------------------------------------------------------------
class Construtor : public TThread
{
protected:
	void __fastcall Execute();
	int num;
    int cont;
	Fase* fase;
	int executando;
	System::Classes::TComponent* Owner;
	Fmx::Types::TFmxObject* Parent;
	ImpFase1* fase1;
	ImpFase2* fase2;
	ImpFase3* fase3;
public:
	__fastcall Construtor(bool CreateSuspended);
	void setNum(int x);
	int getNum();
	void setFase(Fase* f0);
	Fase* getFase();
	int getExecutando();
	void setExecutando(int b);
	void setOwner(System::Classes::TComponent* owner);
	void setParent(Fmx::Types::TFmxObject* parent);
	void __fastcall executaFase();
	void __fastcall msg();
	ImpFase1* getFase1() {return fase1;};
	ImpFase2* getFase2() {return fase2;};
    ImpFase3* getFase3() {return fase3;};
    void __fastcall atualizaUI();
};
//---------------------------------------------------------------------------
#endif
