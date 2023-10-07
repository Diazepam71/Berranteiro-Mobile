#include "Curupira.h"
#include "Chave.h"

using namespace Entidades;
using namespace Personagens;
using namespace Itens;


Curupira::Curupira(Jogador* j1, float x, float y, Fmx::Types::TFmxObject* parent):
Inimigo(j1, x, y, parent)
{
	dano = 1;
	numVidas = 1000;
	ressucitar = false;
    ataqueDistancia = true;
	atirar = true;
	corre = false;
	fogo = new Projetil(x, y + 40, parent);
	fogo->setAtirador(static_cast<Inimigo*>(this));
	virado = 1;
	Tdir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"CurupiraDireita.png"));
	Tesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"CurupiraEsquerda.png"));
	Adir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"CurupiraAtaqueDireita.png"));
	Aesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"CurupiraAtaqueEsquerda.png"));
	corpo->Bitmap->Assign(Tesq);

	corpo->Width = 48;
	corpo->Height = 90;
}

Curupira::~Curupira()
{
	fogo = NULL;
	animais->~ListaEntes();
}
void Curupira::viradoEsq()
{
	setTextura(Tesq);
	corpo->Width = 48;
	corpo->Height = 90;
}
void Curupira::viradoDir()
{
	setTextura(Tdir);
	corpo->Width = 48;
	corpo->Height = 90;
}
void Curupira::ataqueDir()
{
	
	setTextura(Adir);
	corpo->Width = 60;
	corpo->Height = 84;
}
void Curupira::ataqueEsq()
{
	setTextura(Aesq);
	corpo->Width = 60;
	corpo->Height = 84;
}

void Curupira::move()
{
	if ((clock() - proj) /CLOCKS_PER_SEC > 6) fogo->setVidas(3);
	if (pos.x > 1500 || pos.X < -300 || pos.y < -300 || pos.y > 1000) {
		congela();
	}
	else
	{
		TPointF posiJogador;

		posiJogador = jogador1->getPos();


		if (abs(posiJogador.x - pos.x)<200 && abs(posiJogador.y - pos.y)<200)
		{
			afastar(posiJogador);
			atacar = false;
			corre = true;
		}
		else if(((abs(posiJogador.x - pos.x)<600 && abs(posiJogador.y - pos.y)<600)) && corre == false)
		{
			ataque(posiJogador);
			atacar = true;
		}
		else if ((abs(posiJogador.x - pos.x)<1000 && abs(posiJogador.y - pos.y)<1000) && corre == true)
		{
			corre = false;
		}
		else
		{
			movimentoAleatorio();
			atacar = false;
		}


				//cair();

		pos.y = pos.y + vely;
		pos.x = pos.x + velx;

		setPos(TPointF(pos.x, pos.y));
		verifImg();

		velx = 0;
		if (fogo->getVivo() == false && (clock() - proj) / CLOCKS_PER_SEC > 6.2) {
			proj = clock();
		}
	}

}

void Curupira::ataque(TPointF posiJogador)
{

	if(atirar==true && fogo->getAtivado()==false)
	{
		fogo->setAtivado(true);
        if((posiJogador.x - pos.x)<0) 
        { 
            fogo->setDireita(false);
        }
        else if((posiJogador.x - pos.x)>0) 
        { 
            fogo->setDireita(true);
        }
	}
    else
    {
        persegueJogador(posiJogador, 0.8);
    }

	atirar = false;
	ressucitar = false;

	calculaRessucitar();
	if(ressucitar == true) { ressucitarAnimais(); }

	//float dt = relogio.getElapsedTime().asSeconds();
		if((clock() - relogio) / CLOCKS_PER_SEC >=3)
    	{
			relogio = clock();
        	atirar = true;
    	}
}

void Curupira::afastar(TPointF posiJogador)
{
	int v;
	v = 3;

	velx = 0.0;

	if((posiJogador.x - pos.x)<0) {  velx = velx - v; }

	else if((posiJogador.x - pos.x)>0) { velx = velx + v; }

	if(vely==0) { vely = -2; }
}
void Curupira::calculaRessucitar()
{
	srand(time(NULL));
	
	int verif = rand()%15;
	if (verif == 10)
	{
		ressucitar = true;
	}
}

void Curupira::ressucitarAnimais()
{
	Lista<Entidade>::Elemento<Entidade> *aux;
	Entidade *tipo;
	aux = animais->getLista()->getPrimeiro();
	
	while(aux->getProximo()->getProximo()!=NULL)
	{
		tipo = aux->getInfo();
		tipo->setVidas(10);
		aux = aux->getProximo();
	}

}

void Curupira::setLista(ListaEntes *l)
{
    animais = l;
}

Projetil* Curupira::getFogo()
{
	return fogo;
}

void Curupira::setVidas(int x) {
	numVidas = x;
	if (x <= 0) {
		Item* i = f->geraItem(pos.x, pos.y, item);
		static_cast <Chave*> (i)->setFase(f);
		vivo = false;
		corpo->Width = 0;
        corpo->Height = 0;
	}
	else vivo = true;
}
	