#include "Item.h"

Item::Item(Jogador* jo, float x, float y, Fmx::Types::TFmxObject* parent, System::Classes::TComponent* owner) : Entidade(100, TPointF(0.0f, 0.0f), parent) {
	j = jo;
	this->setPos(TPointF(x,y));
	nome = "\n";
	item = true;
	//som = new TMediaPlayer(owner);
	//som->FileName = "";
}

Item::~Item() {}

void Item::pegar() {}

void Item::move() {
	//pos.x = pos.x + vel.x;
	//pos.y = pos.y + vel.y;
	//corpo.setPosition(pos.x, pos.y);

	//GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	if (pos.x > 800 || pos.x < -100 || pos.y > 500 || pos.y < -100) {
		setVelX(0.0f);
		setVelY(-0.3f);
		cair();
	}
	else
	{
		pos.y += vely;
		setPos(TPointF(pos.x, pos.y));
	}
}

void Item::setSound(System::UnicodeString s) {
	//som->FileName = s;
};

void Item::findar() {}

void Item::setVidas(int n) {
	numVidas = n;
	if (n <= 0) {
		vivo = false;
		//if (som->FileName != "") som->Play();
		findar();
        //Item::~Item();
	}
	else vivo = true;
}