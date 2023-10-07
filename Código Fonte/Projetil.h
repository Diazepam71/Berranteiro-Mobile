#pragma once
#include "Entidade.h"
#include "Inimigo.h"

using namespace Personagens;

namespace Entidades
{

	class Projetil: public Entidade
	{
		private:
			float distanciaPercorrida;
			float alcance;
			bool direita;
			bool ativado;
			float dano;
			Inimigo *atirador;
			clock_t relogio;

		public:
			Projetil(float x, float y, Fmx::Types::TFmxObject* parent);
			~Projetil();
			void move();
			void setAtivado(bool b);
			bool getAtivado();
			void setDireita(bool b);
			void setAtirador(Inimigo *i);
			float getDano() {return dano; };
            void setVidas(int n);
	};

}