#include "Ente.h"
#include <FMX.Dialogs.hpp>
#include <System.Ioutils.hpp>
//#include "GerenciadorGrafico.h"

//GerenciadorGrafico* Ente::gerente = GerenciadorGrafico::getGerenciadorGrafico();

Ente::Ente(TPointF p, Fmx::Types::TFmxObject* owner)
{
    //gerente = GerenciadorGrafico::getGerenciadorGrafico();
	pos = p;
	//Owner = owner;
	//dynamic_cast <TForm*> Owner->ShowMessage("CONSTRUTORA: Inicio.");
	//Dialogs::ShowMessage("CONSTRUTORA: Inicio.");
	corpo = new TImage(NULL);
    corpo->Parent = owner;
	textura = new TBitmap();
	//Dialogs::ShowMessage("CONSTRUTORA: New's realizados.");
	//textura = new sf::Texture;
    /*if(!textura.loadFromFile("Midia/Imagens/Roxo.png")) std::cout << "Erro na abertura da textura roxa para o ente." << std::endl;
    else {
        std::cout << "Foi criado um ente com a textura roxa." << std::endl;
        corpo.setTexture(textura);
    }*/
	//corpo->Bitmap->Assign(textura);
	//textura->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Nada.png"));
	//Dialogs::ShowMessage("CONSTRUTORA: Textura Carregada.");
	//corpo->Bitmap->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"J1Direita.png"));
	//corpo.setTextureRect(sf::IntRect(0, 0, 288, 370));
	corpo->Position->Point = pos;
	corpo->Bitmap->Assign(textura);
	corpo->Position->X = pos.X;
	corpo->Position->Y = pos.Y;
	atualizaPosRect();
	comp = 0;
	alt = 0;
}

Ente::~Ente() {
	delete corpo;
	delete textura;
 }

void Ente::setPos(TPointF p) {
	pos = p;
	corpo->Position->Point = pos;
	atualizaPosRect();
}

void Ente::setTextura(TBitmap* tx) {
	if (tx == textura) return;
	if (textura) delete textura;
	textura = new TBitmap;
	textura->Assign(tx);
	corpo->Bitmap->Assign(textura);
 }

void Ente::setTextura(System::UnicodeString s) {
	textura->LoadFromFile(s);
	corpo->Bitmap->Assign(textura);
 }

void Ente::imprimir() {
	//Dialogs::ShowMessage("IMPRIMIR: Inicio.");
	//if (corpo->Canvas == NULL) Dialogs::ShowMessage("IMPRIMIR: Canvas = NULL.");
	 //gerente->desenhaElemento(corpo);
	 corpo->Bitmap->Canvas->BeginScene();
	 corpo->Bitmap->Canvas->DrawBitmap(textura, textura->BoundsF, posRect, 1.0, true);
	 corpo->Bitmap->Canvas->EndScene();
}

void Ente::atualizaPosRect() {
	float deltax = -1*(posRect.left - corpo->Position->Point.x);
	float deltay = -1*(posRect.top - corpo->Position->Point.y);
	posRect.left += deltax;
	posRect.right += deltax;
	posRect.top += deltay;
	posRect.bottom += deltay;

}