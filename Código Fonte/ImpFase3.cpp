//---------------------------------------------------------------------------

#pragma hdrstop

#include "ImpFase3.h"
/*#include "Fase2.h"
#include "Pedra.h"
#include "Espinho.h" */
#include "Item.h"
#include "Caixa.h"
#include "Chave.h"
#include "Porta.h"
#include "Soldado.h"
#include <iostream>
#include <Fmx.Dialogs.hpp>

using namespace Fases;
//using namespace Itens;

ImpFase3::ImpFase3(GerenciadorColisao *c, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner):
Fase(parent, owner)
{

}

ImpFase3::ImpFase3(Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner): Fase(parent, owner) {
	clock_t timer = clock();
	lista = new ListaEntes();
    inimigos = new ListaEntes();
    //obs = new Lista<Obstaculo>;

	/*f1 = new sf::Music();
    f1->openFromFile("Midia/Musicas/S8M4.ogg");
    sf::Image i;
    i.loadFromFile("Midia/Imagens/Fase1.png");
	Plataforma::setImagem(i); */

	imagem = new TBitmap();
	imagem->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Fase3.png"));
	float f = (clock() - timer) / CLOCKS_PER_SEC;
	Mapa* mapa = new Mapa(TPointF(0, 0), TPointF(9600, 2048), imagem, parent);
	mapa2 = mapa;
	ShowMessage((float)(clock() - timer) / CLOCKS_PER_SEC);
	timer = clock();

	j1 = new Jogador(parent);
	j1->setMapa2(mapa2);
	j1->setPos(TPointF(100, 100));
	//interf->setJogador(j1);

	lista->add(static_cast<Entidade*>(j1));

	geraInimigos();
	geraObstaculos();
	geraItens();

	pColi = new GerenciadorColisao(inimigos, j1, mapa2);
	interf = new Interface(parent);

    ShowMessage((float) (clock() - timer + f) / CLOCKS_PER_SEC);
	//f1->play();
    inicio = clock();
}

ImpFase3::~ImpFase3(){
}

void ImpFase3::executar()
{
    moveLista();
}

void ImpFase3::geraInimigos()
{

	geraOnca(400, 100);
    geraSoldado(1152, 416, 1);
    //geraSoldado(1248, 416, 2);
    geraArara(928, 224);
    geraArara(65 * 32, 17 * 32);
    geraOnca(75 * 32, 18 * 32);
    geraSoldado(59 * 32, 10 * 32, 2);
    geraOnca(48 * 32, 27 * 32);
    geraArara(61 * 32, 31 * 32);
    geraArara(21 * 32, 34 * 32);
    geraArara(29 * 32, 36 * 32);
    geraSoldado(30 * 32, 18 * 32, 2);
    geraSoldado(3 * 32, 29 * 32, 1);
    geraOnca(22 * 32, 46 * 32);
    geraOnca(28 * 32, 46 * 32);
    geraSoldado(7 * 32, 49 * 32, 2);
    geraOnca(43 * 32, 0);
    geraOnca(47 * 32, 0);
    geraSoldado(107 * 32, 49 * 32, 2);
    geraOnca(102 * 32, 55 * 32);
    geraOnca(107 * 32, 55 * 32);
    geraArara(87 * 32, 50 * 32);
    geraSoldado(70 * 32, 55 * 32, 1);
    geraOnca(78 * 32, 51 * 32);
    geraArara(44 * 32, 54 * 32);
    geraArara(54 * 32, 54 * 32);
	geraOnca(33 * 32, 56 * 32);
	geraSoldado(131 * 32, 54 * 32, 1);
	geraOnca(91 * 32, 39 * 32);
    geraArara(99 * 32, 14 * 32);
    geraArara(98 * 32, 25 * 32);
    geraArara(96 * 32, 35 * 32);
    geraSoldado(125 * 32, 8 * 32, 2);
	geraOnca(113 * 32, 22 * 32);
	geraSoldado(163 * 32, 42 * 32, 1);
	geraSoldado(165 * 32, 42 * 32, 2);
	geraSoldado(168 * 32, 42 * 32, 1);
	geraSoldado(205 * 32, 34 * 32, 1);
	geraSoldado(183 * 32, 31 * 32, 2);
	geraSoldado(172 * 32, 30 * 32, 2);
	geraSoldado(206 * 32, 28 * 32, 1);
	Inimigo* x = geraSoldado(208 * 32, 40 * 32, 2);
	static_cast <Soldado*> (x)->setItem("chave-A5");
	geraOnca(180 * 32, 25 * 32);
	geraOnca(186 * 32, 25 * 32);
	geraOnca(192 * 32, 25 * 32);
	geraOnca(195 * 32, 25 * 32);
	geraArara(181 * 32, 24 * 32);
	geraArara(185 * 32, 24 * 32);
    geraArara(187 * 32, 24 * 32);



	Curupira* c = geraCurupira(215 * 32, 11 * 32);
	c->setItem("chave-A4");
	inimigos->add(static_cast<Entidade*>(c->getFogo()));
	lista->add(static_cast<Entidade*>(c->getFogo()));

	c->setLista(inimigos);

	j1->setl_ini(inimigos);
}

Curupira* ImpFase3::geraCurupira(float x, float y) {
	Curupira* c = new Curupira(j1, x, y, Parent);
	c->setFase(this);
	inimigos->add(c);
	lista->add(c);
	return c;
}


void ImpFase3::geraObstaculos() {
	geraEspinho(10 * 32, 13 * 32, 4);
	geraEspinho(14 * 32, 50 * 32, 6);
	geraEspinho(31 * 32, 50 * 32, 9);
	geraEspinho(95 * 32, 43 * 32, 10);
	geraEspinho(42 * 32, 60 * 32, 6);
	geraEspinho(55 * 32, 60 * 32, 6);
	geraEspinho(111 * 32, 50 * 32, 2);
}

void ImpFase3::geraItens() {
	Item* i = NULL;
    /*geraItem(2368, 300, "skorpion");
    i = geraItem(2300, 300, "caixa");
    static_cast <Caixa*> (i)->setI1("skorpion");
    static_cast <Caixa*> (i)->setI2("skorpion");
    geraItem(1000, 200, "med");
    geraItem(920, 180, "caixa");
    i = geraItem(900, 150, "chave");
    static_cast <Chave*> (i)->setString("3A1");
    geraItem(1100, 200, "med");
    geraItem(3300, 300, "med");
    geraItem(4330, 820, "med");
    i = geraItem(300, 100, "porta");
    static_cast <Porta*> (i)->setString("3A1");*/

    i = geraItem(2 * 32, 17 * 32, "caixa");
    static_cast <Caixa*> (i)->setI1("chave-A1");
    static_cast <Caixa*> (i)->setI2("mp5");
    geraItem(59 * 32, 11 * 32, "medpack");
    geraItem(61 * 32, 11 * 32, "medpack");
    geraItem(23 * 32, 41 * 32, "medpack");
    geraItem(27 * 32, 41 * 32, "medpack");
    geraItem(74 * 32, 36 * 32, "medpack");
    geraItem(81 * 32, 36 * 32, "medpack");
    i = geraItem(33 * 32, 18 * 32, "caixa");
    //static_cast <Caixa*> (i)->setI1("pistola");
    static_cast <Caixa*> (i)->setI2("medpack");
    i = geraItem(101 * 32, 5 * 32, "porta");
    static_cast <Porta*> (i)->setString("A1");
    //i = geraItem(85 * 32, 9 * 32, "caixa");
    //static_cast <Caixa*> (i)->setI1("medpack");
    //static_cast <Caixa*> (i)->setI2("skorpion");
    geraItem(84 * 32, 9 * 32, "medpack");
    geraItem(86 * 32, 9 * 32, "pistola");
    i = geraItem(124 * 32 - 80, 37 * 32, "porta");
    static_cast <Porta*> (i)->setString("A2");
    i = geraItem(118 * 32, 38 * 32, "chave");
    static_cast <Chave*> (i)->setString("A2");
    i = geraItem(108 * 32, 38 * 32, "caixa");
    static_cast <Caixa*> (i)->setI1("chave-B2");
    static_cast <Caixa*> (i)->setI2("medpack");
    geraItem(119 * 32, 24 * 32, "mp5");
    geraItem(69 * 32, 46 * 32, "pistola");
    geraItem(49 * 32, 59 * 32, "medpack");
    geraItem(51 * 32, 59 * 32, "medpack");
    geraItem(53 * 32, 59 * 32, "medpack");
    i = geraItem(15 * 32, 53 * 32, "porta");
    static_cast <Porta*> (i)->setString("A3");
    i = geraItem(85 * 32, 5 * 32, "caixa");
    static_cast <Caixa*> (i)->setI1("chave-A3");
    i = geraItem(275 * 32, 5 * 32, "porta");
    static_cast <Porta*> (i)->setString("A4");
    geraItem(282 * 32, 5 * 32, "skorpion");
    geraItem(285 * 32, 5 * 32, "municaoskorpion");
    geraItem(286 * 32, 5 * 32, "municaoskorpion");
    i = geraItem(279 * 32, 5 * 32, "medpack");
    static_cast <Medpack*> (i)->setValor(30);
    i = geraItem(280 * 32, 5 * 32, "medpack");
    static_cast <Medpack*> (i)->setValor(20);
    geraItem(288 * 32, 5 * 32, "chave-B4");
    geraItem(74 * 32, 2 * 32, "chave-B1");

    i = geraItem(135 * 32, 54 * 32, "porta");
    static_cast <Porta*> (i)->setString("B1");
    i = geraItem(139 * 32, 48 * 32, "porta");
    static_cast <Porta*> (i)->setString("B2");
    i = geraItem(147 * 32, 48 * 32, "porta");
    static_cast <Porta*> (i)->setString("B3");
    i = geraItem(155 * 32, 48 * 32, "porta");
    static_cast <Porta*> (i)->setString("B4");

    i = geraItem(138 * 32, 56 * 32, "caixa");
    static_cast <Caixa*> (i)->setI1("medpack");
    static_cast <Caixa*> (i)->setI2("skorpion");
    i = geraItem(141 * 32, 58 * 32, "medpack");
	static_cast <Medpack*> (i)->setValor(47);
	//geraItem(5000, 1500, "trigger_fase0");
	geraItem(300, 150, "granada");
	geraItem(48 * 32, 6 * 32, "granada");
	geraItem(70 * 32, 46 * 32, "granada");
	geraItem(146 * 32, 56 * 32, "granada");
	geraItem(148 * 32, 56 * 32, "granada");
	geraItem(162 * 32, 25 * 32, "granada");
	geraItem(164 * 32, 25 * 32, "granada");
	geraItem(172 * 32, 25 * 32, "mp5");
	i = geraItem(199 * 32, 24 * 32, "porta");
	static_cast <Porta*> (i)->setString("A5");
	geraItem(173 * 32, 56 * 32, "trigger_fase0");
	geraItem(178 * 32, 25 * 32, "chave-B3");
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
