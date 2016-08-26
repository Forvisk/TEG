#include <stdio.h>
#include <stdlib.h>
#include "CGrafoVetorAdj.h"

Vetor* criaGrafo(int nV, int nA){
	int i;
	Vetor* vetor = (Vetor*)malloc(sizeof(Vetor));

	vetor->n_vertices = nV;
	vetor->n_arestas = 0;
	vetor->arestas = NULL;

	vetor->vertices = (int*)malloc(sizeof(int)*nV);

	for(i = 0; i< nV; i++){
		vetor->vertices[i] = 0;
	}
	return vetor;
}

void addAresta(Vetor* vetor, int a, int b){
	newA
}

void addArestaDirecional(Vetor* vetor, int a, int b){

}

Vetor* leituraArquivo(){
	char arquivo[50], c_aresta, direcao;
	FILE *fp;
	int i, a = 0, b = 0;
	int nV = 0, nA = 0;

	Vetor* vetor;

	/*printf("Nome do arquivo contendo o grafo: ");
	scanf("%s", arquivo);
	fp = fopen( arquivo, "r");*/
	fp = fopen( NDIRCON, "r");
	//fp = fopen( NDIRDESCON, "r");
	//fp = fopen( DIRCON, "r");
	//fp = fopen( DIRDESCON, "r");

	if(fp == NULL){
		printf("\nArquivo não existe\n");
		return NULL;
	}
	//leitura do arquivo para vertica, direcionado e arestas
	fscanf( fp, "%c\n", &direcao);
	fscanf( fp, "%i\n", &nV);
	printf("Vertices: %i", nV);
	fscanf( fp, "%i\n", &nA);
	printf("Arestas: %i\n", nA);

	vetor = criaGrafo(nV, nA);
	if(direcao == 'd'){
		vetor->isDir = 1;
	}else if(direcao == 'n'){
		vetor->isDir = 0;
	}else{
		printf("Arquivo não esta no padrão;\n");
		return NULL;
	}


	for(i = 0; (i < nA) && (feof(fp) == 0); i++) {
		fscanf( fp, "%c: %i, %i;\n", &c_aresta, &a, &b);
		printf("%c: %i, %i\n", c_aresta, a, b);
		if(vetor->isDir == 0)
			addAresta(vetor, --a, --b);
		else
			addArestaDirecional(vetor, --a, --b);
	}
	putsGrafo(vetor);
	fclose(fp);
	return vetor;
}

void putsGrafo(Vetor* vetor){

}