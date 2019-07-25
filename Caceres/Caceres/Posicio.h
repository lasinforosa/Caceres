#pragma once


#include "jugada.h"
#include "valor.h"

using namespace std;



class Posicio
{

public:

	Posicio();
	virtual ~Posicio();
	int getQuiMou();
	int getPecesBlanques(int i);
	int getPecesNegres(int i);
	int getCassella(int i);
	void posicioInicial();
	void setPosicio(int board[], int blancas[], int negras[], int colores[], int enroques,
		int alPaso, int halfmov, int mou, double hash, Valor elValor);
	void updatePos(Jugada jug);
	void imprimeixEscaquer();

protected:

private:
	int escaquer[144];
	int pecesBlanques[16];
	int pecesNegres[16];
	int colorCasselles[144];
	int enrocs; // 0 + 1 + 2 + 3 + 5 tots els enrocs
	int alPas;
	int ply;
	int quiMou;
	double hashPos;
	Valor valorPos;
};

