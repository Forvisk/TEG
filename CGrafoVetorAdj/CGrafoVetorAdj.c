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
	int i = 0, pos_a = 0, pos_b = 0;

	Arestas* newAresta1 = criaAresta(b);
	Arestas* newAresta2 = criaAresta(a);

	Arestas* atual = vetor->arestas;
	Arestas* aux;

	if(vetor->arestas == NULL){ // primeira aresta do grafo

		//printf("a: %i\n", a);
		vetor->arestas = newAresta1;
		//printf("Primeira aresta\n");
	}else{
		//printf("a: %i\n", a);
		i = 0;
		while(i <= a){
			pos_a += vetor->vertices[i];
			i++;
		}
		atual = vetor->arestas;
		i = 0;
		//printf("pos a: %i\n", pos_a+1);
		while(i < pos_a-1){
			atual = atual->next;
			i++;
		}
		printf("%p\n", (void*)atual->next);
		if(atual->next != NULL){
			//printf("!= NULL\n");
			newAresta1->next = atual->next;
		}
		atual->next = newAresta1;
		//printf("apontou\n");
	}
	vetor->vertices[a]++;
	vetor->n_arestas++;

	if(a != b){
		//printf("b: %i\n", b);
		i = 0;
		while(i <= b){
			pos_b += vetor->vertices[i];
			i++;
		}
		//printf("pos b %i\n", pos_b+1);
		atual = vetor->arestas;
		i = 0;
		while(i < pos_b-1){
			atual = atual->next;
			i++;
		}
		printf("%p\n", (void*)atual->next);
		if(atual->next != NULL){
			//printf("!= NULL\n");
			newAresta2->next = atual->next;
		}
		atual->next = newAresta2;
		//printf("apontou\n");

		vetor->vertices[b]++;
		vetor->n_arestas++;

		//printf("apontou2\n");
	}
	//printf("fim\n");
	atual = vetor->arestas;
	/*do{
		printf("%i\n", atual->vertice);
		atual = atual->next;
	}while(atual->next != NULL);
	printf("%i\n", atual->vertice);*/
}

Arestas* criaAresta(int a){
	Arestas* new = (Arestas*)malloc(sizeof(Arestas));
	new->vertice = a;
	new->next = NULL;
	//printf("%i\n", new->vertice);

	return new;
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
		printf("Este programa não trabalha com grafos direcionados\n");
		fclose(fp);
		return NULL;
	}else if(direcao == 'n'){
		vetor->isDir = 0;
	}else{
		printf("Arquivo não esta no padrão;\n");
		fclose(fp);
		return NULL;
	}


	for(i = 0; (i < nA) && (feof(fp) == 0); i++) {
		fscanf( fp, "%c: %i, %i;\n", &c_aresta, &a, &b);
		printf("%c: %i, %i\n", c_aresta, a, b);
		addAresta(vetor, --a, --b);
	}
	fclose(fp);


	Arestas* atual = vetor->arestas;
	do{
		printf("%i\n", atual->vertice);
		atual = atual->next;
	}while(atual->next != NULL);

	return vetor;
}

void putsGrafo(Vetor* vetor){
	int i, j = 0, t = 0;
	Arestas* atual = vetor->arestas;

	printf("\nGrafo: %p\n\tVertices: %i\n\tArestas: %i\n", (void*)vetor,  vetor->n_vertices, vetor->n_arestas);
	if(vetor->isDir)
		printf("\tdirecionado\n");
	else
		printf("\tnão direcionado\n");

	for(i = 0; i < vetor->n_vertices; i++){
		t += vetor->vertices[i];
		printf("Vertices da aresta %i:", i+1);
		while(j < t){
			printf("\n\t\t%i;", atual->vertice+1);
			atual = atual->next;
			j++;
		}
	}
}