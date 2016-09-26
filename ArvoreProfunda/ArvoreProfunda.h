// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

#include "CGrafos.h"

#ifndef __ArvoreProfunda__
#define __ArvoreProfunda__

#define MARCA 1
#define SEMMARCA 0

typedef struct {
	struct Vertice *inicio;
	int n_vertices;
} Arvore;

typedef struct {
	int nome;
	struct Filhos *filho;
} Vertice;

typedef struct {
	//struct Arestas *aresta;
	struct Vertice *vertice;
	struct Filhos *proximo;
} Filhos;

/*typedef struct {
	struct Vertice *filho;
	struct Vertice *pai;
	int peso;
} Arestas;*/

Arvore* criarArvore(Grafo* grafo, int verticeInit);

void putsArvor(Arvore* arvore);

#endif