// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr


#include "Grafo.h"

#define INFINITO -1;
#define NULO -1;

void dijkstra( Grafo* grafo, int verticeInicial){
	if( seConectado( grafo)){
		int n_vertices = grafo->n_vertices;
		int tabela[ n_vertices][ 2];
		short int vert_visit[ n_vertices];
		int i = 0, j = 0;
		int leave = 1;

		for( i = 0; i < n_vertices; i++){
			tabela[ i][ 0] = NULO;
			tabela[ i][ 1] = INFINITO;
			vert_visit[ i] = 0;
		}

		tabela[ verticeInicial][ 0] = verticeInicial;
		tabela[ verticeInicial][ 1] = 0;
		vert_visit[ verticeInicial] = 1;

		do{
			leave = 0;
			//Essa primeira forma parece não seguir os passos da apostila
			for( i = 0; i < n_vertices; i++){
				if( vert_visit[ i] == 1){
					for( j = 0; j < n_vertices; j++){
						if( ( grafo->vertices[ i][ j] > 0) && ( i != j)){
							if( tabela[ j][ 0] == NULO){
								tabela[ j][ 0] = i;
								tabela[ j][ 1] = tabela[ i][ 1] + grafo->custo[ i][ j];

								vert_visit[ j] = 1;
							}else if( tabela[ j][ 1] >  tabela[ i][ 1] + grafo->custo[ i][ j]){
								tabela[ j][ 0] = i;
								tabela[ j][ 1] = tabela[ i][ 1] + grafo->custo[ i][ j];

								vert_visit[ j] = 1;
							}
						}
					}
					leave = 0;
					vert_visit[ i] = 2;
				}
			}

		}while( !leave);
	}else{
		printf( "Grafo não conectado!\n");
	}

}
