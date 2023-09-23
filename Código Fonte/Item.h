#pragma once
#include "Entidade.h"
using namespace Entidades;
#include "Jogador.h"
using namespace Personagens;
#include <string>
using namespace std;

class Item : public Entidade {
protected:
	Jogador* j;
	string nome;
	//TMediaPlayer* som;

public:
	Item(Jogador* jo, float x, float y, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner);
	~Item();
	virtual void pegar();
	void move();
	string getNome() { return nome; }
	void setVidas(int n);
	void setSound(System::UnicodeString s);
	virtual void findar();
};
