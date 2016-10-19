// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

//gcc -Wall ArvoreLarga.c ArvoreLarga.h CGrafos.c CGrafos.h main.c -o arvoreLargura

#include <stdlib.h>
#include <stdio.h>
#include "CGrafos.h"
#include "ArvoreLarga.h"

int main(void){
	Grafo* grafo = leituraTeclado();
	putsGrafo(grafo);
	/*Arvore* tree = testeArvore();
	putsArvore(tree);
	buscaVerticeArvore(0, tree);
	buscaVerticeArvore(3, tree);
	buscaVerticeArvore(6, tree);
	buscaVerticeArvore(9, tree);*/
	Arvore* tree = criarArvoreLargura( pedeVerticeInicial(),grafo);

	printf("\n\n");
	putsArvore(tree);
	int vertice = -1;
	do{
		vertice = pedeVerticeDesejado();
		if(( vertice >= 0) && ( vertice < grafo->vertices)){
			putsDescendentes(vertice, tree);
			putsAscendentes(vertice, tree);
		}
	}while(vertice >= 0);
	return 0;
}
