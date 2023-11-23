#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Projetil.h"
#include "Menu.h"
#include <iostream>
#include <cmath>
#include <System.Ioutils.hpp>

using namespace Entidades;
using namespace Personagens;

Jogador::Jogador(Fmx::Types::TFmxObject* parent): Personagem(100, 101, 50, 50, parent) {
	//pMapa2 = NULL;
	Tdir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"J1Direita.png"));
	Tesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"J1Esquerda.png"));
	Adir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"J1AtaqueDireita.png"));
	Aesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"J1AtaqueEsquerda.png"));

	verifTempo = true;
	maxVidas = 100;
	pontos = 0;
    numVidas = 100;
	l_arma = new Lista<Arma>();
	itens = new Lista<string>();
	corpo->Width = 56;
	corpo->Height = 74;
	corpo->Bitmap->Assign(Tdir);
	//corpo->Scale->Point = (TPointF(0.2, 0.2));
	System::Classes::TComponent* owner = dynamic_cast <System::Classes::TComponent*> (corpo->Parent);
	//if (owner) ShowMessage("NOT NULL.");
	//else ShowMessage("NULL.");
	Arma* zero = new Arma("zero", owner);
	l_arma->incluirEl(zero);
	arma_sel = 1;
	Arma* Pistola = new Arma("pistola", owner);
	l_arma->incluirEl(Pistola);
	//Arma* Skorpion = new Arma("mp5");
	//l_arma->incluirEl(Skorpion); */
}

Jogador::~Jogador() {
	delete l_arma;
	delete itens;
}

void Jogador::move() 
{
	//atualizaPos();

	pos.X = pos.X + velx;
	pos.Y = pos.Y + vely;
	setPos(pos);

	verifImg();

	//if (atirando == 1) atirar();
}

void Jogador::setOwner(System::Classes::TComponent* owner) {
	Owner = owner;
	for (int i = 1; i <= l_arma->getTam(); i-=-1) {
        l_arma->getElX(i)->getInfo()->setOwner(Owner);
    }
}

void Jogador::parar() {
	velx = 0;
}

void Jogador::pular() { vely = -10; }


void Jogador::viradoDir()
{
	/*if (arma_sel == 1) {
		//corpo.setTextureRect(sf::IntRect(0, 0, 288, 370));
		setTextura(Tdir);
		corpo->Width = 56;
		corpo->Height = 74;
		//textura.loadFromFile("Midia/Imagens/J1Direita.png");
	} */
	//setTextura(Tdir);
	//corpo->Width = 56;
	//corpo->Height = 74;
	/*else {
		corpo.setTextureRect(sf::IntRect(0, 0, l_arma->getElX(arma_sel)->getInfo()->getTdir()->getSize().x, 370));
	}  */
	//this->setTextura(*((l_arma->getElX(arma_sel)->getInfo())->getTdir()));
	setTextura(l_arma->getElX(arma_sel)->getInfo()->getTdir());
	corpo->Width = l_arma->getElX(arma_sel)->getInfo()->getTdir()->Width * 0.2;
	corpo->Height = l_arma->getElX(arma_sel)->getInfo()->getTdir()->Height * 0.2;

}
void Jogador::viradoEsq()
{
	setTextura(l_arma->getElX(arma_sel)->getInfo()->getTesq());
	corpo->Width = l_arma->getElX(arma_sel)->getInfo()->getTesq()->Width * 0.2;
	corpo->Height = l_arma->getElX(arma_sel)->getInfo()->getTesq()->Height * 0.2;
	/*if (arma_sel == 1) {
		//corpo.setTextureRect(sf::IntRect(0, 0, 288, 370));
		setTextura(Tesq);
		corpo->Width = 56;
		corpo->Height = 74;
		//textura.loadFromFile("Midia/Imagens/J1Esquerda.png");
	}  */
	//setTextura(Tesq);
	//corpo->Width = 56;
	//corpo->Height = 74;
	/*else {
		corpo.setTextureRect(sf::IntRect(0, 0, l_arma->getElX(arma_sel)->getInfo()->getTesq()->getSize().x, 370));
	}
	this->setTextura(*((l_arma->getElX(arma_sel)->getInfo())->getTesq()));  */

}

void Jogador::ataqueDir()
{
	setTextura(l_arma->getElX(arma_sel)->getInfo()->getAdir());
	corpo->Width = l_arma->getElX(arma_sel)->getInfo()->getAdir()->Width * 0.2;
	corpo->Height = l_arma->getElX(arma_sel)->getInfo()->getAdir()->Height * 0.2;
	/*if (arma_sel == 1) {
		//corpo.setTextureRect(sf::IntRect(0, 0, 477, 363));
		setTextura(Adir);
		//textura.loadFromFile("Midia/Imagens/J1AtaqueDireita.png");
	} */
	//setTextura(Adir);
	//corpo->Width = 96;
	//corpo->Height = 74;
	/*else {
		corpo.setTextureRect(sf::IntRect(0, 0, l_arma->getElX(arma_sel)->getInfo()->getAdir()->getSize().x, 370));
	}
	this->setTextura(*((l_arma->getElX(arma_sel)->getInfo())->getAdir()));  */
}

void Jogador::ataqueEsq()
{
	setTextura(l_arma->getElX(arma_sel)->getInfo()->getAesq());
	corpo->Width = l_arma->getElX(arma_sel)->getInfo()->getAesq()->Width * 0.2;
	corpo->Height = l_arma->getElX(arma_sel)->getInfo()->getAesq()->Height * 0.2;
	/*if (arma_sel == 1) {
		//corpo.setTextureRect(sf::IntRect(0, 0, 477, 363));
		setTextura(Aesq);
		//textura.loadFromFile("Midia/Imagens/J1AtaqueEsquerda.png");
	} */
	//setTextura(Aesq);
	//corpo->Width = 96;
	//corpo->Height = 74;
	/*else {
		corpo.setTextureRect(sf::IntRect(0, 0, l_arma->getElX(arma_sel)->getInfo()->getAesq()->getSize().x, 370));
	}
	this->setTextura(*((l_arma->getElX(arma_sel)->getInfo())->getAesq())); */
}

void Jogador::colisaoInimigo(Entidade *i)
{

	if(verifTempo==true)
	{
		if(atacar==true)
		{
			i->setVidas(i->getVidas()-25);
			if (i->getVivo() == false) pontos += 100;
		}
		else if(i->getAtacar()==true)
		{
			if (i->getProjetil() == true) setVidas(numVidas - static_cast <Projetil*> (i)->getDano());
			else setVidas(numVidas - static_cast <Inimigo*> (i)->getDano());
		}
		verifTempo = false;
	}

	//float dt = tempoDano.getElapsedTime().asSeconds();
	if((clock() - tempoDano) / CLOCKS_PER_SEC >=3)
	{
		verifTempo = true;
		tempoDano = clock();
	}
}

int Jogador::colisaoMapaObs(Entidade *hbx)
{
	bool flag = 0;
	if (trunc(getPos().X + getTamX()) <= hbx->getPos().X + 16 && getPos().Y >= hbx->getPos().Y - getTamY() + 8) {
		setPos(TPointF(hbx->getPos().x - getTamX(), getPos().y));
		//pJogador->setVelY(-0.3f);
		//std::cout << "Colisao com a direita.\n";
		setVelY(getVelY() / 1.1f);
		flag = 1;
	}
	else if (getPos().X - 8 >= hbx->getPos().X + hbx->getTamX() - 16 && getPos().Y >= hbx->getPos().Y - getTamY() + 8) {
		setPos(TPointF(hbx->getPos().x + hbx->getTamX(), getPos().y));
		//std::cout << "Colisao com a esquerda.\n";
		//if (pJogador->getVel().y <= 0.6 && pJogador->getVel().y >= 0.2) pJogador->setVelY(-0.3f);
		//else pJogador->setVelY(pJogador->getVel().y / 2.0f);
		setVelY(getVelY() / 1.1f);
		flag = 1;
	}


	else if (trunc(getPos().Y + getTamY()) + 8 >= trunc(hbx->getPos().Y) && getVelY() >= 0 && getPos().y < hbx->getPos().y) {
		//std::cout << "Colisao abaixo.\n";
		//int py = pJogador->getPos().y / 32;
		//py = py * 32;
		if (getVelY() > 0) {
			setPos(TPointF(getPos().X, hbx->getPos().Y - 73));
		}
		setVelY(0.0f);
		//pJogador->setPos(sf::Vector2f(pJogador->getPos().x, trunc(hbx->getPos().y - pJogador->getTam().y)));
		flag = 1;
	}
	else if (getPos().Y >= hbx->getPos().Y + hbx->getTamY() - 16) {
		//std::cout << "Colisao acima.\n";
		setVelY(-getVelY());
		setPos(TPointF(getPos().X, hbx->getPos().Y + hbx->getTamY()));
	}
	
	if(verifTempo==true && hbx->getAtacar()==true)
	{
		//operator--();
		numVidas -= static_cast <Obstaculo*> (hbx)->getDano();
		verifTempo = false;
	}

	if((clock() - tempoDano) / CLOCKS_PER_SEC >=1.5)
	{
		verifTempo = true;
		tempoDano = clock();
	}
	setVidas(numVidas);
	return flag;
}

int Jogador::getPontos() { return pontos; }

void Jogador::setArmaSel(int x) { arma_sel = x; }

int Jogador::getArmaSel() { return arma_sel; }

Lista<Arma>* Jogador::getl_arma() { return l_arma; }

void Jogador::setl_ini(ListaEntes* i) { ini = i; }

Ente* Jogador::hitscan(Ente* e) {
	if (virado == 0) {
		if (((e->getPos().Y <= this->getPos().Y + 40 && e->getPos().Y + e->getTamY() >= this->getPos().Y + 40) || (e->getPos().Y <= this->getPos().Y + 60 && e->getPos().Y + e->getTamY() > this->getPos().Y + 60)) && (e->getPos().X + e->getTamX() > this->getPos().X + this->getTamX() - 10) && e->getPos().X < this->getPos().X + this->getTamX() + l_arma->getElX(arma_sel)->getInfo()->getAlc()) return e;
	}
	else if (virado == 1) {
		if (((e->getPos().Y <= this->getPos().Y + 40 && e->getPos().Y + e->getTamY() >= this->getPos().Y + 40) || (e->getPos().Y <= this->getPos().Y + 60 && e->getPos().Y + e->getTamY() > this->getPos().Y + 60)) && (e->getPos().X < this->getPos().X - 10) && e->getPos().X + e->getTamX() > this->getPos().X - l_arma->getElX(arma_sel)->getInfo()->getAlc()) return e;
	}
	return NULL;
}

void Jogador::atirar() {
	if (arma_sel == 1) return;

	clock_t t1 = clock();
	Arma* x = l_arma->getElX(arma_sel)->getInfo();
	if (t1 / (float)CLOCKS_PER_SEC - x->getTR() / (float)CLOCKS_PER_SEC > x->getRec() && x->getRecarregando() == 1) {
		x->setDry(0);
		if (x->getAmmo() > x->getMag()) x->setMagvar(x->getMag());
		else x->setMagvar(x->getAmmo());
		x->setRecarregando(0);
	}
	else if (x->getRecarregando() == 1) x->setDry(1);
	if (x->getDry() == 1 && x->getNome() != "granada") {
		x->getSomDry()->Play();
		return;
	}
	if (t1 / (float) CLOCKS_PER_SEC - x->getClock() / (float) CLOCKS_PER_SEC < 1.0 / x->getCad()) {
		if (virado == 0) {
			this->setTextura((x->getTdir()));
			corpo->Width = x->getTdir()->Width * 0.2;
			corpo->Height = x->getTdir()->Height * 0.2;
			//corpo.setTextureRect(sf::IntRect(0, 0, x->getTdir()->getSize().x, 370));
		}
		else {
			this->setTextura((x->getTesq()));
			corpo->Width = x->getTesq()->Width * 0.2;
			corpo->Height = x->getTesq()->Height * 0.2;
		}
		return;
	}
	//std::cout << t1 / (float) CLOCKS_PER_SEC << " - " << x->getClock() / (float) CLOCKS_PER_SEC << " = " << t1 / (float) CLOCKS_PER_SEC - x->getClock() / (float) CLOCKS_PER_SEC << "\n";
	if (x->getNome() != "granada") x->setClock(t1);
	if (x->getSom()->State == TMediaState::Playing) x->getSom()->CurrentTime = 0;
	x->getSom()->Play();
    if (x->getNome() == "granada") return;
	Ente* e = NULL, *e1 = NULL;
	int cont = 1, min=99999999999;
	while (ini->getLista()->getTam() >= cont) {
		e = hitscan(ini->getLista()->getElX(cont)->getInfo());
		if (e != NULL) if (static_cast <Entidade*> (e)->getVivo() == false) {
			e = NULL;
			cont++;
			continue;
		}
		if (e != NULL) if (fabs(e->getPos().x - this->getPos().x) < min) {
			min = fabs(e->getPos().x - this->getPos().x);
			e1 = e;
		}
		//std::cout << e->getPos().x << "\ne.y = " << e->getPos().y << "\nj.x = " << this->getPos().x << "\nj.y = " << this->getPos().y << "\n";
		//Sleep(1000);
		cont++;
	}
	e = e1;
	if (e == NULL) {
		std::cout << "e == NULL.\n" ;
	}
	else std::cout << "e != NULL.\n";
	//Sleep(1000);
	x->setMagvar(x->getMagvar() - 1);
	x->setAmmo(x->getAmmo() - 1);
	if (e == NULL) return;
	//std::cout << "ATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\n";

	static_cast <Entidade*> (e)->setVidas(static_cast <Entidade*> (e)->getVidas() - l_arma->getElX(arma_sel)->getInfo()->getDano());
	if (static_cast <Entidade*> (e)->getVivo() == false) {
		pontos += 50;
		//ShowMessage("Matou.");
	}
	//else std::cout << "Nao matou.\n";
}

bool Jogador::verifPular() {
	if (vely >= -0.3 && vely <= 0.3) return true;
	return false;
}

void Jogador::setVidas(int n) {
	if (numVidas > 0 && n <= 0 && vivo == true) {
		numVidas = n;
		vivo = false;
		corpo->Width = 0;
		corpo->Height = 0;
		ShowMessage("Morreu!");
		dynamic_cast <TForm*> (Owner->Owner)->Show();
		dynamic_cast <TForm1*> (Owner->Owner)->atualizaPontos();
		delete Owner;
    }
    numVidas = n;
}