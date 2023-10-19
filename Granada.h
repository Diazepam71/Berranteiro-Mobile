//---------------------------------------------------------------------------

#ifndef GranadaH
#define GranadaH

#include "Fase.h"
#include "Item.h"
using namespace Fases;

class Granada : public Item {
private:
	bool ativa, explode, explodindo, flag;
	Fase* f;
	clock_t inicio;
    System::Classes::TComponent* Owner;

public:
	Granada(Jogador* jo, float x, float y, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner);
	~Granada();
	void pegar();
	void setVidas(int n);
	void setFase(Fase* f0) {f = f0;};
	void explodir();
	void move();
	void setAtiva(bool b) {ativa = b;};
};
//---------------------------------------------------------------------------
#endif
