#include "Plataforma.h"
#include <time.h>
#include <iostream>
#include <FMX.Dialogs.hpp>
//#include <FMX.Types.TPixelFormat>

using namespace Entidades;

Plataforma::Plataforma(TPointF* coor, TBitmap* mapa, Fmx::Types::TFmxObject* parent) : Entidade(0, *coor, parent){
	TBitmapData x;
    float f = 0;
	int qtd = 1;
	bool flag = 0;
	nula = false;
	if (mapa->Map(Fmx::Graphics::TMapAccess::Read, x)) {
		System::Uitypes::TAlphaColor p1 = x.GetPixel(coor->X / 2.0f, coor->y /2.0f);
		System::Uitypes::TAlphaColor p2 = x.GetPixel(coor->X / 2.0f + 15.0f, coor->y /2.0f + 15.0f);
		System::Uitypes::TAlphaColor p3 = x.GetPixel(coor->X / 2.0f + 7.0f, coor->y /2.0f + 7.0f);
		mapa->Unmap(x);
		if (p1 == TAlphaColor(0x0) && p2 == TAlphaColor(0x0) && p3 == TAlphaColor(0x0)) {
			nula = true;
			coor->x += 32;
            goto FIM;
			//ShowMessage("Plataforma Nula.");
		}
		//else ShowMessage("Plataforma Não Nula criada.");
	}



	if (mapa->Map(Fmx::Graphics::TMapAccess::Read, x)) {
		for (f = coor->x + 32; f < mapa->Width * 2; f = f + 32) {

			//TBitmapData* x = dynamic_cast <TBitmapData*> (textura);
			System::Uitypes::TAlphaColor p1 = x.GetPixel(f / 2.0f, coor->y /2.0f);
			System::Uitypes::TAlphaColor p2 = x.GetPixel(f / 2.0f + 15.0f, coor->y /2.0f + 15.0f);
			System::Uitypes::TAlphaColor p3 = x.GetPixel(f / 2.0f + 7.0f, coor->y /2.0f + 7.0f);



			if (p1 == TAlphaColor(0x0) && p2 == TAlphaColor(0x0) && p3 == TAlphaColor(0x0)) {
				flag = 1;
				//if (qtd == 0) std::cout << "Não ha plataforma.\n";
				//else std::cout << "Fim do bloco de plataformas. qtd = " << qtd << ".\n";
				break;
			}
			else {
				qtd++;
			}
		}
	}
    mapa->Unmap(x);

	if (qtd > 0) {
		//if (!textura.loadFromImage(teste, sf::IntRect(coor->x / 2.0, coor->y / 2.0, 16 * qtd, 16))) std::cout << "Erro no carregamento da textura da plataforma.\n";
        //ShowMessage("Chegou.");
		//TBitmap* tex = new TBitmap();
		//TBitmap* tex = new TBitmap(16 * qtd, qtd);
		corpo->Bitmap->Resize(16 * qtd, 16);
		corpo->Bitmap->CopyFromBitmap(mapa, System::Types::TRect(coor->x / 2.0, coor->y /2.0, 16 * qtd + coor->x / 2.0f, 16 + coor->y / 2.0f), 0 ,0);
		corpo->Width = 32 * qtd;
		corpo->Height = 32;
		//corpo->Scale->Point = TPointF(2, 2);
		//textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Tile.png"));
		//setTextura(textura);
		//corpo->Bitmap->Assign(textura);
		//delete tex;
        setPos(*coor);


		coor->x = f;

	}
	else if (flag == 1) coor->x += 32;
	else coor->x += 9999999999;
	FIM:;
}

Plataforma::~Plataforma() {
	//gerente = NULL;
	pos = TPointF(-1.0f, -1.0f);
	if (teste) delete teste;
}

const bool Plataforma::getNula() { return nula; }

void Plataforma::setImagem(TBitmap* i) { teste = i; }

TBitmap* Plataforma::loadAlt(System::UnicodeString s) {
	//if (i) delete i;
	TBitmap* i = new TBitmap();
	//i->LoadFromFile(s);
	return (i);
}

const bool Plataforma::verifNula(TPointF coor) {
	//std::cout << "VerifNula inicializado.\n";
	TBitmapData x;
	if (teste->Map(Fmx::Graphics::TMapAccess::ReadWrite, x)) {
			//TBitmapData* x = dynamic_cast <TBitmapData*> (teste);
			System::Uitypes::TAlphaColor p1 = x.GetPixel(coor.X / 2.0f, coor.y /2.0f);
			System::Uitypes::TAlphaColor p2 = x.GetPixel(coor.X / 2.0f + 15.0f, coor.y /2.0f + 15.0f);
			System::Uitypes::TAlphaColor p3 = x.GetPixel(coor.X / 2.0f + 7.0f, coor.y /2.0f + 7.0f);
			teste->Unmap(x);

		if (p1 == TAlphaColor(0x0) && p2 == TAlphaColor(0x0) && p3 == TAlphaColor(0x0)) return true;
		else return false;
	}
	return true;
}

void Plataforma::move() { }
