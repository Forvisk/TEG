#include <stdlib.h>
#include <stdio.h>
#include "CGrafos.h"

Grafo* criarGrafo (int n_vertices){
	Grafo* ret = (Grafo*)malloc(sizeof(Grafo));
	
	ret->vertices = n_vertices;
	ret->isDir = 0;
	int i,j;
	ret->matriz_adj = (int**)malloc(sizeof(int*)*n_vertices);
	for (i = 0; i< ret->vertices; i++){
		ret->matriz_adj[i] = (int*)malloc(sizeof(int)*n_vertices);
		for (j = 0; j < n_vertices; j++){
			ret->matriz_adj[i][j] = 0;
		}
	}
	
	ret->arestas = 0;
	
	return ret;
}

void addAresta(Grafo* grafo, int a, int b){
	grafo->arestas ++;
	if(a != b)
		grafo->matriz_adj[a][b] += 1;
	grafo->matriz_adj[b][a] += 1;
}

void addArestaDirecionado(Grafo* grafo, int a, int b){
	grafo->isDir = 1;
	grafo->arestas ++;
	grafo->matriz_adj[a][b] += 1;
}

Grafo* addVerticeDirecional(Grafo* grafo, int quant){
	int i, j, c;
	Grafo* new = criarGrafo(grafo->vertices + quant - 1);

	new->isDir = grafo->isDir;
	if(grafo->arestas > 0){
		for(i = 0; i < grafo->vertices; i++){
			for(j = 0; j < grafo->vertices; j++){
				if(grafo->matriz_adj[i][j] > 0){
					if(i == j){
						for(c = 0; c < grafo->matriz_adj[i][j] / 2; c++){
							printf("aresta %i %i\n", i, j);
							addArestaDirecionado(new, i, j);
						}
					}else{
						for(c = 0; c < grafo->matriz_adj[i][j]; c++){
							printf("aresta %i %i\n", i, j);
							addArestaDirecionado(new, i, j);
						}
					}
				}
			}
		}
	}
	return new;
}

Grafo* addVertice(Grafo* grafo, int quant){
	int i, j, c;
	Grafo* new = criarGrafo(grafo->vertices + quant - 1);

	new->isDir = grafo->isDir;

	if(grafo->vertices > 0){
		for(i = 0; i < grafo->vertices; i++){
			for(j = i; j < grafo->vertices; j++){
				if(grafo->matriz_adj[i][j] > 0){
					if(i == j){
						for(c = 0; c < grafo->matriz_adj[i][j] / 2; c++){
							printf("aresta %i %i\n", i, j);
							addAresta(new, i, j);
						}
					}else{
						for(c = 0; c < grafo->matriz_adj[i][j]; c++){
							printf("aresta %i %i\n", i, j);
							addAresta(new, i, j);
						}
					}
				}
			}
		}
	}
	return new;
}


Grafo* RemoveVerticeDirecional(Grafo* grafo, int a){
	int i, j, c;
	Grafo* new = criarGrafo(grafo->vertices - 1);

	a--;
	new->isDir = grafo->isDir;

	for(i = 0; i < grafo->vertices; i++){
		for(j = 0; j < grafo->vertices; j++){
			if(grafo->matriz_adj[i][j] > 0){
				if((i < a) && (j < a)){
					for(c = 0; c < grafo->matriz_adj[i][j]; c++)
						addArestaDirecionado(new, i, j);
				}else if((i < a) && (j > a)){
					for(c = 0; c < grafo->matriz_adj[i][j]; c++)
						addArestaDirecionado(new, i, j-1);
				}else if((i > a) && (j < a)){
					for(c = 0; c < grafo->matriz_adj[i][j]; c++)
						addArestaDirecionado(new, i-1, j);
				}else if((i > a) &&(j > a)){
					for(c = 0; c < grafo->matriz_adj[i][j]; c++)
						addArestaDirecionado(new, i-1, j-1);
				}
			}
		}

	}
	return new;
}

Grafo* RemoveVertice(Grafo* grafo, int a){
	int i, j, c;
	Grafo* new = criarGrafo(grafo->vertices - 1);

	a--;
	new->isDir = grafo->isDir;

	for(i = 0; i < grafo->vertices; i++){
		for(j = i; j < grafo->vertices; j++){
			if(grafo->matriz_adj[i][j] > 0){
				if((i < a) && (j < a)){
					if(i == j){
						for(c = 0; c < grafo->matriz_adj[i][j] / 2; c++)
							addAresta(new, i, j);	
					}else{
						for(c = 0; c < grafo->matriz_adj[i][j]; c++)
							addAresta(new, i, j);
					}
				}else if((i < a) && (j > a)){
					for(c = 0; c < grafo->matriz_adj[i][j]; c++)
						addAresta(new, i, j-1);
				}else if((i > a) && (j < a)){
					for(c = 0; c < grafo->matriz_adj[i][j]; c++)
						addAresta(new, i-1, j);
				}else if((i > a) &&(j > a)){
					if(i == j){
						for(c = 0; c < grafo->matriz_adj[i][j] / 2; c++)
							addAresta(new, i-1, j-1);
					}else{
						for(c = 0; c < grafo->matriz_adj[i][j]; c++)
							addAresta(new, i-1, j-1);
					}
				}
			}
		}
	}
	return new;
}

void putsGrafo (Grafo* grafo){
	printf("\nGrafo %p:\n\tVertices: %d\n\tArestas: %d\n", (void*)grafo,grafo->vertices,grafo->arestas);
	//printf("\tDirecionado: %d\n", grafo->isDir);

	if(grafo->isDir)
		printf("\tGrafo direcionado\n");
	else
		printf("\tGrafo não direcionado\n");
	
	int i,j;
	
	for(i = 0; i < grafo->vertices; i++){
		for(j = 0; j < grafo->vertices; j++){
			printf ("%d ", grafo->matriz_adj[i][j]);
		}
		printf("\n");
	}
}


/*Função usada para ler arquivo, ela pedira o nome do arquivo e ira ler as caracteristicas do grafo e criara um grafo com tais caracteristicas
	então ira continua lendo o arquivo e adcionara os vertices chamando as funções.*/
Grafo* leituraArquivo(){
	Grafo* grafo;
	char arquivo[50], nonAresta, direcao;
	FILE *fp;
	int i, a = 0, b = 0;
	int nVert = 0, nArest = 0;
	/*printf("Nome do arquivo contendo o grafo: ");
	scanf("%s", arquivo);
	fp = fopen( arquivo, "r");*/
	fp = fopen( NDIRLI, "r");
	//fp = fopen( NDIRNLI, "r");
	if(fp == NULL){
		printf("\nArquivo não existe\n");
		return NULL;
	}
	//leitura do arquivo para vertica, direcionado e arestas
	fscanf( fp, "%c\n", &direcao);
	fscanf( fp, "%i\n", &nVert);
	printf("Vertices: %i", nVert);
	fscanf( fp, "%i\n", &nArest);
	printf("Arestas: %i\n", nArest);
	grafo = criarGrafo(nVert);
	if(direcao == 'd'){
		grafo->isDir = 1;
	}else if(direcao == 'n'){
		grafo->isDir = 0;
	}else{
		printf("Arquivo não esta no padrão;\n");
		return NULL;
	}
	for(i = 0; (i < nArest) && (feof(fp) == 0); i++) {
		fscanf( fp, "%c: %i, %i;\n", &nonAresta, &a, &b);
		printf("%c: %i, %i\n", nonAresta, a, b);
		addAresta(grafo, --a, --b);
	}
	putsGrafo(grafo);
	fclose(fp);
	return grafo;
}

void seLigadoDirecionado(Grafo* grafo){

}

void seLigado(Grafo* grafo){
	int flag[grafo->vertices][grafo->vertices];
	int vertVisit[grafo->vertices];
	int mud = 0, linha = 0, ok = 1;
	int i = linha, j = 0;

	vertVisit[linha] = 1;

	do{
		printf("linha: %i\n", linha);
		if(vertVisit[linha] == 1){
			do{
				mud = 0;
				do{
					if((grafo->matriz_adj[i][j] > 0) && (flag[i][j] == 0) && (i != j)){
						printf("%i\n", vertVisit[j]);
						printf("\nAresta encontrada\n%i <-> %i\n%i", j, i, vertVisit[i]);
						int aux = i;
						vertVisit[j] = 1;
						flag[i][j] = 1;
						i = j;
						j = aux;
						flag[i][j] = 1;
						mud = 1;
					}else if(flag[i][j])
						printf("\nJa passamos aqui\n%i <-> %i\n%i", i, j, vertVisit[i]);
					else
						printf("\nAresta não encontrada\n%i -/- %i\n%i", i, j, vertVisit[i]);
					j++;
				}while(j < grafo->vertices);
				j = 0;
				i = linha;
			}while(mud == 1);
		}
		linha++;
		i = linha;
		j = 0;
		printf("linha: %i\n", linha);
	}while(linha < grafo->vertices);

	for(linha = 0; linha < grafo->vertices; linha++)
		if(vertVisit[linha] == 0)
			ok = 0;

	//finalização
	if(ok == 0)
		printf("\nGrafo não ligado\n");
	else
		printf("\nGrafo ligado\n");
}

void grauNosDirecionado(Grafo* grafo){
	int i, j;
	int grau[grafo->vertices][3];
	for(i = 0; i < grafo->vertices; i++){
		grau[i][0] = 0;
		grau[i][1] = 0;
		grau[i][2] = 0;
	}
	for(i = 0; i < grafo->vertices; i++){
		for(j = i; j < grafo->vertices; j++){
			if((i == j) && (grafo->matriz_adj[i][j] > 0)){
				grau[i][0] += grafo->matriz_adj[i][j];
				grau[i][1] += grafo->matriz_adj[i][j];
				grau[i][2] += grafo->matriz_adj[i][j] * 2;
			}else if((i != j) && (grafo->matriz_adj[i][j] > 0)){
				grau[i][1] += grafo->matriz_adj[i][j];
				grau[i][2] += grafo->matriz_adj[i][j];
				grau[j][0] += grafo->matriz_adj[i][j];
				grau[j][2] += grafo->matriz_adj[i][j];
			}
		}
	}
	for(i = 0; i < grafo->vertices; i++)
		printf("Grau do nó %i: \n\tentrada: %i;\n\tsaida: %i;\n\ttotal: %i", i+1, grau[i][0], grau[i][1], grau[i][2]);

}

void grauNos(Grafo* grafo){
	int i, j;
	int grau[grafo->vertices];
	for(i = 0; i < grafo->vertices; i++)
		grau[i] = 0;
	for(i = 0; i < grafo->vertices; i++){
		for(j = 0; j < grafo->vertices; j++){
			if((i == j) && (grafo->matriz_adj[i][j] > 0)){
				grau[i] += grafo->matriz_adj[i][j] * 2;
			}else if((i != j) && (grafo->matriz_adj[i][j] > 0)){
				grau[i] += grafo->matriz_adj[i][j];
				grau[j] += grafo->matriz_adj[i][j];
			}
		}
	}
	for(i = 0; i < grafo->vertices; i++)
		printf("Grau do nó %i: %i.\n", i+1, grau[i]);	
}

Grafo* complemento(Grafo* grafo){
	Grafo* ret = criarGrafo(grafo->vertices);
	int i, j;
	if(grafo->isDir){
		for(i = 0; i < grafo->vertices; i++){
			for(j = 0; j<grafo->vertices; j++){
				if(grafo->matriz_adj[i][j] == 0)
					addArestaDirecionado(ret,i,j);
			}
		}
	} else {
		for(i = 0; i < grafo->vertices; i++){
			for(j = i; j<grafo->vertices; j++){
				if(grafo->matriz_adj[i][j] == 0)
					addAresta(ret,i,j);
			}
		}
	}

	return ret;

	

}

