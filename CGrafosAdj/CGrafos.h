#ifndef __CGrafos__
#define __CGrafos__

#define NDIRLI "NotDirComp.txt"
#define NDIRNLI "NotDirIncomp.txt"

typedef struct {
	int** matriz_adj;
	int vertices;
	int arestas;
	int isDir;
} Grafo;

Grafo* criarGrafo(int n_vertices);
Grafo* leituraArquivo();

void addAresta(Grafo* grafo, int a, int b);
void addArestaDirecionado(Grafo* grafo, int a, int b);

Grafo* addVertice(Grafo* grafo, int quant);
Grafo* RemoveVertice(Grafo* grafo, int a);

Grafo* addVerticeDirecional(Grafo* grafo, int quant);
Grafo* RemoveVerticeDirecional(Grafo* grafo, int a);

void putsGrafo(Grafo* grafo);

void seLigadoDirecionado(Grafo* grafo);
void seLigado(Grafo* grafo);

void completo(Grafo* grafo);

void grauNosDirecionado(Grafo* grafo);
void grauNos(Grafo* grafo);

#endif