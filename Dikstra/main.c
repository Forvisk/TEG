// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

/*
	gcc -Wall Grafo.h GrafoConstrutor.c GrafoTools.c GrafoEstado.c main.c -o dikstra
*/

#include <stdio.h>
#include "Grafo.h"

int main(){
	Grafo* grafo = leituraGrafo();
	putsGrafo(grafo);
	seConectado(grafo);
	return 0;
}

/*Funções Grafo.h

//GrafoConstrutor.c

	Grafo* criaGrafo(int n_vertices);

	void addVertice(Grafo* grafo);
	void addAresta(int origem, int destino, int custo, Grafo* grafo);

	int removeVertice(int vertice, Grafo* grafo);
	int removeAresta(int origem, int destino, Grafo* grafo);

//GrafoTools.c
	
	Grafo* leituraGrafo();
	Grafo* leituraGrafoDirecioado();

	void putsGrafo'();

//GrafoEstado.c

	int seConectado(Grafo* grafo);
	int seDirecionado(Grafo* grafo);

*/