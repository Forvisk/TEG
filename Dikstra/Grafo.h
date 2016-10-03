// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr
#ifndef __Grafo__
#define __Grafo__

typedef struct{
	int n_vertices;
	int n_arestas;
	int **vertices;
	int **custo;
} Grafo;

Grafo* criaGrafo(int n_vertices);

void addVertice(Grafo* grafo);
void addAresta(int origem, int destino, int custo, Grafo* grafo);

void removeVertice(int vertice, Grafo* grafo);
void removeAresta(int origem, int destino, Grafo* grafo);

Grafo* leituraGrafo();
Grafo* leituraGrafoDirecioado();

void putsGrafo();

#endif