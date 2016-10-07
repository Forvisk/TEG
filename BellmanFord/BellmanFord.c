// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

#include "Grafo.h"

int possuiCicloNegativo(Grafo* grafo){
	int n_vertices = grafo->n_vertices;
	int i, j;
	//int custoCiclo = 0;
	//int ok = 1;
	for( i = 0; i < n_vertices; i++){
		for( j = 0; j < n_vertices; j++){
			if( i != j){
				if( grafo->vertices[ i][ j] > 0){
					printf("achou aresta %i para %i\n", i+1, j+1);
					printf("%i\n", grafo->custo[ i][ j]);
					int cicloNegatico = buscaCiclo( i, j, grafo, grafo->custo[ i][ j]);
					if( cicloNegatico == NEG){
						return NEG;
					}
				}
			}
		}
	}
	return POS;
}

int buscaCiclo( int verticeDestino, int verticeOrigem, Grafo* grafo, int custoAtual){
	int n_vertices = grafo->n_vertices;
	int i = verticeOrigem;
	int j = verticeDestino;
	if( grafo->vertices[ i][ j] > 0){
		printf("achou aresta %i para %i\n", i+1, j+1);
		printf("%i\n", custoAtual + grafo->custo[ i][ j]);
		if( custoAtual + grafo->custo[ i][ j] < 0){
			return NEG;
		}else{
			printf("Ciclo positivo\n");
			return POS;
		}
	}
	for( j = 0; j < n_vertices; j++){
		if( i != j){
			if(grafo->vertices[ i][ j] > 0){
					printf("achou aresta %i para %i\n", i+1, j+1);
					printf("%i\n", custoAtual + grafo->custo[ i][ j]);
					int cicloNegatico = buscaCiclo( verticeDestino, j, grafo, custoAtual + grafo->custo[ i][ j]);
				if( cicloNegatico == NEG){
					return NEG;
				}
			}
		}
	}
	printf("Fim de linha %i\n", i+1);
	return POS;
}