#pragma once

class Valor
{
public:
	Valor();
	Valor(int valor, int segur);
	virtual ~Valor();
	int getValorVal();
	int getValorSegur();
	void setValorVal(int val);
	void setValorSegur(int seg);

private:
	int valor;
	int segur;
};


