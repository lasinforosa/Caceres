#include "valor.h"


Valor::Valor()
{
	//ctor
}

Valor::~Valor()
{
	//dtor
}

Valor::Valor(int valor, int segur) {
	this->valor = valor;
	this->segur = segur;

}

int Valor::getValorVal() {
	return valor;
}

int Valor::getValorSegur() {
	return segur;
}

void Valor::setValorVal(int val) {
	this->valor = val;
}

void Valor::setValorSegur(int seg) {
	segur = seg;
}
