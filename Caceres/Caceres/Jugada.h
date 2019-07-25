#pragma once

class Jugada
{
public:
	Jugada();
	Jugada(int orig, int desti, int especial);
	virtual ~Jugada();
	int getInicial();
	int getFinal();
	int getCorOCapt();
	void setInicial(int ini);
	void setFinal(int fin);
	void setCorOCapt(int corOCapt);

protected:

private:
	int inicial;
	int fi;
	int corOCapt;
};

