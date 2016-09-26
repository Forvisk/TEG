// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

#include <stdlib.h>
#include <stdio.h>
#include "ArvoreProfunda.h"
#include "CGrafos.h"

Arvore* criarArvore(Grafo* grafo, int verticeInicial){

	int marcacao[2][grafo->vertices];
	int i;
	for(i = 0; i < grafo->vertices; i++){
		marcacao[0][i] = SEMMARCA;
		marcacao[1][i] = SEMMARCA;
	}
	marcacao[0][--verticeInicial] = MARCA;
	Arvore *tree = (Arvore*)malloc(sizeof(Arvore));

	Vertice *primeiro = (Vertice*)malloc(sizeof(Vertice));
	primeiro->filho = NULL;
	primeiro->nome = verticeInicial;

	tree->inicio = primeiro;
	Vertice *verticeAtual = primeiro;

	i = 0;
	do{
		if((marcacao[0][i] == MARCA) && (marcacao[1][i] != MARCA)){
			for(int j = 0; j < grafo->vertices; j++){

			}
			marcacao[1][i] = MARCA;
			i = 0;
		}
	}while(i < grafo->vertices);

	return tree;
}

void putsArvore(Arvore* arvore){

}