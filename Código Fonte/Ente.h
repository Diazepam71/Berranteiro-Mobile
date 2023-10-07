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
using namespace std;

class Ente
{
	protected:
		TPointF pos;
		TImage* corpo;
		TBitmap* textura;
		TRectF posRect;
        float comp, alt;

	public:
		Ente(TPointF p, Fmx::Types::TFmxObject* owner);
		~Ente();
		TPointF getPos() {return pos;}
		TImage* getCorpo() {return corpo;};
		TBitmap* getTextura() { return textura; };
		void setPos(TPointF p);
		float getTamX() {return corpo->Width;};
		float getTamY() {return corpo->Height; };
		void setTextura(TBitmap* tx);
		void setTextura(System::UnicodeString s);
		void imprimir();
		void atualizaPosRect();
};








