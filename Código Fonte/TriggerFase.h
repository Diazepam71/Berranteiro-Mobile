//---------------------------------------------------------------------------

#ifndef TriggerFaseH
#define TriggerFaseH
#include "Item.h"
#include "Fase.h"
#include "Construtor.h"
using namespace Fases;

class TriggerFase : public Item {
private:
	Fase* fAtual;
	int fNova;
	System::Classes::TComponent* Owner;
    Construtor* construtor;

public:
	TriggerFase(int fase, Jogador* jo, float x, float y,
	Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner);
	~TriggerFase();
	void setFAtual(Fase* f);
	void setFaseNova(int nova);
	void pegar();
	void setWidth(float f);
	void setHeight(float f);
    void setVidas(int n) {};
};
//---------------------------------------------------------------------------
#endif
