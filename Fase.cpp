#include "Fase.h"
#include "Skorpion.h"
#include "Pistola.h"
#include "MP5.h"
#include "MedPack.h"
#include "Caixa.h"
#include "Soldado.h"
#include "Chave.h"
#include "Porta.h"
#include "MunicaoMP5.h"
#include "MunicaoSkorpion.h"
#include "TriggerFase.h"
#include "Explosao.h"
#include "Granada.h"
using namespace Itens;

using namespace Fases;


Fase::Fase() {
	pColi = NULL;
	lista = NULL;
	j1 = NULL;
	mapa2 = NULL;
	relogio = clock();
	dropclock = clock();
	imagem = NULL;
	Parent = NULL;
	interf = NULL;
	Owner = NULL;
	//interf = new Interface(Parent);
    //obs = NULL;
}

Fase::Fase(Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner)
{
	pColi = NULL;
	lista = NULL;
	j1 = NULL;
	mapa2 = NULL;
    relogio = clock();
	dropclock = clock();
	imagem = NULL;
	Parent = parent;
	interf = NULL;
	Owner = owner;
	//interf = new Interface(Parent);
    //obs = NULL;
}

Fase::~Fase()
{
    mapa2->~Mapa();
    delete pColi;
    delete lista;
    delete j1;
	delete inimigos;
	delete interf;
}

void Fase::setJogador1(Jogador *j)
{
    j1 = j;
	interf->setJogador(j);
}

void Fase::setEntes(ListaEntes *l)
{
    lista = l;
}

void Fase::setInimigos(ListaEntes *i)
{
    inimigos =i;
}

void Fase::setMapa2(Mapa* m) { mapa2 = m; }

Mapa* Fase::getMapa2() { return mapa2; }

void Fase::setColi(GerenciadorColisao* c) { pColi = c; }

ListaEntes* Fase::getLista() { return lista; }

ListaEntes* Fase::getInimigos() { return inimigos; }

Jogador* Fase::getJogador() { return j1; }

void Fase::geraOnca(float x, float y)
{

    Onca* inimigo;
	inimigo = new Onca(j1, x, y, Parent);
    inimigos->add(static_cast<Entidade*>(inimigo));
    lista->add(static_cast<Entidade*>(inimigo));

}

void Fase::geraArara(float x, float y)
{

    Arara *inimigo;
	inimigo = new Arara(j1, x, y, Parent);
    inimigos->add(static_cast<Entidade*>(inimigo));
    lista->add(static_cast<Entidade*>(inimigo));

}

Inimigo* Fase::geraSoldado(float x, float y, int s)
{
    Soldado *ini; 
    ini = new Soldado(j1, x, y, s, Parent, Owner);
    inimigos->add(static_cast<Entidade*>(ini));
    lista->add(static_cast<Entidade*>(ini));
	ini->setFase(this);
    return ini;
}

void Fase::geraPedra(float x, float y)
{
    Pedra* p2 = new Pedra(x, y, Parent);
    lista->add(static_cast<Entidade*>(p2));
    inimigos->add(static_cast<Entidade*>(p2));
}
void Fase::geraEspinho(float x, float y, int tam)
{
	Espinho* e1 = new Espinho(x, y, tam, Parent);
	lista->add(static_cast<Entidade*>(e1));
    inimigos->add(static_cast<Entidade*>(e1));
}

Item* Fase::geraItem(float x, float y, string nome) {
    Item* i=NULL;
    if (nome == "skorpion") {
		i = new Skorpion(j1, x, y, Parent, Owner);
        static_cast <Skorpion*> (i)->setFase(this);
    }
	else if (nome == "pistola") {
		i = new Pistola(j1, x, y, Parent, Owner);
        static_cast <Pistola*> (i)->setFase(this);
    }
    else if (nome == "mp5") {
		i = new MP5(j1, x, y, Parent, Owner);
        static_cast <MP5*> (i)->setFase(this);
    }
    else if (nome == "medpack") {
		i = new Medpack(j1, x, y, Parent, Owner);
        static_cast <Medpack*> (i)->setFase(this);
    }
    else if (nome == "caixa") {
		i = new Caixa(j1, x, y, Parent, Owner);
        static_cast <Caixa*> (i)->setFase(this);
    }
    else if (nome == "chave") {
		i = new Chave(j1, x, y, Parent, Owner);
        static_cast <Chave*> (i)->setFase(this);
        
    }
    else if (nome[0] == 'c' && nome[1] == 'h') {
		i = new Chave(j1, x, y, Parent, Owner);
        string aux2;
        aux2.push_back(nome[6]);
        aux2.push_back(nome[7]);
        static_cast <Chave*> (i)->setString(aux2);
        static_cast <Chave*> (i)->setFase(this);
    }
    else if (nome == "porta") {
		i = new Porta(j1, x, y, Parent, Owner);
        static_cast <Porta*> (i)->setFase(this);
    }
    else if (nome == "municaomp5") {
		i = new MunicaoMP5(j1, x, y, Parent, Owner);
        static_cast <MunicaoMP5*> (i)->setFase(this);
    }
	else if (nome == "municaoskorpion") {
		i = new MunicaoSkorpion(j1, x, y, Parent, Owner);
        static_cast <MunicaoSkorpion*> (i)->setFase(this);
	}
	else if (nome == "trigger_fase1") {
		i = new TriggerFase(1, j1, x, y, Parent, Owner);
		static_cast <TriggerFase*> (i)->setFAtual(this);
	}
	else if (nome == "trigger_fase2") {
		i = new TriggerFase(2, j1, x, y, Parent, Owner);
		static_cast <TriggerFase*> (i)->setFAtual(this);
	}
	else if (nome == "trigger_fase3") {
		i = new TriggerFase(3, j1, x, y, Parent, Owner);
		static_cast <TriggerFase*> (i)->setFAtual(this);
	}
	else if (nome == "trigger_fase0") {
		i = new TriggerFase(0, j1, x, y, Parent, Owner);
		static_cast <TriggerFase*> (i)->setFAtual(this);
	}
	else if (nome == "granada") {
		i = new Granada(j1, x, y, Parent, Owner);
        static_cast <Granada*> (i)->setFase(this);
    }
    if (i != NULL) {
        lista->add(static_cast <Entidade*> (i));
        inimigos->add(static_cast <Entidade*> (i));
    }
    return i;
}

void Fase::moveLista()
{
    int contador;

	pColi->executar();
	//if (pEvent->getDrop() == 1) jogador_soltarArma();

	interf->atualiza();
    //interface->imprimir();

    for(contador=1; contador<lista->getLista()->getTam() + 1; contador++)
	{
        if (lista->getLista()->getElX(contador)->getInfo()->getVivo() == false) continue;
		lista->getLista()->getElX(contador)->getInfo()->move();//movimento do jogador eh atualizado na na funcao move(), que chama a funcao atualizaPos()
	}
}

Interface* Fase::getInterface() { return interf; }

/*void Fase::jogador_soltarArma() {
	if ((clock() - dropclock) / CLOCKS_PER_SEC < 2) return;
    Arma* x = j1->getl_arma()->getElX(j1->getArmaSel())->getInfo();
    if (x->getNome() == "zero") return;
    if (x->getNome() == "pistola_d") {
        Arma* y = new Arma("pistola");
        j1->getl_arma()->incluirEl(y);
        j1->getl_arma()->removeElX(j1->getArmaSel());
        j1->setArmaSel(j1->getl_arma()->getTam());
        Item* i = geraItem(j1->getPos().x + 100 - j1->getVirado() * 200, j1->getPos().y + 30, "pistola");
        static_cast <Pistola*> (i)->setammo(x->getAmmo() / 2);
        static_cast <Pistola*> (i)->setmagvar(x->getMagvar() / 2);
    }
    else {
        string s = x->getNome();
        j1->getl_arma()->removeElX(j1->getArmaSel());
        Item* i = geraItem(j1->getPos().x + 100 - j1->getVirado() * 200, j1->getPos().y + 30, s);
        j1->setArmaSel(j1->getArmaSel() - 1);
        if (s == "skorpion") {
            static_cast <Skorpion*> (i)->setammo(x->getAmmo());
            static_cast <Skorpion*> (i)->setmagvar(x->getMagvar());
        }
        else if (s == "mp5") {
            static_cast <MP5*> (i)->setammo(x->getAmmo());
            static_cast <MP5*> (i)->setmagvar(x->getMagvar());
        }
        else if (s == "pistola") {
            static_cast <Pistola*> (i)->setammo(x->getAmmo());
            static_cast <Pistola*> (i)->setmagvar(x->getMagvar());
        }
    }
	dropclock = clock();
}            */

void Fase::setParent(Fmx::Types::TFmxObject* parent) {Parent = parent;}

void Fase::geraExplosao(float x, float y, float s) {
	Explosao* e = new Explosao(s, x, y, Parent, Owner);
    e->setFase(this);
	lista->add(e);
	inimigos->add(e);

}