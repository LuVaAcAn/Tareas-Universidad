#include "pch.h"
#include "Dijkstra.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace System;

void dibujaDijsktra() {
	cout << endl << endl << endl;
	cout << "	 ---------------------------Algoritmo de Dijsktra---------------------------" << endl;
	cout << "	|                                                                           |" << endl;
	cout << "	|  $$$$$$$    $$$$$$   $$$$$$   $$$$$$   $$   $$ $$$$$$$$ $$$$$$$   $$$$$$  |" << endl;
	cout << "	|  $$    $$     $$         $$  $$    $$  $$  $$     $$    $$    $$ $$    $$ |" << endl;
	cout << "	|  $$    $$     $$         $$  $$        $$ $$      $$    $$   $$  $$    $$ |" << endl;
	cout << "	|  $$    $$     $$         $$   $$$$$$   $$$$       $$    $$$$$    $$$$$$$$ |" << endl;
	cout << "	|  $$    $$     $$         $$        $$  $$ $$      $$    $$  $$   $$    $$ |" << endl;
	cout << "	|  $$    $$     $$    $$   $$  $$    $$  $$  $$     $$    $$    $$ $$    $$ |" << endl;
	cout << "	|  $$$$$$$    $$$$$$   $$$$$$   $$$$$$   $$   $$    $$    $$    $$ $$    $$ |" << endl;
	cout << "	|                                                                           |" << endl;
	cout << "	 --------------------------------------------------------------------------- " << endl;
	cout << endl << endl << endl;
}

void Creditos() {
	cout << endl << endl << endl;
	cout << "	 ---------------------------Algoritmo de Dijsktra---------------------------" << endl;
	cout << "	|                                                                           |" << endl;
	cout << "	|                                                                           |" << endl;
	cout << "	|             U202113624 -- Achin Angeles, Luciano Valentino                |" << endl;
	cout << "	|             U202119197 -- Amarillo Alejos, Nicolle Francesca              |" << endl;
	cout << "	|             U202113280 -- Pingus Rodriguez, Carlos Daniel                 |" << endl;
	cout << "	|             U20211A620 -- Velarde Luyo, Piero Alberto                     |" << endl;
	cout << "	|             U202124051 -- Valverde Cora, Piero Salvador                   |" << endl;
	cout << "	|                                                                           |" << endl;
	cout << "	|                                                                           |" << endl;
	cout << "	 --------------------------------------------------------------------------- " << endl;
	cout << endl << endl << endl;  
}

int main() {

	srand(time(NULL));

	Dijkstra* obj_dijkstra = new Dijkstra();
	int primeraopcion;
	int opcion_menu;
	int num_aleartorio;

	system("color 2");

	do {  // para la primera parte de los creditos
		system("cls");
		dibujaDijsktra();
		cout << " ----- Ingrese una opcion ----------" << endl;
		cout << "[1] Mostrar creditos" << endl;
		cout << "[2] Iniciar Programa" << endl;
		cin >> primeraopcion;
	} while (primeraopcion <= 0 || primeraopcion > 2);

	switch (primeraopcion)
	{

	case 1: // en el caso 1 muestra los creditos.
		system("cls");
		Creditos();
		do {
			cout << endl << "Ingrese 3 para salir >>>";
			cin >> primeraopcion;
		} while (primeraopcion < 2 || primeraopcion > 4);

		if (primeraopcion == 3) {
			break;
		}
		
	case 2: // En el segundo caso defrente hace el Break
		if (primeraopcion == 2) {
			break;
		}
	default:
		break;
	}
	//luego de esto continua normal el Programa


	while (vert_num < 5 || vert_num > 15) {
		system("cls"); // limpia la pantalla
		dibujaDijsktra(); // Dibuja la palabra Dijkstra bomnito
		cout <<"			      == Programa Algoritmo de Dijkstra ==				" << endl;
		cout << "\nIngrese la cantidad de vertices [5 - 15]:  "; cin >> vert_num;
	}

	system("cls");

	while (opcion_menu != 1 && opcion_menu != 2) {
		dibujaDijsktra();
		cout << "= Menu =\n";
		cout << "[1] Ingresar los valores manualmente" << endl;
		cout << "[2] Ingresar los valores automaticamente" << endl;
		cout << "[=>] "; cin >> opcion_menu;
		cout << "\n\n";

		switch (opcion_menu) {
		case 1:

			cout << "= Ingrese los valores =\n";

			for (int i = 0; i < vert_num; i++) {
				for (int j = 0; j < vert_num; j++) {
					cin >> matr_graf[i][j];
				}
			}
			break;

		case 2:

			for (int i = 0; i < vert_num; i++) {
				for (int j = 0; j < vert_num; j++) {

					matr_graf[i][j] = 1 + rand() % (40 + 1 - 1);
					int aux = rand() & 2 + 1;
					if (aux % 2) {
						matr_graf[i][j] == num_aleartorio;
					}
					else {
						matr_graf[i][j] = inf;
					}
				}
			}
			break;
		}
		do{
			cout << "Ingrese el vertice de origen [0 al " << vert_num - 1 << "] : ";
			cin >> vert_ini;
		} while (vert_ini < 0 || vert_ini > (vert_num - 1)); // valida que ingrese un valor dentro de el arreglo
		
	}


	obj_dijkstra->inicioDijkstra();
	obj_dijkstra->algoritmoDijkstra();
	obj_dijkstra->mostrarDijkstra();

	_getch();
	return 0;
}