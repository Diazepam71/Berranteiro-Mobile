#pragma once
#include <iostream>
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Objects.hpp>
#include <string>
//#include "GerenciadorGrafico.h"
using namespace std;
//using namespace Gerenciadores;

//class GerenciadorGrafico;
class Ente
{
	protected:
		TPointF pos;
		TImage* corpo;
		TBitmap* textura;
		//GerenciadorGrafico* gerente;
		TRectF posRect;


    public:

		Ente(TPointF p, Fmx::Types::TFmxObject* owner);
		~Ente();
        //virtual void executar() = 0;
		//virtual void imprimir();
		//float getPosX() {return posx;};
		TPointF getPos() {return pos;}
		TImage* getCorpo() {return corpo;};
		TBitmap* getTextura() { return textura; };
		void setPos(TPointF p);
		float getTamX() {return corpo->Width;};
		float getTamY() {return corpo->Height; };
		//static GerenciadorGrafico* getGerente() { return gerente; }
		void setTextura(TBitmap* tx);
		void setTextura(System::UnicodeString s);
		void imprimir();
		void atualizaPosRect();
};