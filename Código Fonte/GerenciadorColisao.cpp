#include "GerenciadorColisao.h"
#include "Item.h"
#include "Obstaculo.h"
#include <cmath>

using namespace Gerenciadores;

GerenciadorColisao::GerenciadorColisao(ListaEntes* ini, Jogador* p, Mapa* m) {
	inimigos = ini;
	map = m;
	jogador = p;
	plataforma_inicio = map->getStart();
}

GerenciadorColisao::GerenciadorColisao()
{
	inimigos = NULL;
	map = NULL;
}

GerenciadorColisao::~GerenciadorColisao(){}

const TPointF GerenciadorColisao::calculaColisaoIni(Ente* e1, Ente* e2) {
	TPointF pos1 = e1->getPos();
	TPointF pos2 = e2->getPos();
	TPointF tam1 = TPointF(e1->getTamX(), e1->getTamY());
	TPointF tam2 = TPointF(e2->getTamX(), e2->getTamY());
	TPointF distanciaEntreCentros{
		fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
		fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f))
	};
	TPointF somaMetadeRetangulo(tam1.x / 2.0f + tam2.x / 2.0f, tam1.y / 2.0f + tam2.y / 2.0f);
	return TPointF(distanciaEntreCentros.x - somaMetadeRetangulo.x, distanciaEntreCentros.y - somaMetadeRetangulo.y);
	//Por Giovane Limas Salvi
}

const TPointF GerenciadorColisao::calculaColisaoPlat(Ente* e, Plataforma* p) {
	TPointF pos1 = e->getPos();
	TPointF pos2 = p->getPos();
	TPointF tam1 = TPointF(e->getTamX(), e->getTamY());
	TPointF tam2 = TPointF(p->getTamX(), p->getTamY());
	TPointF distanciaEntreCentros{
		fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
		fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f))
	};
	TPointF somaMetadeRetangulo(tam1.x / 2.0f + tam2.x / 2.0f, tam1.y / 2.0f + tam2.y / 2.0f);
	return TPointF(distanciaEntreCentros.x - somaMetadeRetangulo.x, distanciaEntreCentros.y - somaMetadeRetangulo.y);
}

void GerenciadorColisao::executar() {
	Entidade* ent1;
	int i = 0;
	int j = 0;
	bool flag1 = false;
	bool flag2 = false;
	bool flag4 = false;
	bool flag3 = false;

	//for (int i = 0; i < inimigos->getLista()->getTam() - 1; i++)
		//Entidade* ent1 = inimigos->getLista()->getElX(i)->getInfo();
		for (j = 0; j <= inimigos->getLista()->getTam(); j++) {
			Entidade* ent2 = inimigos->getLista()->getElX(j)->getInfo();
			if(ent2->getVivo()==true)
			{
				if(jogador->getVivo()==false) continue;
				ent1 = static_cast<Entidade*>(jogador);

				TPointF ds = calculaColisaoIni(ent1, ent2);
				if (ds.x < 0.0f && ds.y < 0.0f) {
						//std::cout << "Ocorre uma colisao 1.\n";
						
					if (ent2->getObstaculo() == true)
					flag1 = jogador->colisaoMapaObs(ent2);



					else if (ent2->getIsItem() == true) static_cast <Item*> (ent2)->pegar();

					else
					{
						jogador->colisaoInimigo(ent2);
					}

					
				}
			}
		}


		//GerenciadorGrafico *graf = GerenciadorGrafico::getGerenciadorGrafico();

		if (-(map->getLista()->getElX(plataforma_inicio)->getInfo()->getPos().x) <  map->getLen() * 0.3)map->setColidiveis(map->getC1());
		else if (-map->getLista()->getElX(plataforma_inicio)->getInfo()->getPos().x >  map->getLen() * 0.3 && -map->getLista()->getElX(plataforma_inicio)->getInfo()->getPos().x < map->getLen() * 0.5) map->setColidiveis(map->getC1b());
		else if (-map->getLista()->getElX(plataforma_inicio)->getInfo()->getPos().x > map->getLen() * 0.5 && -map->getLista()->getElX(plataforma_inicio)->getInfo()->getPos().x < map->getLen() * 0.7) map->setColidiveis(map->getC2());
		else if (-map->getLista()->getElX(plataforma_inicio)->getInfo()->getPos().x >  map->getLen() * 0.7 && -map->getLista()->getElX(plataforma_inicio)->getInfo()->getPos().x <  map->getLen() * 0.9) map->setColidiveis(map->getC2b());
		else if (-map->getLista()->getElX(plataforma_inicio)->getInfo()->getPos().x >  map->getLen() * 0.9 && -map->getLista()->getElX(plataforma_inicio)->getInfo()->getPos().x < map->getLen()) map->setColidiveis(map->getC3());
		

		//map->setColidiveis(map->getC1());
		for (j = 0; j < map->getColidiveis()->getTam(); j++) {
			Plataforma* hbx = map->getColidiveis()->getElX(j)->getInfo();
			//if (hbx->getPos().x > graf->getCoorView().x + 320 || hbx->getPos().x < graf->getCoorView().x - 320 || hbx->getPos().y > graf->getCoorView().y + 240 || hbx->getPos().y < graf->getCoorView().y - 240) continue;

				if(jogador->getVivo()==false) continue;
				ent1 = static_cast<Entidade*>(jogador);

				TPointF ds = calculaColisaoPlat(ent1, hbx);
				if (ds.x < 0.0f && ds.y < 0.0f) {
					flag3 = jogador->colisaoMapaObs(static_cast<Entidade*>(hbx));

				}
			}
			//else pJogador->cair();

		if (flag1 == 0 && flag3 == 0) jogador->cair();
		//if (flag2 == 0 && flag4 == 0) jogadores[1]->cair();
		
		for (i = 0; i <= inimigos->getLista()->getTam(); i++) {
			flag2 = 0;
			ent1 = inimigos->getLista()->getElX(i)->getInfo();
			if (ent1->getVivo() == false) continue;
			if ((ent1->getPos().x > 800) || ent1->getPos().x < -100 || ent1->getPos().y > 500 || ent1->getPos().y < -100) continue;
			for (j = 0; j < map->getColidiveis()->getTam(); j++) {
				Plataforma* hbx = map->getColidiveis()->getElX(j)->getInfo();
				if ((hbx->getPos().x > 1000 && hbx->getPos().x + hbx->getTamX() > 1000)
					|| (hbx->getPos().x < -400 && hbx->getPos().x + hbx->getTamX() < -400)
					|| hbx->getPos().y > 800 || hbx->getPos().y < -100) continue;
				TPointF ds = calculaColisaoPlat(ent1, hbx);
				if (ds.x < 0.0f && ds.y < 0.0f) {
					//std::cout << "Ocorre uma colisao 2 - Inimigo.\n";
					if (ent1->getPos().y + ent1->getTamY() >= hbx->getPos().y) {
						ent1->setVelY(0.0f);
						flag2 = 1;
					}
					bool flag3 = 0;
					if (trunc(ent1->getPos().X + ent1->getTamX()) <= hbx->getPos().X + 16 && ent1->getPos().Y >= hbx->getPos().Y - ent1->getTamY() + 8) {
						ent1->setPos(TPointF(hbx->getPos().x - ent1->getTamX(), ent1->getPos().y));

						ent1->setVelY(ent1->getVelY() / 1.1f);
						flag3 = 1;
					}
					else if (ent1->getPos().X - 8 >= hbx->getPos().X + hbx->getTamX() - 16 && ent1->getPos().Y >= hbx->getPos().Y - ent1->getTamY() + 8) {
						ent1->setPos(TPointF(hbx->getPos().x + hbx->getTamX(), ent1->getPos().y));
						//std::cout << "Colisao com a esquerda.\n";
						//if (pJogador->getVel().y <= 0.6 && pJogador->getVel().y >= 0.2) pJogador->setVelY(-0.3f);
						//else pJogador->setVelY(pJogador->getVel().y / 2.0f);
						ent1->setVelY(ent1->getVelY() / 1.1f);
						flag3 = 1;
					}

						else if (trunc(ent1->getPos().Y + ent1->getTamY()) + 8 >= trunc(hbx->getPos().Y) && ent1->getVelY() >= 0 && ent1->getPos().y < hbx->getPos().y) {
							//std::cout << "Colisao abaixo.\n";
							//int py = pJogador->getPos().y / 32;
							//py = py * 32;
							if (ent1->getVelY() > 0) {
								ent1->setPos(TPointF(ent1->getPos().X, hbx->getPos().Y - 73));
							}
							ent1->setVelY(0.0f);
							//pJogador->setPos(sf::Vector2f(pJogador->getPos().x, trunc(hbx->getPos().y - pJogador->getTam().y)));
							flag3 = 1;
						}

					else if (ent1->getPos().Y >= hbx->getPos().Y + hbx->getTamY() - 16) {
						//std::cout << "Colisao acima.\n";
						ent1->setVelY(-(ent1->getVelY()));
						ent1->setPos(TPointF(ent1->getPos().X, hbx->getPos().Y + hbx->getTamY()));
					}

				}
				//else if (ent1->getPos().x + ent1->getTam().x >= hbx->getPos().x)
				//else pJogador->cair();
			}
			if (flag2 == 0) ent1->cair();
		}

		/*for (int j = 1; j <= inimigos->getLista()->getTam(); j++) {
			Entidade* e1 = inimigos->getLista()->getElX(j)->getInfo();
			for (int k = 1; k <= inimigos->getLista()->getTam(); k++) {
				Entidade* e2 = inimigos->getLista()->getElX(k)->getInfo();
				if (e2->getObstaculo() == false) continue;
				e1->setVidas(e1->getVidas() - static_cast <Obstaculo*> (e2)->getDano());
            }
        } */
	}


void GerenciadorColisao::setInimigos (ListaEntes *l)
{
	inimigos = l;
}
/*void GerenciadorColisao::setMapa (Mapa *m)
{
	map = m;
}

Ente* GerenciadorColisao::hitscan(Jogador* j, Ente* e) {
	if (!j->getVirado()) {
		if ((e->getPos().y >= j->getPos().y + 40 && e->getPos().y <= j->getPos().y + 60) && e->getPos().x + e->getTam().x > j->getPos().x + j->getTam().x - 10) return e;
	}
	else if (j->getVirado()) {
		if ((e->getPos().y >= j->getPos().y + 40 && e->getPos().y <= j->getPos().y + 60) && e->getPos().x < j->getPos().x - 10) return e;
	}
	return NULL;
} */

void GerenciadorColisao::trataExplosao(Entidade* expl) {
	for (int i = 1; i <= inimigos->getLista()->getTam(); i++) {
		Entidade* e1 = inimigos->getLista()->getElX(i)->getInfo();
        if (expl == e1) continue;
		TPointF ds = calculaColisaoIni(expl, e1);
		if (ds.x < 0.0f && ds.y < 0.0f) {
            e1->setVidas(e1->getVidas() - static_cast <Obstaculo*> (expl)->getDano());
        }
    }

}