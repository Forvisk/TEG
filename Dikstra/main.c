// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

/*
	gcc -Wall Grafo.h Grafo.c GrafoTools.c main.c -o dikstra
*/

#include <stdio.h>
#include "Grafo.h"

int main(){
	Grafo* grafo = leituraGrafo();
	if( grafo != NULL){
		putsGrafo(grafo);
		removeAresta(1, 2, grafo);
		putsGrafo(grafo);
		removeVertice(4, grafo);
		putsGrafo(grafo);
	}

	return 0;
}