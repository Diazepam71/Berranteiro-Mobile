//---------------------------------------------------------------------------

#pragma hdrstop

#include "Explosao.h"

Explosao::Explosao(float s, float x, float y, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner)
: Obstaculo(x, y, parent) {
	som = new TMediaPlayer(owner);
	som->FileName = (System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"explode3.wav"));

	expl = new TBitmap();
	contaQuadros = 0;
	expl->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Explosao.png"));
    corpo->Bitmap->Resize(49,42);
	corpo->Bitmap->CopyFromBitmap(expl, System::Types::TRect(0,0,49,42),0,0);
	//corpo->Bitmap->Assign(textura);
	corpo->Width = 49;
	corpo->Height = 42;
	corpo->Position->Point = TPointF(x, y);
	corpo->Scale->X = s;
    corpo->Scale->Y = s;
	danoso = 300;
	atacar = true;
	f = NULL;
}

Explosao::~Explosao() {
	delete expl;
	delete som;
}

void Explosao::move() {
    if (contaQuadros == 0) som->Play();
	if (contaQuadros < 3) {
		if (contaQuadros == 0) {
			corpo->Bitmap->Resize(49, 42);
			corpo->Bitmap->CopyFromBitmap(expl, System::Types::TRect(0,0,49,42),0,0);
		}
		//corpo->Bitmap->Assign(textura);
		corpo->Width = 49;
		corpo->Height = 42;
	}
	else if (contaQuadros < 7) {
		if (contaQuadros == 3) {
			corpo->Bitmap->Resize(79, 74);
			corpo->Bitmap->CopyFromBitmap(expl, System::Types::TRect(150,0,229,74),0,0);
		}
		//corpo->Bitmap->Assign(textura);
		corpo->Width = 79;
		corpo->Height = 74;
	}
	else if (contaQuadros < 12) {
		if (contaQuadros == 7) {
			corpo->Bitmap->Resize(98, 90);
			corpo->Bitmap->CopyFromBitmap(expl, System::Types::TRect(300,0,398,90),0,0);
		}
		//corpo->Bitmap->Assign(textura);
		corpo->Width = 98;
		corpo->Height = 90;
	}
	else if (contaQuadros < 18) {
		if (contaQuadros == 12) {
			corpo->Bitmap->Resize(106, 105);
			corpo->Bitmap->CopyFromBitmap(expl, System::Types::TRect(450,0,556,105),0,0);
		}
		//corpo->Bitmap->Assign(textura);
		corpo->Width = 106;
		corpo->Height = 105;
	}
	else if (contaQuadros < 22) {
		if (contaQuadros == 18) {
			corpo->Bitmap->Resize(104, 104);
			corpo->Bitmap->CopyFromBitmap(expl, System::Types::TRect(600,0,704,104),0,0);
		}
		//corpo->Bitmap->Assign(textura);
		corpo->Width = 104;
		corpo->Height = 104;
	}
	else if (contaQuadros < 26) {
		if (contaQuadros == 22) {
			corpo->Bitmap->Resize(103, 104);
			corpo->Bitmap->CopyFromBitmap(expl, System::Types::TRect(750,0,853,104),0,0);
		}
		//corpo->Bitmap->Assign(textura);
		corpo->Width = 103;
		corpo->Height = 104;
	}
	else if (contaQuadros < 29) {
		if (contaQuadros == 26) {
			corpo->Bitmap->Resize(119, 108);
			corpo->Bitmap->CopyFromBitmap(expl, System::Types::TRect(900,0,1019,108),0,0);
		}
		//corpo->Bitmap->Assign(textura);
		corpo->Width = 119;
		corpo->Height = 108;
	}
	else {
		setVidas(0);
		corpo->Width = 0;
        corpo->Height = 0;
    }
	contaQuadros++;
	f->getGCol()->trataExplosao(this);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
