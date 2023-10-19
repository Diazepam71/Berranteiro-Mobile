//---------------------------------------------------------------------------

#ifndef ExplosaoH
#define ExplosaoH
#include <Fmx.Media.hpp>
#include <System.Ioutils.hpp>
#include "Obstaculo.h"
#include "Fase.h"
using namespace Fases;
using namespace Entidades;

class Explosao : public Obstaculo {
private:
	float scale;
	TMediaPlayer* som;
    TBitmap* expl;
	int contaQuadros;
	Fase* f;

public:
	Explosao(float s, float x, float y, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner);
	~Explosao();
	void move();
    void setFase(Fase* f0) {f = f0;};
};
//---------------------------------------------------------------------------
#endif
