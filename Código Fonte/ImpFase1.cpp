#include "ImpFase1.h"
/*#include "Fase2.h"
#include "Pedra.h"
#include "Espinho.h" */
#include "Item.h"
#include "Caixa.h"
#include "Chave.h"
#include "Porta.h"
#include <iostream>
#include <Fmx.Dialogs.hpp>

using namespace Fases;
//using namespace Itens;

ImpFase1::ImpFase1(GerenciadorColisao *c, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner):
Fase(parent, owner)
{

}

ImpFase1::ImpFase1(Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner): Fase(parent, owner) {
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
	imagem->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Fase1.png"));
	float f = (clock() - timer) / CLOCKS_PER_SEC;
	Mapa* mapa = new Mapa(TPointF(0, 160), TPointF(4992, 2240), imagem, parent);
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
}

ImpFase1::~ImpFase1(){
}

void ImpFase1::executar()
{
    moveLista();
}

void ImpFase1::geraInimigos()
{

    srand(time(NULL));
    int verif;
    int lim = 0;
    int contador = 0;
    float x = 300;
    float y = 100;
	geraOnca(660, 376);
	geraSoldado(19 * 32, 48, 2);
    geraOnca(500, 100);
	geraOnca(3224, 1462);

	geraArara(2384, 250);
	geraArara(1312, 150);
	geraArara(2936, 568);
	geraSoldado(3456, 662, 1);


    verif = rand() % 4;
    if (verif == 1) geraOnca(1072, 248);
    verif = rand() % 4;
	if (verif == 1) geraArara(352, 50);
    verif = rand() % 4;
	if (verif == 1) geraArara(1080, 96);
	verif = rand() % 4;
    if (verif == 1) geraOnca(2304, 374);
    verif = rand() % 4;
	if (verif == 1) geraSoldado(3456, 662, 2);
	verif = rand() % 4;
    if (verif == 1) geraOnca(3014, 1335);
    verif = rand() % 4;
    if (verif == 1) geraSoldado(4334, 823, 2);
    verif = rand() % 4;
    if (verif == 1) geraOnca(3110, 1848);

    j1->setl_ini(inimigos);
}


void ImpFase1::geraObstaculos() {
    srand(time(NULL));
    
    int verif;
    verif = rand() % 4;
	if (verif == 1) {
        geraPedra(1736, 280);
    }
    verif = rand() % 4;
    if (verif == 2) {
        geraPedra(2368, 200);
    }
    verif = rand() % 4;
    if (verif == 3) {
        geraPedra(3302, 300);
    }
    geraTrepadeira(1072, 100);
    geraPedra(2056, 300);
	geraPedra(2632, 300);
    geraEspinho(3424, 1856, 8);
    geraEspinho(2752, 1952, 3);
    geraEspinho(3424, 2144, 3);
    geraEspinho(3616, 2144, 3);

    verif = rand() % 4;
    if (verif == 1) {
        geraEspinho(3168, 1472, 3);
    }
    verif = rand() % 4;
    if (verif == 2) {
        geraEspinho(3136, 736, 4);
    }
    verif = rand() % 4;
    if (verif == 3) {
        geraEspinho(2592, 544, 4);
    }
    verif = rand() % 4;
    if (verif == 1) {
        geraEspinho(576, 160, 3);
    }
}

void ImpFase1::geraTrepadeira(float x, float y)
{
    Trepadeira* p1 = new Trepadeira(x, y, Parent);
    lista->add(p1);
    inimigos->add(p1);
}

void ImpFase1::geraItens() {
    Item* i = NULL;
	i = geraItem(2368, 300, "skorpion");
	i = geraItem(2300, 300, "caixa");
    static_cast <Caixa*> (i)->setI1("skorpion");
    static_cast <Caixa*> (i)->setI2("skorpion");
    geraItem(1000, 200, "med");
    i = geraItem(920, 180, "caixa");
	//i = geraItem(900, 150, "chave");
	//static_cast <Chave*> (i)->setString("3A1");
    static_cast <Caixa*> (i)->setI1("chave-A1");
    static_cast <Caixa*> (i)->setI2("pistola");
    geraItem(1100, 200, "med");
    geraItem(3300, 300, "med");
    geraItem(4330, 820, "med");
    i = geraItem(300, 100, "porta");
	static_cast <Porta*> (i)->setString("A1");
}
