#include "Mapa.h"
//#include "Windows.h"
#include <iostream>

Mapa::Mapa() : lista(), colidiveis()  {
	//inicializaAuto();
	//std::cout << "inicializaAuto executada.\n";
}

Mapa::~Mapa() {
	lista.~Lista();
	colidiveis->~Lista();
}

Mapa::Mapa(TPointF inicio, TPointF fim, TBitmap* img, Fmx::Types::TFmxObject* parent) : lista() {
	len = fim.x - inicio.x;
	this->ini = inicio.x;
	imagem = img;
	Parent = parent;
	inicializaAuto(inicio, fim);

}

void Mapa::inicializaAuto(TPointF ini, TPointF fim) {
	/*bool chk = 0;
	float len = fim.x - ini.x;
	for (float i = ini.x; i <= fim.x; i = i + 32) {
		chk = 0;
		for (float j = ini.y; j <= fim.y; j = j + 32) {
			Plataforma* p = new Plataforma(sf::Vector2f(i, j));
			if (p->getNula() == false) {
				chk = 1;
				cout << "Item adicionado a lista.\n";
				//p->setGerente(graf);
				lista.incluirEl(p);
				if (p->verifNula(sf::Vector2f(i + 32, j)) || p->verifNula(sf::Vector2f(i - 32, j)) ||
					p->verifNula(sf::Vector2f(i, j + 32)) || p->verifNula(sf::Vector2f(i, j - 32))) {
					if (i <= ini.x + len / 3) {
						c1.incluirEl(p);
						cout << "ADICAO A C1.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					}
					if (i > ini.x + len / 6 && i < ini.x + len / 2) c1b.incluirEl(p);
					if (i > ini.x + len / 3 && i < ini.x + 2 * len / 3) c2.incluirEl(p);
					if (i > ini.x + len / 2 && i < ini.x + 5 * len / 6) c2b.incluirEl(p);
					if (i > ini.x + 2 * len / 3 && i <= ini.x + len) c3.incluirEl(p);
				}
			}
			//else if (chk == 1) break;
		}
	}*/


	TPointF* pos = (TPointF*) malloc(sizeof(TPointF));
	pos->x = ini.x;
	pos->y = ini.y;
	clock_t contador = 0;

	float len = fim.x - ini.x;
	bool chk = 0;
	Plataforma* p = NULL;

	for (float i = ini.y; i < fim.y; i += 32) {
		pos->y = i;
		while (pos->x < fim.x) {
			//cout << pos->x << ", " << pos->y << "\n";
			//if (pos->y == 480) Sleep(500);
			clock_t a = clock();
			p = new Plataforma(pos, imagem, Parent);
			contador += (a - clock());
			if (p->getNula() == false) {
				chk = 1;
				//cout << "Item adicionado a lista.\n";
				lista.incluirEl(p);
				if (pos->x <= ini.x + len / 2.5 || pos->x - p->getTamX() <= ini.x + len / 2.5) {
					c1.incluirEl(p);
					//cout << "ADICAO A C1.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				}
				if ((pos->x > ini.x + len / 5 || pos->x - p->getTamX() > ini.x + len / 5)
					&& (pos->x < ini.x + len / 1.6666 || pos->x - p->getTamX() < ini.x + len / 1.6666)) c1b.incluirEl(p);
				if ((pos->x > ini.x + len / 2.5 || pos->x - p->getTamX() > ini.x + len / 2.5)
					&& (pos->x < ini.x + 2 * len / 2.5 || pos->x - p->getTamX() < ini.x + 2 * len / 2.5)) c2.incluirEl(p);
				if ((pos->x > ini.x + len / 1.6666 || pos->x - p->getTamX() > ini.x + len / 1.6666)
					&& (pos->x < ini.x + 5 * len / 5 || pos->x - p->getTamX() < ini.x + 5 * len / 5)) c2b.incluirEl(p);
				if ((pos->x > ini.x + 2 * len / 3 || pos->x - p->getTamX() > ini.x + 2 * len / 3)
					&& (pos->x < ini.x + len || pos->x - p->getTamX() < ini.x + len)) c3.incluirEl(p);
				//if (pos->x > ini.x + len / 3 && pos->x < ini.x + 2 * len / 3) c2.incluirEl(p);
				//if (pos->x > ini.x + len / 2 && pos->x < ini.x + 5 * len / 6) c2b.incluirEl(p);
				//if (pos->x > ini.x + 2 * len / 3 && pos->x <= ini.x + len) c3.incluirEl(p);

				/*c1.incluirEl(p);
				c1b.incluirEl(p);
				c2.incluirEl(p);
				c2b.incluirEl(p);
				c3.incluirEl(p);*/
				//colidiveis->incluirEl(p);
			}
			//else delete p;
		}
		pos->x = ini.x;
	}

	colidiveis = &c1;
    //ShowMessage((float) (contador / CLOCKS_PER_SEC));
}

Lista<Plataforma>* Mapa::getLista() { return &lista; }

void Mapa::imprimir() {
	Lista<Plataforma>::Elemento<Plataforma>* it = lista.getPrimeiro();
	while (it != NULL) {
		it->getInfo()->imprimir();
		it = it->getProximo();
	}
}

Lista<Plataforma>* Mapa::getColidiveis() { return colidiveis; }

Lista<Plataforma>* Mapa::getC1() { return &c1; }

Lista<Plataforma>* Mapa::getC1b() { return &c1b; }

Lista<Plataforma>* Mapa::getC2() { return &c2; }

Lista<Plataforma>* Mapa::getC2b() { return &c2b; }

Lista<Plataforma>* Mapa::getC3() { return &c3; }

/*Lista<Plataforma>* Mapa::getC1() { return colidiveis; }
Lista<Plataforma>* Mapa::getC1b() { return colidiveis; }
Lista<Plataforma>* Mapa::getC2() { return colidiveis; }
Lista<Plataforma>* Mapa::getC2b() { return colidiveis; }
Lista<Plataforma>* Mapa::getC3() { return colidiveis; }*/

float Mapa::getLen() { return len; }

void Mapa::setColidiveis(Lista<Plataforma>* l) { colidiveis = l; }

float Mapa::getIni() { return ini; }

void Mapa::reposMapa(float x, float y) {
	for (int i = 1; i <= lista.getTam(); i++){
        lista.getElX(i)->getInfo()->repos(x, y);
	}

}

int Mapa::getStart() {
	int i = 1;
	while (lista.getElX(i)->getInfo()->getPos().x != ini) i++;
	return i;

}