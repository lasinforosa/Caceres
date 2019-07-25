// Caceres.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "string.h"
#include "caceres.h"
#include "jugada.h"
#include "posicio.h"

using namespace std;


Caceres::Caceres()
{

	numPsJugades = 0;
	// mainPos = new  Posicio();
	mainPos.posicioInicial();
	mainPos.imprimeixEscaquer();
	entradaJugades();
}

Caceres::~Caceres()
{
	//dtor
}

void Caceres::entradaJugades() {
	string s;
	int orig, desti;
	int vabe = 0;
	bool bucle = true;
	Jugada jugada;

	printf("\n");
	printf("p: mostra l'escaquer\n");
	printf("x: surt\n");
	printf("Introdueix la teva jugada e2e4 o g1f3 o h7h8D\n");
	printf("ENTRADA DE JUGADES\n");


	while (bucle==true) {

		/* de FirstChess i/o TSCP */
		printf("tu: ");

		vabe = scanf("%s", s);

		if (vabe == EOF)   /*  acaba el programa */
			break;
		
		if (s.compare("p")) {
			mainPos.imprimeixEscaquer();
			continue;
		}

		if (s.compare("x")) {
			printf("a reveure!\n");
			bucle = false;
			continue;
		}

		/* TSCP */
		if (s[0] < 'a' || s[0]> 'h' ||
			s[1] < '0' || s[1]> '9' ||
			s[2] < 'a' || s[2]> 'h' ||
			s[3] < '0' || s[3]> '9')
		{
			printf("Jugada il·legal\n");
			continue;

		}

		/* FirstChess i TSCP */
		orig = s[0] - 'a';
		orig += 8 * (8 - (s[1] - '0'));
		desti = s[2] - 'a';
		desti += 8 * (8 - (s[3] - '0'));

		printf("\n");
		printf("La teva jugada es: %c%c%c%c ", s[0], s[1], s[2], s[3]);
		printf("o %d-%d\n", orig, desti);

		jugada.setInicial(orig);
		jugada.setFinal(desti);
		jugada.setCorOCapt(0);

		/* genera pseudoJugades */
		// numPseudoJugades = generaJugada(&posPPAL, &pseudoJUG[0]);
		mainPos.updatePos(jugada);
		// System.out.printf("Nombre de pseudo jugades = %d \n",numPseudoJugades);
		mainPos.imprimeixEscaquer();

	} /* del for */
}

int Caceres::generaNoCapt(Posicio posTreball) {
	int origen, desti;
	int i;
	int compta;
	int numJugades = 0;

	for (i = 0; i < 16; i++) {
		origen = posTreball.getPecesNegres(i);

		switch (i) {

		case 0:		/* REI */
			for (int j = 0; j < 8; j++) {

				desti = origen + MOVS_REI[j];
				if (desti < 26 || desti>117 || posTreball.getCassella(desti) == 99 || posTreball.getCassella(desti) != 0) {
				}
				else {

					// anota jugada
					numJugades++;
					printf("%3d-%3d\n", origen, desti);
				}

			}
			break;

		case 1:		/* DAMA */
			for (int j = 0; j < MOVS_DAMA.length; j++) {
				compta = 1;
				do {
					desti = origen + compta * MOVS_DAMA[j];
					if (desti < 26 || desti>117 || posTreball.getCassella(desti) == 99 || posTreball.getCassella(desti) != 0) {
						compta = 100;
					}
					else {

						// anota jugada
						numJugades++;
						printf("%3d-%3d\n", origen, desti);
					}
					compta++;
				} while (compta <= MAX_DESPL);

			}
			break;

		case 2:		/* TORRE */
		case 3:
			for (int j = 0; j < MOVS_TORRE.length; j++) {
				compta = 1;
				do {
					desti = origen + compta * MOVS_TORRE[j];
					if (desti < 26 || desti>117 || posTreball.getCassella(desti) == 99 || posTreball.getCassella(desti) != 0) {
						compta = 100;
					}
					else {

						// anota jugada
						numJugades++;
						printf("%3d-%3d\n", origen, desti);
					}
					compta++;
				} while (compta <= MAX_DESPL);

			}
			break;

		case 4:
		case 5:
			for (int j = 0; j < MOVS_ALFIL.length; j++) {
				compta = 1;
				do {
					desti = origen + compta * MOVS_ALFIL[j];
					if (desti < 26 || desti>117 || posTreball.getCassella(desti) == 99 || posTreball.getCassella(desti) != 0) {
						compta = 100;
					}
					else {

						// anota jugada
						numJugades++;
						printf("%3d-%3d\n", origen, desti);
					}
					compta++;
				} while (compta <= MAX_DESPL);

			}
			break;

		case 6:		/* CAVALL */
		case 7:
			for (int j = 0; j < MOVS_CAVALL.length; j++) {

				desti = origen + MOVS_CAVALL[j];
				if (desti < 26 || desti>117 || posTreball.getCassella(desti) == 99 || posTreball.getCassella(desti) != 0) {
				}
				else {

					// anota jugada
					numJugades++;
					printf("%3d-%3d\n", origen, desti);
				}

			}
			break;

		default: /* PEO */
			for (int j = 0; j < MOVS_PEON.length; j++) {

				desti = origen + MOVS_PEON[j];
				if (desti < 26 || desti>117 || posTreball.getCassella(desti) == 99 || posTreball.getCassella(desti) != 0) {
				}
				else {

					// anota jugada
					numJugades++;
					printf("%3d-%3d\n", origen, desti);
				}

			}
			break;

		} // switch
	} // for

	return numJugades;
}



int main()
{
	Caceres roda;
	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
