//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif
#include "Interface.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Interface::Interface(Fmx::Types::TFmxObject* parent) : Ente(TPointF(0.0f, 0.0f), parent) {
	//sf::Vector2f pos = sf::Vector2f(gerente->getCoorView().x - gerente->getView()->getSize().x / 2, gerente->getCoorView().y - gerente->getView()->getSize().y / 2);

	//TRosto.loadFromFile("Midia/Imagens/Rosto.png");
	rosto = new Ente(TPointF(0,0), parent);
	rosto->getCorpo()->Width = 64;
	rosto->getCorpo()->Height = 64;
	rosto->getCorpo()->Bitmap->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Rosto.png"));
	rosto->setPos(TPointF(0,0));
	//rosto->getCorpo()->Scale->Point = TPointF(0.25, 0.25);

	cor = new Ente(TPointF(0, 68), parent);
	cor->getCorpo()->Width = 32;
	cor->getCorpo()->Height = 32;
	cor->getCorpo()->Bitmap->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"CorCheio.png"));
	cor->setPos(TPointF(0,68));
	//cor->getCorpo()->Scale->Point = TPointF(2, 2);

	frame = new Ente(TPointF(36, 68), parent);
	frame->getCorpo()->Bitmap->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"HealthFrame.png"));
	frame->getCorpo()->Width = 76;
	frame->getCorpo()->Height = 13;
	frame->setPos(TPointF(36, 68));

	HBar = new TRectangle(dynamic_cast <System::Classes::TComponent*> (parent));
	HBar->Parent = parent;
	HBar->Fill->Color = System::Uitypes::TAlphaColorRec::Green;
	HBar->Position->Point = TPointF(36, 84);
	HBar->Width = 100;
	HBar->Height = 12;

	mag = new TLabel(dynamic_cast <System::Classes::TComponent*> (parent));
	ammo = new TLabel(dynamic_cast <System::Classes::TComponent*> (parent));
	instrucao = new TLabel(dynamic_cast <System::Classes::TComponent*> (parent));
	mag->Parent = parent;
	ammo->Parent = parent;
	instrucao->Parent = parent;
	mag->StyledSettings.Clear();
	ammo->StyledSettings.Clear();
	instrucao->StyledSettings.Clear();
	System::Set<Fmx::Types::TStyledSetting, TStyledSetting::Family, TStyledSetting::Other> s0;
	mag->StyledSettings.operator-(s0);
	ammo->StyledSettings.operator-(s0);
	instrucao->StyledSettings.operator-(s0);
	mag->Font->Family = System::UnicodeString("Impact");
	ammo->Font->Family = System::UnicodeString("Impact");
	instrucao->Font->Family = System::UnicodeString("Impact");
	mag->TextSettings->FontColor = System::Uitypes::TAlphaColor(0xFFFFFFFF);
	ammo->TextSettings->FontColor = System::Uitypes::TAlphaColor(0xFFFFFFFF);
	instrucao->TextSettings->FontColor = System::Uitypes::TAlphaColor(0xFFFFFFFF);
	mag->FontColor = System::Uitypes::TAlphaColorRec::White;
	ammo->FontColor = System::Uitypes::TAlphaColorRec::White;
	instrucao->FontColor = System::Uitypes::TAlphaColorRec::White;
	mag->Position->Point = TPointF(68, 32);
	ammo->Position->Point = TPointF(68, 0);
	instrucao->Position->Point = TPointF(200, 0);
	mag->Width = 176;
	ammo->Width = 176;
	instrucao->Width = 600;

	mag->Text = System::UnicodeString("CAR.: 00");
	ammo->Text = System::UnicodeString("TOTAL: 00");
	instrucao->Text = System::UnicodeString("");
	tref = 0;

	//Arma* x = j->getl_arma()->getElX(j->getArmaSel())->getInfo();
	//mag->setText("CAR.: "+to_string(x->getMagvar()));
	//ammo->setText("TOTAL: "+to_string(x->getAmmo()));
}

Interface::~Interface() {
	delete rosto;
	delete cor;
	delete frame;
	delete HBar;
	delete ammo;
	delete mag;
	delete instrucao;
}

void Interface::alteraAmmo(int x) {
	//char buf[5];
	//itoa(x, buf, 10);
	//string s = to_string(x);
	ammo->Text = System::UnicodeString(x);
	ammo->TextSettings->FontColor = System::Uitypes::TAlphaColor(System::Uitypes::TAlphaColorRec::Red);
}

void Interface::alteraMag(int x) {
	//char buf[5];
	//_itoa(x, buf, 10);
	//string s = to_string(x);
	mag->Text = System::UnicodeString(x);
	mag->TextSettings->FontColor = System::Uitypes::TAlphaColor(System::Uitypes::TAlphaColorRec::Red);
}

void Interface::imprimir() {
	/*gerente->desenhaElemento(rosto);
	gerente->desenhaElemento(cor);
	ammo->draw(gerente->getWindow());
	mag->draw(gerente->getWindow());
	gerente->imprimeRet(HBar);
	gerente->desenhaElemento(frame);
	instrucao->draw(gerente->getWindow());*/
}

void Interface::setInstrucao(System::UnicodeString s) {
	instrucao->Text = System::UnicodeString("> " + s);
	tref = clock() / CLOCKS_PER_SEC;
}

void Interface::atualiza() {
	//I. Health Bar.

	/*for (int i = 1; i <= 5; i++) {
		if (i <= j->getVidas()) {
			if (i == 1) v1.setTexture(CorCheio);
			if (i == 2) v2.setTexture(CorCheio);
			if (i == 3) v3.setTexture(CorCheio);
			if (i == 4) v4.setTexture(CorCheio);
			if (i == 5) v5.setTexture(CorCheio);
		}
		else {
			if (i == 1) v1.setTexture(CorVazio);
			if (i == 2) v2.setTexture(CorVazio);
			if (i == 3) v3.setTexture(CorVazio);
			if (i == 4) v4.setTexture(CorVazio);
			if (i == 5) v5.setTexture(CorVazio);
		}
	}*/

	float f = (j->getVidas() / (float)j->getMaxVidas()) * 100;
	//HBar->Size = TPointF(f, 12);
	HBar->SetBounds(36, 84, f, 12);


	//II. Munições & Rosto.

	Arma* x = j->getl_arma()->getElX(j->getArmaSel())->getInfo();
	x->verifReload();
	System::UnicodeString s0 = System::UnicodeString((int) x->getMagvar());
	System::UnicodeString s1 = System::UnicodeString((int) x->getAmmo());
	mag->Text = System::UnicodeString ("CAR.: "+ s0);
	ammo->Text = System::UnicodeString("TOTAL: " + s1);
	//mag->FontColor = System::Uitypes::TAlphaColor(System::Uitypes::TAlphaColorRec::White);
	//ammo->FontColor = System::Uitypes::TAlphaColor(System::Uitypes::TAlphaColorRec::White);
	//instrucao->FontColor = System::Uitypes::TAlphaColor(System::Uitypes::TAlphaColorRec::White);
	mag->TextSettings->FontColor = System::Uitypes::TAlphaColor(0xFFFFFFFF);
	ammo->TextSettings->FontColor = System::Uitypes::TAlphaColor(0xFFFFFFFF);
	instrucao->TextSettings->FontColor = System::Uitypes::TAlphaColor(0xFFFFFFFF);

	//III. Posições

	/*sf::Vector2f pos = sf::Vector2f(gerente->getCoorView().x - gerente->getView()->getSize().x / 2, gerente->getCoorView().y - gerente->getView()->getSize().y / 2);
	rosto.setPosition(pos);
	cor.setPosition(sf::Vector2f(pos.x, pos.y + 68));
	ammo->setPosition(sf::Vector2f(pos.x + 68, pos.y));
	mag->setPosition(sf::Vector2f(pos.x + 68, pos.y + 32));
	HBar.setPosition(pos.x + 36, pos.y + 84);
	frame.setPosition(pos.x + 36, pos.y + 68);
	instrucao->setPosition(sf::Vector2f(pos.x + 250, pos.y));*/



	/*rosto->getCorpo()->Position->Point = TPointF(0,0);
	ammo->Position->Point = TPointF(68, 0);
	cor->getCorpo()->Position->Point = TPointF(0, 68);
	mag->Position->Point = TPointF(68, 32);
	HBar->Position->Point = TPointF(36, 84);
	frame->getCorpo()->Position->Point = TPointF(36, 68);
	instrucao->Position->Point = TPointF(250, 0); */


	//IV. Instrução
	if (clock() /CLOCKS_PER_SEC - tref > 3) instrucao->Text = System::UnicodeString("");
	//instrucao->FontColor = System::Uitypes::TAlphaColor(System::Uitypes::TAlphaColorRec::White);
	//instrucao->TextSettings->FontColor = System::Uitypes::TAlphaColor(System::Uitypes::TAlphaColorRec::Red);
}

void Interface::teste() {
	//cout << "Coord. do rosto:\nx = " << rosto.getPosition().x << "\n y = " << rosto.getPosition().y << "\n";
}

void Interface::emergencia(TStyledSettings socorro) {
	mag->StyledSettings = socorro;
	ammo->StyledSettings = socorro;
	instrucao->StyledSettings = socorro;
	mag->Font->Size = 24;
	ammo->Font->Size = 24;
	instrucao->Font->Size = 20;
	mag->Font->Family = System::UnicodeString("Unispace");
	ammo->Font->Family = System::UnicodeString("Unispace");
	instrucao->Font->Family = System::UnicodeString("Unispace");
}