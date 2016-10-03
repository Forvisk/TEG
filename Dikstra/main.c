// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

/*
	gcc -Wall Grafo.h Grafo.c main.c -o dikstra
*/

#include <stdio.h>
#include "Grafo.h"

int main(){
	Grafo* grafo = leituraGrafo();
	if( grafo != NULL)
		putsGrafo(grafo);
	return 0;
}