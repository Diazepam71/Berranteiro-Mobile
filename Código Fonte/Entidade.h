#pragma once
#include "Ente.h"

namespace Entidades
{
	class Entidade: public Ente{
	protected:
		float velx, vely;
		bool vivo;
		bool atacar;
		bool obstaculo;
		bool item;
		bool projetil;
		int numVidas;
	public:
		Entidade(const int v, TPointF p, Fmx::Types::TFmxObject* parent);
		~Entidade();
		virtual void move() = 0;
		void cair();
		float getVelX() { return velx; };
		float getVelY() {return vely; };
		int getVidas(){ return numVidas; }
		void setVelX(float x);
		void setVelY(float y);
		bool getAtacar();
		void setAtacar(bool a);
		bool getVivo();
		void setVivo(bool v);
		void operator++();
		void operator--();
		void repos(float x, float y) { pos.X = pos.X + x; pos.Y = pos.Y + y; setPos(pos); };
		virtual void setVidas(int n);
		bool getObstaculo();
		bool getIsItem() { return item; }
        bool getProjetil() {return projetil; };
	};
}