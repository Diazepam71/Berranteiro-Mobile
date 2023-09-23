#include "GerenciadorGrafico.h"

GerenciadorGrafico* GerenciadorGrafico::pGrafico = NULL;

GerenciadorGrafico::GerenciadorGrafico() {
	canvas = new TCanvas();
	TPointF x(0, 0) ;
	canvas->Offset = x;
}

GerenciadorGrafico::~GerenciadorGrafico() {
	if (pGrafico) delete pGrafico;
}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico() {
	if (pGrafico == NULL) {
		pGrafico =  new GerenciadorGrafico();
	}
	return pGrafico;
}

void GerenciadorGrafico::limpaJanela() {
	canvas->Clear();
}

void GerenciadorGrafico::desenhaElemento(TImage* x) {
	TRectF tmp;
    tmp.left = x->Bitmap->BoundsF.left + x->Position->Point.x;
	canvas->DrawBitmap(x->Bitmap, x->Bitmap->BoundsF, x->Bitmap->BoundsF + x->Position->Point);

}

TPointF GerenciadorGrafico::getCoorView () {
	return canvas->Offset;

}

void GerenciadorGrafico::setView(TPointF p) {canvas->Offset = p;}