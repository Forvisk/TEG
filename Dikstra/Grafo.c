// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

#include <stdlib.h>
#include <stdio.h>
#include "Grafo.h"

Grafo* criaGrafo( int n_vertices){
	Grafo* novo;
	novo = ( Grafo*)malloc( sizeof( Grafo));
	novo->n_vertices = n_vertices;
	novo->n_arestas = 0;

	novo->vertices = ( int**)malloc( sizeof( int*) * n_vertices);
	novo->custo =  ( int**)malloc( sizeof( int*) * n_vertices);
	int i, j;
	for( i = 0; i < n_vertices; i++){
		novo->vertices[ i] = ( int*)malloc( sizeof( int) * n_vertices);
		novo->custo[ i] = ( int*)malloc( sizeof( int) * n_vertices);
		for( j = 0; j < n_vertices; j++){
			novo->vertices[ i][ j] = 0;
			novo->custo[ i][ j] = 0;
		}
	}

	return novo;
}

void addVertice( Grafo* grafo){
	int i, j;
	int n_vertices = grafo->n_vertices + 1;
	int **vertices;
	int **custo;

	vertices = (int**)malloc(sizeof(int*) * n_vertices);
	custo =  (int**)malloc(sizeof(int*) * n_vertices);
	for( i = 0; i < n_vertices; i++){
		vertices[i] = ( int*)malloc( sizeof( int) * n_vertices);
		custo[i] = ( int*)malloc( sizeof( int) * n_vertices);
		for( j = 0; j < n_vertices; j++){
			if(( i != n_vertices - 1) && (j != n_vertices)){
				vertices[i][j] = grafo->vertices[i][j];
				custo[i][j] = grafo->custo[i][j];
			}else{
				vertices[i][j] = 0;
				custo[i][j] = 0;
			}
		}
	}
	grafo->n_vertices = n_vertices;
	grafo->vertices = vertices;
	grafo->custo = custo;
}

void addAresta( int origem, int destino, int custo, Grafo* grafo){
	grafo->vertices[ origem][ destino]++;
	grafo->custo[ origem][ destino] = custo;
	grafo->n_arestas--;
}

/*void removeVertice(int vertice, Grafo* grafo){
	if(vertice < grafo->n_vertices){
		int i, j;
		int tam_novo = grafo->n_vertices - 1;
		int **novo_vertices, **novo_custo;
		novo_vertices = ( int**)malloc( sizeof( int*) * tam_novo);
		novo_custo = ( int**)malloc( sizeof( int*) * tam_novo);
		for( i = 0; i < grafo->n_vertices; i++){
			novo_vertices[i] = ( int*)malloc( sizeof( int) * tam_novo);
			novo_custo[i] = ( int*)malloc( sizeof( int) * tam_novo);
			for(j = 0; j < grafo->n_vertices; j++){
				
			}
		}
	}else{
		printf("Vertice não existente!");
	}
}
*/
//void removeAresta(int origem, int destino, Grafo* grafo);

Grafo* leituraGrafoDirecionado(){
	char arquivo[50];
	char nameAresta;
	int n_vertices, n_arestas;
	int origem, destino, custo;

	int i;

	Grafo* grafo;

	FILE *fp;
	printf( "Nome do arquivo:\n");
	scanf( "%s", arquivo);
	fp = fopen( arquivo, "r");
	if( fp == NULL){
		printf( "Arquivo não existente!\n");
		return NULL;
	}

	fscanf( fp, "%i%i", &n_vertices, &n_arestas);
	grafo = criaGrafo( n_vertices);
	for( i = 0; i < n_arestas; i++){
		fscanf( fp, "%c: %i, %i = %i", &nameAresta, &origem, &destino, &custo);
		addAresta( origem, destino, custo, grafo);
		addAresta( destino, origem, custo, grafo);
		grafo->n_arestas--;
	}
	return grafo;
}

Grafo* leituraGrafo(){
	char arquivo[50];
	char nameAresta;
	int n_vertices, n_arestas;
	int origem, destino, custo;

	int i;

	Grafo* grafo;

	FILE *fp;
	printf( "Nome do arquivo:\n");
	scanf( "%s", arquivo);
	fp = fopen( arquivo, "r");
	if( fp == NULL){
		printf( "Arquivo não existente!\n");
		return NULL;
	}
	printf("Arquivo encontrado\n");
	fscanf( fp, "%i %i\n", &n_vertices, &n_arestas);
	printf("Vertices: %i;\nArestas: %i.\n", n_vertices, n_arestas);
	grafo = criaGrafo( n_vertices);
	for( i = 0; i < n_arestas; i++){
		fscanf( fp, "%c: %i, %i = %i;\n", &nameAresta, &origem, &destino, &custo);
		printf("%c %i, %i = %i;\n", nameAresta, origem, destino, custo);
		addAresta( origem-1, destino-1, custo, grafo);
	}
	return grafo;
}

void putsGrafo(Grafo* grafo){
	int i, j;
	printf( "Grafo: %p;\nVertices: %i;\n", ( void*)grafo, grafo->n_vertices);
	printf("    ");
	for( j = 0; j < grafo->n_vertices; j++)
		printf(" %3i ", j);
	printf("\n\n");
	for( i = 0; i < grafo->n_vertices; i++){
		printf("%2i  ", i+1);
		for (int j = 0; j < grafo->n_vertices; j++){
			printf(" %3i ", grafo->vertices[i][j]);
		}
		printf("\n    ");
		for (int j = 0; j < grafo->n_vertices; j++){
			printf(" %3i ", grafo->custo[i][j]);
		}
		printf("\n\n");
	}
}
