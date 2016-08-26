#ifndef __CGrafoVetorAdj__
#define __CGrafoVetorAdj__

#define NDIRCON "NotDirConexo.txt"
#define NDIRDESCON "NotDirDesconexo.txt"
#define DIRCON "DirConexo.txt"
#define DIRDESCON "DirDesconexo.txt"

typedef struct{
	int* vertices;
	int n_vertices;
	int n_arestas;
	int isDir;
	struct Arestas *arestas;
} Vetor;

typedef struct{
	struct arestas *next;
	struct arestas *last;
	int vertice;
} Arestas;

Vetor* criaGrafo(int nV, int nA);
Vetor* leituraArquivo();

void addAresta(Vetor* vetor, int a, int b);
void addArestaDirecional(Vetor* vetor, int a, int b);

//Grafo* addVertice(Vetor* vetor);

void putsGrafo(Vetor* vetor);

#endif