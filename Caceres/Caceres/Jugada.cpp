#include "jugada.h"


Jugada::Jugada()
{
	//ctor
}

Jugada::Jugada(int orig, int desti, int especial) {
	inicial = orig;
	fi = desti;
	corOCapt = especial;
}


Jugada::~Jugada()
{
	//dtor
}

int Jugada::getInicial() {
	return inicial;
}

int Jugada::getFinal() {
	return fi;
}

int Jugada::getCorOCapt() {
	return corOCapt;
}

void Jugada::setInicial(int ini) {
	inicial = ini;
}
void Jugada::setFinal(int fin) {
	fi = fin;
}

void Jugada::setCorOCapt(int corOCapt) {
	this->corOCapt = corOCapt;
}

