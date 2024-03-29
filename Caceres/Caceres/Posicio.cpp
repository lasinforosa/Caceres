
#include <stdio.h>
#include "caceres.h"
#include "posicio.h"
#include "valor.h"


using namespace std;


Posicio::Posicio()
{
	// escaquer = new int[144];
	// pecesBlanques = new int[16];
	// pecesNegres = new int[16];
	// colorCasselles = new int[144];
	// valorPos = new Valor;
	enrocs = 0;
	alPas = 0;
	ply = 0;
	quiMou = BLANC;
	hashPos = 0.0;
}

Posicio::~Posicio()
{
	//dtor
}

void Posicio::setPosicio(int board[], int blancas[], int negras[], int colores[], int enroques,
	int alPaso, int halfmov, int mou, double hash, Valor elValor)
{
	for (int i = 0; i < 144; i++) {
		escaquer[i] = board[i];
		colorCasselles[i] = colores[i];
		if (i < 16) {
			pecesBlanques[i] = blancas[i];
			pecesNegres[i] = negras[i];
		}
	}

	enrocs = enroques;
	alPas = alPaso;
	ply = halfmov;
	quiMou = mou;
	hashPos = hash;
	valorPos.setValorVal(elValor.getValorVal());
	valorPos.setValorSegur(elValor.getValorSegur());
}


int Posicio::getCassella(int desti)
{
	return escaquer[desti];
}

int Posicio::getQuiMou() {
	return quiMou;
}

int Posicio::getPecesBlanques(int i) {
	return pecesBlanques[i];
}

int Posicio::getPecesNegres(int i) {
	return pecesNegres[i];
}

void Posicio::posicioInicial() {

	pecesBlanques[0] = 61;        pecesBlanques[1] = 60;    pecesBlanques[2] = 57;
	pecesBlanques[3] = 64;        pecesBlanques[4] = 59;    pecesBlanques[5] = 62;
	pecesBlanques[6] = 58;        pecesBlanques[7] = 63;    pecesBlanques[8] = 49;
	pecesBlanques[9] = 50;        pecesBlanques[10] = 51;   pecesBlanques[11] = 52;
	pecesBlanques[12] = 53;       pecesBlanques[13] = 54;   pecesBlanques[14] = 55;
	pecesBlanques[15] = 56;
	pecesNegres[0] = 5;           pecesNegres[1] = 4;       pecesNegres[2] = 1;
	pecesNegres[3] = 8;           pecesNegres[4] = 3;       pecesNegres[2] = 6;
	pecesNegres[6] = 2;           pecesNegres[7] = 7;       pecesNegres[2] = 9;
	pecesNegres[9] = 10;          pecesNegres[10] = 11;     pecesNegres[2] = 12;
	pecesNegres[12] = 13;         pecesNegres[13] = 14;     pecesNegres[2] = 15;
	pecesNegres[15] = 16;

	colorCasselles[0] = NEGRE;    colorCasselles[1] = NEGRE;
	colorCasselles[2] = NEGRE;    colorCasselles[3] = NEGRE;
	colorCasselles[4] = NEGRE;    colorCasselles[5] = NEGRE;
	colorCasselles[6] = NEGRE;    colorCasselles[7] = NEGRE;
	colorCasselles[8] = NEGRE;    colorCasselles[9] = NEGRE;
	colorCasselles[10] = NEGRE;    colorCasselles[11] = NEGRE;
	colorCasselles[12] = BUIT;     colorCasselles[13] = BUIT;
	colorCasselles[14] = BUIT;     colorCasselles[15] = BUIT;
	colorCasselles[16] = BUIT;     colorCasselles[17] = BUIT;
	colorCasselles[18] = BUIT;     colorCasselles[19] = BUIT;
	colorCasselles[20] = BUIT;     colorCasselles[21] = BUIT;
	colorCasselles[22] = BUIT;     colorCasselles[23] = BUIT;
	colorCasselles[24] = BUIT;     colorCasselles[25] = BUIT;
	colorCasselles[26] = BUIT;     colorCasselles[27] = BUIT;
	colorCasselles[28] = BUIT;     colorCasselles[29] = BUIT;
	colorCasselles[30] = BUIT;     colorCasselles[31] = BUIT;
	colorCasselles[32] = BUIT;     colorCasselles[33] = BUIT;
	colorCasselles[34] = BUIT;     colorCasselles[35] = BUIT;
	colorCasselles[36] = BUIT;     colorCasselles[37] = BUIT;
	colorCasselles[38] = BUIT;     colorCasselles[39] = BUIT;
	colorCasselles[40] = BUIT;     colorCasselles[41] = BUIT;
	colorCasselles[42] = BUIT;     colorCasselles[43] = BUIT;
	colorCasselles[44] = BUIT;     colorCasselles[45] = BUIT;
	colorCasselles[46] = BUIT;     colorCasselles[47] = BUIT;
	colorCasselles[48] = BLANC;    colorCasselles[49] = BLANC;
	colorCasselles[50] = BLANC;    colorCasselles[51] = BLANC;
	colorCasselles[52] = BLANC;    colorCasselles[53] = BLANC;
	colorCasselles[54] = BLANC;    colorCasselles[55] = BLANC;
	colorCasselles[56] = BLANC;    colorCasselles[57] = BLANC;
	colorCasselles[58] = BLANC;    colorCasselles[59] = BLANC;
	colorCasselles[60] = BLANC;    colorCasselles[61] = BLANC;
	colorCasselles[62] = BLANC;    colorCasselles[63] = BLANC;

	// situem la posicio inicial
	for (int i = 16; i < 48; i++) {
		escaquer[0] = BUIT;
	}

	escaquer[0] = -TORRE;             escaquer[1] = -CAVALL;
	escaquer[2] = -ALFIL;             escaquer[3] = -DAMA;
	escaquer[4] = -REI;               escaquer[5] = -ALFIL;
	escaquer[6] = -CAVALL;            escaquer[7] = -TORRE;
	escaquer[8] = -PEO;               escaquer[9] = -PEO;
	escaquer[10] = -PEO;              escaquer[11] = -PEO;
	escaquer[12] = -PEO;              escaquer[13] = -PEO;
	escaquer[14] = -PEO;              escaquer[15] = -PEO;
	escaquer[48] = PEO;               escaquer[49] = PEO;
	escaquer[50] = PEO;               escaquer[51] = PEO;
	escaquer[52] = PEO;               escaquer[53] = PEO;
	escaquer[54] = PEO;               escaquer[55] = PEO;
	escaquer[56] = TORRE;             escaquer[57] = CAVALL;
	escaquer[58] = ALFIL;             escaquer[59] = DAMA;
	escaquer[60] = REI;               escaquer[61] = ALFIL;
	escaquer[62] = CAVALL;            escaquer[63] = TORRE;

	enrocs = 11;              // 1 + 2 + 3 + 5
	alPas = 0;
	ply = 1;
	quiMou = BLANC;
	hashPos = 0;
	valorPos.setValorVal(10);            // valorant tenir la sortida
	valorPos.setValorSegur(100);         // a ull

}


void Posicio::updatePos(Jugada jug) {
	escaquer[jug.getFinal()] = escaquer[jug.getInicial()];
	escaquer[jug.getInicial()] = BUIT;
	ply++;
	quiMou = quiMou * NEGRE;
	/*
	   enrocs, alPas, hashPos i valorPos  -> PENDENT
	*/

	/* actualitzem els registres de Posicio */
	if (quiMou == BLANC) {
		if (colorCasselles[jug.getFinal()] == NEGRE) {
			pecesNegres[escaquer[jug.getFinal()]] = BUIT;
			colorCasselles[jug.getFinal()] = BUIT;
		}
		pecesBlanques[escaquer[jug.getInicial()]] = jug.getFinal();
	}
	else {
		if (colorCasselles[jug.getFinal()] == BLANC) {
			pecesBlanques[escaquer[jug.getFinal()]] = BUIT;
			colorCasselles[jug.getFinal()] = BUIT;
		}
		pecesNegres[escaquer[jug.getInicial()]] = jug.getFinal();
	}
	/* canvia el torn de joc */
	quiMou = quiMou * NEGRE;

}

void Posicio::imprimeixEscaquer()
{
	int i;
	int compta = 0;
	char nomPeces[] = { 'K','Q','R','B','N','P','k','q','r','b','n','p' };

	printf("   +---+---+---+---+---+---+---+---+\n");
	printf("   +");

	for (i = 0; i < 64; i++) {

		switch (escaquer[i]) {

		case REI:
			printf(" %c +", nomPeces[0]);
			break;
		case -REI:
			printf(" %c +", nomPeces[6]);
			break;
		case DAMA:
			printf(" %c +", nomPeces[1]);
			break;
		case -DAMA:
			printf(" %c +", nomPeces[7]);
			break;
		case TORRE:
			printf(" %c +", nomPeces[2]);
			break;
		case -TORRE:
			printf(" %c +", nomPeces[8]);
			break;
		case ALFIL:
			printf(" %c +", nomPeces[3]);
			break;
		case -ALFIL:
			printf(" %c +", nomPeces[9]);
			break;
		case CAVALL:
			printf(" %c +", nomPeces[4]);
			break;
		case -CAVALL:
			printf(" %c +", nomPeces[10]);
			break;
		case PEO:
			printf(" %c +", nomPeces[5]);
			break;
		case -PEO:
			printf(" %c +", nomPeces[11]);
			break;

		default:
			printf("   +");
			break;
		}

		if ((i & 7) == 7) {
			compta++;
			printf(" %d", 9 - compta);
			printf("\n");
			printf("   +---+---+---+---+---+---+---+---+\n");
			printf("   +");
		}
	}

	printf(" a   b   c   d   e   f   g   h   \n");
}
