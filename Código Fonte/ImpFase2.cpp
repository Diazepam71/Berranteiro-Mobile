#include "ImpFase2.h"
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

ImpFase2::ImpFase2(GerenciadorColisao *c, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner):
Fase(parent, owner)
{

}

ImpFase2::ImpFase2(Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner): Fase(parent, owner) {
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
	imagem->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Fase2.png"));
	float f = (clock() - timer) / CLOCKS_PER_SEC;
	Mapa* mapa = new Mapa(TPointF(4192, 32), TPointF(12768, 1792), imagem, parent);
	mapa2 = mapa;
	//ShowMessage((float)(clock() - timer) / CLOCKS_PER_SEC);
	timer = clock();

	j1 = new Jogador(parent);
	j1->setMapa2(mapa2);
	j1->setPos(TPointF(4320, 800));
	//interf->setJogador(j1);

	lista->add(static_cast<Entidade*>(j1));

    geraInimigos();
	geraObstaculos();
	geraItens();

	pColi = new GerenciadorColisao(inimigos, j1, mapa2);
	interf = new Interface(parent);

    //ShowMessage((float) (clock() - timer + f) / CLOCKS_PER_SEC);
	//f1->play();
    inicio = clock();
}

ImpFase2::~ImpFase2(){
}

void ImpFase2::executar()
{
    moveLista();
}

void ImpFase2::geraInimigos()
{

	srand(time(NULL));
    int verif;
    int lim = 0;
    int contador = 0;
    float x = 300;
    float y = 100;
    Curupira* c;
    geraSoldado(4830, 888, 2);
    geraOnca(7912, 472);
    geraOnca(9110, 855);
    geraOnca(9286, 855);
    geraOnca(9526, 728);
    geraOnca(12142, 823);
    geraOnca(12342, 823);
    geraArara(5344, 544);
    geraSoldado(6592, 544, 1);
    geraArara(8320, 192);
    geraArara(9184, 768);
    geraArara(9536, 576);
	geraArara(12384, 640);
    verif = rand() % 4;
    if (verif == 1) geraOnca(5382, 950);
    verif = rand() % 4;
    if (verif == 1) geraOnca(5816, 792);
    verif = rand() % 4;
    if (verif == 1) geraOnca(6382, 500);
    verif = rand() % 4;
    if (verif == 1) geraOnca(6630, 300);
    verif = rand() % 4;
    if (verif == 1) geraOnca(6912, 438);
    verif = rand() % 4;
    if (verif == 1) geraOnca(8110, 920);
    verif = rand() % 4;
    if (verif == 1) geraSoldado(9406, 1496, 1);
    verif = rand() % 4;
    if (verif == 1) geraOnca(10126, 728);
    verif = rand() % 3;
    if (verif == 1) geraArara(8640, 224);
    verif = rand() % 3;
    if (verif == 1) geraArara(10144, 288);
    verif = rand() % 3;
	if (verif == 1) geraArara(12192, 640);
    c = geraCurupira(12598, 800);

    inimigos->add(static_cast<Entidade*>(c->getFogo()));
    lista->add(static_cast<Entidade*>(c->getFogo()));

	c->setLista(inimigos);
    c->setItem("trigger_fase3");

    j1->setl_ini(inimigos);
}

Curupira* ImpFase2::geraCurupira(float x, float y) {
	Curupira* c = new Curupira(j1, x, y, Parent);
	c->setFase(this);
	inimigos->add(c);
	lista->add(c);
	return c;
}


void ImpFase2::geraObstaculos() {
	 srand(time(NULL));

    geraEspinho(6976, 768, 4);
    geraEspinho(7296, 768, 4);
    geraEspinho(7424, 832, 12);
    geraEspinho(8256, 1024, 8);
    geraEspinho(8448, 704, 2);
    geraEspinho(9152, 1600, 4);
    geraEspinho(9536, 1600, 4);
    geraEspinho(9792, 1728, 8);
    geraEspinho(10304, 1024, 15);
    geraPedra(5440, 544);
    geraPedra(6400, 480);
    geraPedra(9856, 256);

    int verif;
    verif = rand() % 3;
    if (verif == 1) {
        geraPedra(11040, 448);
    }
    verif = rand() % 3;
    if (verif == 1) {
        geraPedra(12320, 608);
    }
    verif = rand() % 3;
    if (verif == 1) {
        geraPedra(11840, 608);
    }
    verif = rand() % 3;
    if (verif == 1) {
        geraEspinho(5670, 960, 5);
    }
    verif = rand() % 3;
    if (verif == 1) {
        geraEspinho(7808, 512, 4);
	}
}

void ImpFase2::geraItens() {
	Item* i = NULL;
	//geraItem(4900, 900, "pistola");
	i = geraItem(5500, 1000, "caixa");
	static_cast <Caixa*> (i)->setI1("pistola");
	static_cast <Caixa*> (i)->setI2("medpack");
	geraItem(8076, 512, "caixa");
	geraItem(8160, 940, "medpack");
	geraItem(8220, 940, "medpack");
	geraItem(9200, 768, "skorpion");
	geraItem(9200, 900, "medpack");
	geraItem(9280, 900, "medpack");
	geraItem(10200, 380, "municaomp5");
	geraItem(4770 * 2, 700, "municaoskorpion");
	i = geraItem(5680 * 2, 560, "caixa");
	static_cast <Caixa*> (i)->setI1("pistola");
	static_cast <Caixa*> (i)->setI2("medpack");
	i = geraItem(5720 * 2, 780, "caixa");
	static_cast <Caixa*> (i)->setI1("municaomp5");
	static_cast <Caixa*> (i)->setI2("medpack");
	geraItem(4690 * 2, 1500, "mp5");
}
