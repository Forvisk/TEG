// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

#include "CGrafos.h"

#ifndef __ArvoreProfunda__
#define __ArvoreProfunda__

#define MARCA 1
#define SEMMARCA 0
#define SUCESSO 1
#define FRACASSO 0

typedef struct {
	struct Vertice *inicio;
	int n_vertices;
} Arvore;

typedef struct {
	int nome;
	struct Filhos *filho;
	struct Vertice *pai;
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
int adicionaVertice(int novoVertice, int verticePai, Arvore *tree);
Vertice* buscaVertice(int nome, Vertice *verticeAtual);

void putsArvore(Arvore* arvore);

#endif