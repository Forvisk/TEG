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

//GrafoConstrutor.c

Grafo* criaGrafo(int n_vertices);

void addVertice(Grafo* grafo);
void addAresta(int origem, int destino, int custo, Grafo* grafo);

int removeVertice(int vertice, Grafo* grafo);
int removeAresta(int origem, int destino, Grafo* grafo);

//GrafoTools.c

Grafo* leituraGrafo();
Grafo* leituraGrafoDirecioado();

void putsGrafo();

//GrafoEstado.c

int seConexo(Grafo* grafo);
int seDirecionado(Grafo* grafo);

#endif