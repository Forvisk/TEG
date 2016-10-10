// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

#include "Grafo.h"

#define INFINITO 1
#define NULO -1

int possuiCicloNegativo(Grafo* grafo){
	int n_vertices = grafo->n_vertices;
	int i, j;
	int cicloNegatico;
	//int custoCiclo = 0;
	//int ok = 1;
	printf("1\n");
	for( i = 0; i < n_vertices; i++){
		printf("2\n");
		for( j = 0; j < n_vertices; j++){
			printf("3\n");
			if( i != j){
				if( grafo->vertices[ i][ j] > 0){
					printf("achou aresta %i para %i\n", i+1, j+1);
					printf("%i\n", grafo->custo[ i][ j]);
					cicloNegatico = buscaCiclo( i, j, 0, grafo, grafo->custo[ i][ j]);
					if( cicloNegatico == NEG){
						return NEG;
					}
				}
			}
		}
	}
	return POS;
}

int buscaCiclo( int verticeDestino, int verticeOrigem, int anteriorOrigem, Grafo* grafo, int custoAtual){
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
				printf("achou aresta %i para %i // %i\n", i+1, j+1, verticeOrigem+1);
				printf("%i\n", custoAtual + grafo->custo[ i][ j]);
				if( anteriorOrigem > 0){
					int cicloNegatico = buscaCiclo( verticeDestino, j, grafo, custoAtual + grafo->custo[ i][ j]);
					if( cicloNegatico == NEG){
						return NEG;
					}
				}
			}
		}
	}
	printf("Fim de linha %i\n", i+1);
	return POS;
}

void bellmanFord(Grafo* grafo, int verticeInicial){
	if( !possuiCicloNegativo(grafo)){
		/*if( verticeInicial > 0){
			int n_vertices = grafo->n_vertices;

			int tabela[ n_vertices][ 3];
			//int short vert_Visit[ n_vertices];
			int i = 0, j = 0;

			for( i = 0; i < n_vertices; i++){
				tabela[ i][ 0] = NULO;
				tabela[ i][ 1] = 0;
				tabela[ i][ 2] = INFINITO;
				printf(".\n");
				//vert_Visit[ i] = 0;
			}

			tabela[ verticeInicial][ 0] = verticeInicial;
			tabela[ verticeInicial][ 1] = 0;
			tabela[ verticeInicial][ 2] = 0;

			for( i = 0; i < n_vertices - 1; i++){
				//if( vert_Visit[ i]){
					for( j = 0; j < n_vertices; j++){
						if( grafo->vertices[ i][ j] > 0){
							if(tabela[ j][ 0] == NULO){
								tabela[ j][ 0] = i;
								tabela[ j][ 1] = grafo->custo[ i][ j];
								//tabela[ j][ 2] = 0;
							}else if( tabela[ i][ 1] + grafo->custo[ i][ j] < tabela[ j][ 1]){
								tabela[ j][ 0] = i;
								tabela[ j][ 1] = tabela[ i][ 1] + grafo->custo[ i][ j];
							}
							//vert_Visit[ j] = 1;
							printf("3 %i %i\n", i, j);
						}
						printf("2\n");
					}
					printf("1\n");
				//}
			}
			printf( "\nVertice:  ");
			for( i = 0; i < n_vertices; i++){
				printf( " %3i ", i + 1);
			}
			printf( "\nCusto:    ");
			for( i = 0; i < n_vertices; i++){
				if( tabela[ i][ 1] != NULO)
					printf(" %3i ", tabela[ i][ 1]);
				else
					printf(" NUL ");
			}
			printf( "\nAnterior: ");
			for( i = 0; i < n_vertices; i++){
				if( tabela[ i][ 0] != NULO)
					printf( " %3i ", tabela[ i][ 0] + 1);
				else
					printf(" NUL ");
			}
			printf( "\n");
		}*/
	}else{
		printf("Possiu ciclos negativos, não é possivel usar Bellman-Ford\n");
	}
}