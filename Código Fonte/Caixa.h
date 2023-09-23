#pragma once
#include "Item.h"
#include "Skorpion.h"
#include "MP5.h"
#include "Pistola.h"
#include "MedPack.h"
#include "Fase.h"
#include <time.h>
#include <string>
using namespace Itens;
using namespace Fases;



class Caixa : public Item {
private:
	TMediaPlayer* som;
	//Item* i1, * i2;
	string i1, i2;
	Fase* f;

public:
	Caixa(Jogador* j, float sx, float sy, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner);
	~Caixa();
	void pegar();
	void findar();
	void setI1(string s);
	void setI2(string s);
	string getI1();
	string getI2();
	void setFase(Fase* k);
};
