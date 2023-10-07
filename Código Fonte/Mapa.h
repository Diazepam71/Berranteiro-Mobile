#pragma once
#include "ListaEntes.h"
#include "Plataforma.h"
using namespace Entidades;
using namespace Listas;

class Mapa {
private:
	Lista<Plataforma> lista;
	Lista<Plataforma>* colidiveis;
	Lista<Plataforma> c1, c1b, c2, c2b, c3;
	float len, ini;
	TBitmap* imagem;
	Fmx::Types::TFmxObject* Parent;
	int start;
public:
	Mapa();
	Mapa(TPointF ini, TPointF fim, TBitmap* img, Fmx::Types::TFmxObject* parent);
	~Mapa();
	void inicializaAuto(TPointF ini, TPointF fim);
	Lista<Plataforma>* getLista();
	void imprimir();
	Lista<Plataforma>* getColidiveis();
	Lista<Plataforma>* getC1();
	Lista<Plataforma>* getC1b();
	Lista<Plataforma>* getC2();
	Lista<Plataforma>* getC2b();
	Lista<Plataforma>* getC3();
	float getLen();
	void setColidiveis(Lista<Plataforma>* l);
	float getIni();
	void setImagem(TBitmap* img) {imagem = img;};
	void reposMapa(float x, float y);
	int getStart();
};