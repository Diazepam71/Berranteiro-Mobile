#pragma once
#include "Entidade.h"
#include <System.Ioutils.hpp>
#include <string>
using namespace std;

namespace Entidades
{

	class Plataforma : public Entidade {
	private:
		//static TBitmap* teste;
		bool nula = false;
		//TBitmap* textura;

	public:
		TBitmap* teste;
		Plataforma(TPointF* coor, TBitmap* mapa, Fmx::Types::TFmxObject* parent);
		~Plataforma();
		void move();
		const bool getNula();
		void setImagem(TBitmap* i);
		TBitmap* loadAlt(System::UnicodeString s);
		const bool verifNula(TPointF coor);
	};

}
