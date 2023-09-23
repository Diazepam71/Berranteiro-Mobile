#include "Inimigo.h"
#include <iostream>

using namespace Entidades;
using namespace Personagens;

Inimigo::Inimigo(Jogador *j1, float x, float y, Fmx::Types::TFmxObject* parent) :
Personagem(20, 103, x, y, parent)
{
	jogador1 = j1;
	movAl = rand()%2;
	horaAtaque = true;
	inicio = clock();
}

Inimigo::~Inimigo()
{
	jogador1 = NULL;
}

void Inimigo::move()
{
	//GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	if (pos.x > 1500 || pos.X < -300 || pos.y < -300 || pos.y > 1000) {
        congela();
    }
    else {
		TPointF posiJogador;

            if(voa==true)
                setVelY(0);

			posiJogador = jogador1->getPos();

            
            if (abs(posiJogador.x - pos.x)<200)
            {
                if(voa==true)
                    ataque(posiJogador);
                else
                {
                    if(abs(posiJogador.y - pos.y)<100)
                    {
                        ataque(posiJogador);
                    }
                }
            }
            else if(abs(posiJogador.x - pos.x)<400 && abs(posiJogador.y - pos.y)<400)
            {
                if(voa==true || abs(posiJogador.y - pos.y)<100)
                    persegueJogador(posiJogador, 0.8);

                atacar = false;
            }
            else
            {
                movimentoAleatorio();
                atacar = false;
            }

            if (abs(posiJogador.x - pos.x)<200) { atacar = true; }

            //cair();

			pos.y = pos.y + vely;
			pos.x = pos.x + velx;

			corpo->Position->Point = TPointF(pos.x, pos.y);
			verifImg();

			velx = 0;

        }
    
}

void Inimigo::persegueJogador(TPointF posiJogador, float x)
{
    
    velx = 0.0;

	if((posiJogador.x - pos.x)<0) {  velx = velx - x; }

	else if((posiJogador.x - pos.x)>0) { velx = velx + x; }

    if(voa==true)
    {
        if((posiJogador.y - pos.y)<0)
			vely = vely - x;
        else if((posiJogador.y - pos.y)>0)
			vely = vely + x;
        else
			vely = 0;
    }
    

}

void Inimigo::movimentoAleatorio()
{
    if(movAl==1)
    {
		velx = velx + 0.4;
    }
    else
    {
		velx = velx - 0.4;
    }

	atual = clock();
	float dt = atual - inicio;
    if(dt>=1)
    {
		inicio = clock();
		movAl = rand()%2;
    }

}

void Inimigo::ataque(TPointF posiJogador)
{
	velx = 0.0;

	if((posiJogador.x - pos.x)<0) {  velx = velx - 1.5; }

	else if((posiJogador.x - pos.x)>0) { velx = velx + 1.5; }

        
}

void Inimigo::congela() {
    setVelX(0.0f);
    setVelY(-0.3f);
    cair();
}