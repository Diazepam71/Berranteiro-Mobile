#include "Soldado.h"
#include "Item.h"
#include "MP5.h"
#include "Skorpion.h"
#include "MunicaoMP5.h"
#include "MunicaoSkorpion.h"
#include "Chave.h"
#include "Granada.h"
using namespace Itens;
using namespace Entidades;
using namespace Personagens;
Soldado::Soldado(Jogador *j1, float x, float y, int s, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner) :
Inimigo(j1, x, y, parent)
{
	item = "";
	contador = 0;
	corre = false;
	int i;
    //numVidas = 50;
    ataqueDistancia = true;
    voa = false;
	skin = s;
	numVidas = 100;
	s1 = NULL;
	if(s==1)
	{
		arma = new Arma("mp5-s", parent);
		Tdir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Soldado-D.png"));
		Tesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Soldado-E.png"));
		Adir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Soldado-AD.png"));
		Aesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Soldado-AE.png"));
		corpo->Width = 66;
		corpo->Height = 74;
	}
	else
	{
		arma = new Arma("skorpion-s", parent);
		Tdir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Soldado2-D.png"));
		Tesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Soldado2-E.png"));
		Adir->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Soldado2-AD.png"));
		Aesq->LoadFromFile(System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath(), L"Soldado2-AE.png"));
		corpo->Width = 74;
		corpo->Height = 68;
	}
	
	
    /*srand(time(NULL));
    i = rand()%3 + 1;
    if(i==1)
        arma = new Arma("pistola", true);
    else if(i==2)
        arma = new Arma("mp5", true);
    else if(i=3)
        arma = new Arma("skorpion", true);
    */
}
Soldado::~Soldado()
{
	delete arma;
}
void Soldado::move()
{
	if (pos.x > 1500 || pos.X < -300 || pos.y < -300 || pos.y > 1000) {
		congela();
	}
	else
	{
		TPointF posiJogador;
		posiJogador = jogador1->getPos();
		if(((abs(posiJogador.x - pos.x)<500 && abs(posiJogador.y - pos.y)<50)))
		{
			persegueJogador(posiJogador, 0.1);
			if(atacar==true)
			{
				//persegueJogador(posiJogador, 0.1);
				ataque(posiJogador);
				//contador++;
			}
			/*if(arma->getMagvar() == 0)
				arma->setRecarregando(1);*/
		}
		/*else if((abs(posiJogador.x - pos.x)<1000 && abs(posiJogador.y - pos.y)<200) && corre == true)
			persegueJogador(posiJogador);*/
		/*else
		{
			movimentoAleatorio();
			atacar = false;
		}*/
		if(contador==3)
		{
			atacar = false;
			contador = 0;
		}
		//dt = relogio.getElapsedTime().asSeconds();
		if((clock() - relogio) / CLOCKS_PER_SEC >=2)
    	{
			relogio = clock();
        	atacar = true;
    	}

				//cair();
		pos.y = pos.y + vely;
		pos.x = pos.x + velx;
		setPos(TPointF(pos.x, pos.y));
		verifImg();
		velx = 0;
	}
}
void Soldado::afastar(TPointF posiJogador)
{
	int v;
	v = 3;
	velx = 0.0;
	if((posiJogador.x - pos.x)<0) {  velx = velx + v; }
	else if((posiJogador.x - pos.x)>0) { velx = velx - v; }
	//if(vel.y==0) { vel.y = -2; }
}
void Soldado::viradoEsq()
{
	setTextura(Tesq);
	if(skin==1){
		corpo->Width = 66;
		corpo->Height = 74;
	}
	else{
		corpo->Width = 74;
		corpo->Height = 68;
	}
}
void Soldado::viradoDir()
{
	setTextura(Tdir);
	if(skin==1){
		corpo->Width = 66;
		corpo->Height = 74;
	}
	else{
		corpo->Width = 74;
		corpo->Height = 68;
	}
}
void Soldado::ataqueDir()
{
	setTextura(Adir);
	if(skin==1){
		corpo->Width = 80;
		corpo->Height = 74;
	}
	else{
		corpo->Width = 88;
		corpo->Height = 67;
	}
}
void Soldado::ataqueEsq()
{
	setTextura(Aesq);
	if(skin==1){
		corpo->Width = 80;
		corpo->Height = 74;
	}
	else{
		corpo->Width = 88;
		corpo->Height = 67;
	}
}
Ente* Soldado::hitscan(Ente* e) {
	if (virado == 0) {
		if (((e->getPos().Y <= this->getPos().Y + 40 && e->getPos().Y + e->getTamY() >= this->getPos().Y + 40) || (e->getPos().Y <= this->getPos().Y + 60 && e->getPos().Y + e->getTamY() > this->getPos().Y + 60)) && (e->getPos().X + e->getTamX() > this->getPos().X + this->getTamX() - 10) && e->getPos().X < this->getPos().X + this->getTamX() + arma->getAlc()) return e;
	}
	else if (virado == 1) {
		if (((e->getPos().Y <= this->getPos().Y + 40 && e->getPos().Y + e->getTamY() >= this->getPos().Y + 40) || (e->getPos().Y <= this->getPos().Y + 60 && e->getPos().Y + e->getTamY() > this->getPos().Y + 60)) && (e->getPos().X < this->getPos().X - 10) && e->getPos().X + e->getTamX() > this->getPos().X - arma->getAlc()) return e;
	}
	return NULL;
}
void Soldado::ataque(TPointF posiJogador)
{
	clock_t t1 = clock();
	if (t1 / CLOCKS_PER_SEC - arma->getClock() / CLOCKS_PER_SEC < 1.0 / arma->getCad()) return;
	contador++;
	//std::cout << t1 / (float) CLOCKS_PER_SEC << " - " << arma->getClock() / (float) CLOCKS_PER_SEC << " = " << t1 / (float) CLOCKS_PER_SEC - arma->getClock() / (float) CLOCKS_PER_SEC << "\n";
	arma->setClock(t1);
	if (arma->getSom()->State == TMediaState::Playing) arma->getSom()->CurrentTime = 0;
	else arma->getSom()->Play();
	Ente* e = NULL, *e1 = NULL;
	//int min=99999999999;
	
		e = hitscan(jogador1);
		if (e != NULL) if (static_cast <Jogador*> (e)->getVivo() == false) {
			e = NULL;
			//cont++;
		}
		if (e != NULL){ //if (fabs(e->getPos().x - this->getPos().x) < min) {
			//min = e->getPos().x - this->getPos().x;
			e1 = e;
		}
	
	e = e1;
	
	arma->setMagvar(arma->getMagvar() - 1);
	arma->setAmmo(arma->getAmmo() - 1);
	if (e == NULL) return;
	//std::cout << "ATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\n";
	static_cast <Jogador*> (e)->setVidas(static_cast <Jogador*> (e)->getVidas() - arma->getDano());
	
}
void Soldado::setVidas(int n) {

	if (numVidas > 0 && n <= 0 && vivo == true) {
		vivo = false;
        Item* i = f->geraItem(pos.x, pos.y, item);
		if (item.operator[](0) == 'c' && item.operator[](1) == 'h')  static_cast <Chave*> (i)->setFase(f);
		srand(time(NULL));
		int x = rand() % 2;
        corpo->Width = 0;
		corpo->Height = 0;
		jogador1->setPontos(jogador1->getPontos() + 150);
		int z = rand() % 3;
		if (z != 0) {
			Item* ii = f->geraItem(pos.X + 30, pos.Y + 30, "granada");
			static_cast <Granada*> (ii)->setQtd(z);
		}
		if (x != 1) return;
		if (skin == 1) {
			Item* i = f->geraItem(pos.x, pos.y, "municaomp5");
			int y = rand() % 23;
			static_cast <MunicaoMP5*> (i)->setValor(26 + y);
		}
		else {
			Item* i = f->geraItem(pos.x, pos.y, "municaoskorpion");
			int y = rand() % 16;
			static_cast <MunicaoSkorpion*> (i)->setValor(25 + y);
		}
	}
	numVidas = n;
}