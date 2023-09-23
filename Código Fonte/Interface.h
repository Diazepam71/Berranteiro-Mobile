#pragma once
#include "Ente.h"
//#include "Textbox.h"
#include "Jogador.h"
using namespace Personagens;
#include <string>
//#include <SFML/Graphics.hpp>
//#define _CRT_SECURE_NO_WARNINGS

class Interface : public Ente {
private:
	//sf::Sprite rosto;
	//sf::Sprite cor, frame;
	Ente *rosto, *cor, *frame;
	TRectangle *HBar;
	//sf::Texture TRosto, CorCheio, TFrame;
	//Textbox *mag, *ammo, *instrucao;
	TLabel *mag, *ammo, *instrucao;
	//sf::Font* f;
	Jogador* j;
	clock_t relogio;
	float tref;

public:
	Interface(Fmx::Types::TFmxObject* parent);
	~Interface();
	void imprimir();
	void alteraMag(int x);
	void alteraAmmo(int x);
	void atualiza();
	void setJogador(Jogador* jo) { j = jo; }
	void teste();
	void setInstrucao(System::UnicodeString s);
    void emergencia(TStyledSettings socorro);
};
