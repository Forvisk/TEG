// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr


#include <stdlib.h>
#include <stdio.h>

#ifndef __Grafo__
#define __Grafo__

#define NEG 1
#define POS 0

#define INFINITO 1
#define NULO -1

typedef struct{
	int n_vertices;
	int n_arestas;
	int **vertices;
	int **custo;
} Grafo;

//GrafoConstrutor.c

Grafo* criaGrafo( int n_vertices);
void addVertice( Grafo* grafo);
void addAresta( int origem, int destino, int custo, Grafo* grafo);
int removeVertice( int vertice, Grafo* grafo);
int removeAresta( int origem, int destino, Grafo* grafo);

//GrafoTools.c

Grafo* leituraTecladoGrafo();
Grafo* leituraGrafo();
Grafo* leituraGrafoDirecioado();
void putsGrafo();
int escolheVertice( Grafo* grafo);

//GrafoEstado.c

int seConectado( Grafo* grafo);
int seDirecionado( Grafo* grafo);

/*//Dijkstra.c

void dijkstra( Grafo* grafo, int verticeInicial);
*/

//BellmanFord.c

int possuiCicloNegativo(Grafo* grafo);
int buscaCiclo( int verticeDestino, int verticeOrigem, Grafo* grafo, int custoAtual, int *vert_visit_init);
void bellmanFord(Grafo* grafo, int verticeInicial);

#endif