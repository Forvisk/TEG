// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

#include <stdlib.h>
#include <stdio.h>
#include "Grafo.h"

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
	printf( "Grafo: %p;\n\nVertices: %i;\n", ( void*)grafo, grafo->n_vertices);
	printf("    ");
	for( j = 0; j < grafo->n_vertices; j++)
		printf(" %3i ", j+1);
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