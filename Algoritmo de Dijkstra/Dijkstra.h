	#pragma once
#include <iostream>

#define inf 999; //inf va a servirnos para la identificacion de nodos no adyacentes

int vert_num; //Numero de vertices
int vert_ini; //Vertice inicial
int vert_dist[100]; //Distancia entre vertices
int vert_padre[100]; //Vertice padre del vertice en el que estamos / Sirve para poder seguir el vertice anterior
int matr_graf[100][100]; //Matriz del grafo / Esta la usaremos para poder recoger los valores del grafo
bool vert_visitado[100] = { 0 }; //Booleano que sirve para hacer un seguimiento de los vertices visitados / En 0 porque al inicio no se visita ninguno aun

using namespace std;


class Dijkstra {

public:

	Dijkstra() {}
	~Dijkstra() {}

	void inicioDijkstra() { //Inicializacion de los valores

		for (int i = 0; i < vert_num; i++) {
			vert_padre[i] = i;
			vert_dist[i] = inf;
		}

		vert_dist[vert_ini] = 0;
	}

	int getCercano() {
		int dist_minima = inf;
		int vert_minimo = 0;

		for (int i = 0; i < vert_num; i++) {
			if (!vert_visitado[i] && vert_dist[i] < dist_minima) { 
				dist_minima = vert_dist[i];
				vert_minimo = i;
			}
		}
		return vert_minimo;
	}

	void algoritmoDijkstra() {
		for (int i = 0; i < vert_num; i++) {
			int vert_cercano = getCercano();

			vert_visitado[vert_cercano] = true;

			for (int vert_ady = 0; vert_ady < vert_num; vert_ady++) {
				if ((matr_graf[vert_cercano][vert_ady] != 999) && (vert_dist[vert_ady] > vert_dist[vert_cercano] + matr_graf[vert_cercano][vert_ady])) {
					vert_dist[vert_ady] = vert_dist[vert_cercano] + matr_graf[vert_cercano][vert_ady];
					vert_padre[vert_ady] = vert_cercano;
				}
			}
		}
	}

	void mostrarDijkstra() {

		cout << "\nNodo\t\tDistancia\t\Camino\n";

		for (int i = 0; i < vert_num; i++) {
			cout << i << "\t\t" << vert_dist[i] << "\t\t" << " ";

			cout << i << " ";
			int temp = vert_padre[i];
			bool error = false;

			while (temp != vert_ini) {
				if (temp != vert_padre[temp]) {
					cout << " <- " << temp << " ";
					temp = vert_padre[temp];
				}
				else {
					error = true;
					cout << "|| Camino No Valido en " << temp << " ||";
					temp = vert_ini;
				}
			}

			if (error == false) {
				cout << " <- " << vert_ini;
				error = true;
			}

			cout << endl;
		}

	}

};