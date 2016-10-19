// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

#include "Grafo.h"


int possuiCicloNegativo(Grafo* grafo){
	int n_vertices = grafo->n_vertices;

	//int custo = 0;
	int vert_visit[ n_vertices];
	int i, j, k;
	int cicloNegativo;
	for( k = 0; k < n_vertices; k++)
		vert_visit[ k] = 0;

	vert_visit[ 0] = 1;
	for( i = 0; i < n_vertices; i++){
		for( j = 0; j < n_vertices; j++){
			vert_visit[ i] = 1;
			if( i != j){
				if( grafo->vertices[ i][ j] > 0){
					printf( "Achou aresta de %i para %i com custo %i\n", i+1, j+1, grafo->custo[ i][ j]);

					vert_visit[ j] = 1;
					cicloNegativo = buscaCiclo( i, j, grafo, grafo->custo[ i][ j], vert_visit);

					if( cicloNegativo)
						return NEG;
				}
			}else{
				if( grafo->vertices[ i][ j] > 0){
					printf( "Achou aresta de %i para %i com custo %i\n", i+1, j+1, grafo->custo[ i][ j]);
					if( grafo->custo[ i][ j] < 0)
						return NEG;
				}
			}

			for( k = 0; k < n_vertices; k ++)
				vert_visit[ k] = 0;
		}
	}
	return POS;
}

int buscaCiclo( int verticeDestino, int verticeOrigem, Grafo* grafo, int custoAtual, int *vert_visit_init){
	int n_vertices = grafo->n_vertices;
	int i = verticeOrigem, j = verticeDestino;
	int k;
	int cicloNegativo;
	int vert_visit[ n_vertices];

	if( grafo->vertices[ i][ j] > 0){
		printf( "Achou aresta de %i para %i com custo %i\n", i+1, j+1, grafo->custo[ i][ j]);
		printf("custo ciclo: %i\n", custoAtual + grafo->custo[ i][ j]);
		if( custoAtual + grafo->custo[ i][ j] < 0)
			return NEG;
		else
			return POS;
	}

	for( k = 0; k < n_vertices; k++)
		vert_visit[ k] = vert_visit_init[ k];

	for( j = 0; j < n_vertices; j++){
		if( (i != j) && (!vert_visit[ j])){
			if( grafo->vertices[ i][ j]){
				printf( "Achou aresta de %i para %i com custo %i\n", i+1, j+1, grafo->custo[ i][ j]);
				printf("custo ciclo: %i\n", custoAtual + grafo->custo[ i][ j]);
				vert_visit[ j] = 1;
				cicloNegativo = buscaCiclo( verticeDestino, j, grafo, custoAtual + grafo->custo[ i][ j], vert_visit);
				if( cicloNegativo)
					return NEG;
			}
		}else
			if( grafo->vertices[ i][ j]){
				printf( "Achou aresta de %i para %i mas ja passou\n", i+1, j+1);
			}
	}

	printf("Fim do caminho %i\n", i+1);
	return POS;

}

void bellmanFord(Grafo* grafo, int verticeInicial){
	if( !possuiCicloNegativo( grafo)){
		printf("Sem ciclo negativos\n");
		int n_vertices = grafo->n_vertices;

		int i, j;
		int tabela[ n_vertices][ 2];
		int vert_visit[ n_vertices];
		int leave = 1;
		i = verticeInicial;

		for( i = 0; i < n_vertices; i++){
			tabela[ i][ 0] = NULO;
			tabela[ i][ 1] = INFINITO;
		}
		tabela[ verticeInicial][ 0] = verticeInicial;
		tabela[ verticeInicial][ 1] = 0;

		for( j = 0; j < n_vertices; j++){
			if(( grafo->vertices[ i][ j] > 0) && ( j != verticeInicial)){
				vert_visit[ j] = 1;
				tabela[ j][ 0] = verticeInicial;
				tabela[ j][ 1] = grafo->custo[ i][ j];
			}
		}
		do{
			for( i = 0; i < n_vertices; i ++){
				if( ( tabela[ i][ 0] != NULO) && ( i != verticeInicial)){
					for( j = 0; j < n_vertices; j++){
						if( ( i != j) && ( grafo->n_vertices[ i][ j]))
					}
				}
			}
		}while( !leave);
	}else{
		printf("Possui ciclos negativos, não é possivel usar o Bellman-Ford\n");
	}
}