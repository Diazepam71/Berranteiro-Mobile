#pragma once
#include <time.h>
#include <string>
#include <Fmx.Media.hpp>
using namespace std;

class Arma {
protected:
	clock_t t0, tr;
	//sf::Sprite *Sesq, *Sdir;
	float dano, cad, rec, alc, mag, magvar, ammo;
	TBitmap *Tesq, *Tdir, *Aesq, *Adir;
	TMediaPlayer *s, *e, *d, *r;
	TMediaPlayer* r0, *r1;
	string nome;
	bool hitscan, dry, recarregando;
	bool inimigo;
	System::Classes::TComponent* Owner;

public:
	Arma(string n, System::Classes::TComponent* owner);
	~Arma();
	TBitmap* getTdir();
	TBitmap* getTesq();
	TBitmap* getAdir();
	TBitmap* getAesq();
	//void atirar();
	float getDano() { return dano; };
	float getRec() { return rec; };
	float getCad() { return cad; };
	float getAlc() { return alc; };
	clock_t getClock() { return t0; };
	void setClock(clock_t t) { t0 = t; };
	TMediaPlayer* getSom() { return s; };
	TMediaPlayer* getSomEquip() { return e; };
	bool getHitscan() { return hitscan; };
	void setMagvar(float x) { 
		if (x <= 0) dry = 1;
		magvar = x;
	};
	float getMag() { return mag; };
	float getMagvar() { return magvar; };
	void setDry(int x) { dry = x; };
	bool getDry() { return dry; };
	TMediaPlayer* getSomDry() { return d; };
	void recarregar();
	clock_t getTR() { return tr; };
	bool getRecarregando() { return recarregando; };
	void setRecarregando(int x) { recarregando = x; };
	void setAmmo(float x) { 
		ammo = x; 
		if (ammo <= 0) dry = 1;
	};
	float getAmmo() { return ammo; };
	void verifReload();
	string getNome() { return nome; };
	void setDano(float x) { dano = x; };
	void setCad(float x) { cad = x; };
	void setRec(float x) { rec = x; };
	void setAlc(float x) { alc = x; };
	void setMag(float x) { mag = x; };
	void setNome(string s) { nome = s; };
	void setTesq(System::UnicodeString s) { Tesq->LoadFromFile(s); };
	void setAesq(System::UnicodeString s) { Aesq->LoadFromFile(s); };
	void setTdir(System::UnicodeString s) { Tdir->LoadFromFile(s); };
	void setAdir(System::UnicodeString s) { Adir->LoadFromFile(s); };
	void setOwner(System::Classes::TComponent* owner) {
		Owner = owner;
		//e->Owner = Owner;
		//r->Owner = Owner;
		//s->Owner = Owner;
        //d->Owner = Owner;
	};
    TMediaPlayer* getR1() {return r1;};
};
