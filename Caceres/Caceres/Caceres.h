#pragma once

#include "posicio.h"

#define REI    1
#define DAMA   2
#define TORRE  3
#define ALFIL  4
#define CAVALL 5
#define PEO    6

#define BUIT   0
#define BLANC  1
#define NEGRE  -1

const int MOVS_TORRE[] = { 1,12,-1,-12 };
const int MOVS_CAVALL[] = { -23,-10,14,25,23,10,-14,-25 };
const int MOVS_PEOB[] = { -24,-12 };
const int MOVS_PEOB_CAPT[] = { -11,-13 };
const int MOVS_PEON[] = { 24,12 };
const int MOVS_PEON_CAPT[] = { 11,13 };
const int MOVS_REI[] = { -11,1,13,12,11,-1,-13,-12 };
const int MOVS_DAMA[] = { 1,12,-1,-12,-11,13,11,-13 };

class Caceres
{
public:
	int numPsJugades;

	Caceres();
	virtual ~Caceres();
	void entradaJugades();
	int generaNoCapt(Posicio posTreball);

private:
	Posicio mainPos;

};

