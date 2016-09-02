// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

#include <stdlib.h>
#include <stdio.h>
#include "CGrafos.h"

/*	Função grafo direcionado
*	essa função retorna se o grafo é direcionado ou não
*/
int direcionado(Grafo* grafo){
	return grafo->isDir;
}

/*	Função grafo não direcionado conexo
*	essa função define se o grafo não direcionado é conexo ou não
*/
void seConexo(Grafo* grafo){
	int flag[grafo->vertices][grafo->vertices];
	int vertVisit[grafo->vertices];
	int mud = 0, linha = 0, ok = 1;
	int i, j;
	int subgrafo = 1;
	for(j = 0; j < grafo->vertices; j++){
		vertVisit[j] = 0;
		for(i = 0; i < grafo->vertices; i++)
			flag[i][j] = 0;
	}
	vertVisit[linha] = subgrafo;
	j = 0; i = linha;
	do{
		if(vertVisit[linha] == 0){
			subgrafo++;
			vertVisit[linha] = subgrafo;
		}
		if(vertVisit[linha] > 0){
			do{
				mud = 0;
				do{
					if((grafo->matriz_adj[i][j] > 0) && (flag[i][j] == 0) && (i != j)){
						int aux = i;
						vertVisit[j] = vertVisit[i];
						flag[i][j] = 1;
						i = j;
						j = aux;
						flag[i][j] = 1;
						mud = 1;
					}else	flag[i][j] = 1;
					j++;
				}while(j < grafo->vertices);
				j = 0;
				i = linha;
			}while(mud == 1);
		}
		linha++;
		i = linha;
		j = 0;
	}while(linha < grafo->vertices);
	for(linha = 0; linha < grafo->vertices; linha++){
		printf("%i %i\n", linha, vertVisit[linha]);
		if(vertVisit[linha] == 0)
			ok = 0;
	}
	if(ok == 0)
		printf("\nGrafo desconexo\n");
	else
		printf("\nGrafo Conexo\n");
	if(subgrafo > 1){
		int qualSub;
		for(qualSub = 1; qualSub <= subgrafo; qualSub++){
			int vertSub = 0;
			printf("\nVertices pertencentes ao subgrafo %i:\n\t", qualSub);
			for(linha = 0; linha < grafo->vertices; linha++){
				if(vertVisit[linha] == qualSub){
					vertSub++;
					printf(" %i;", linha);
				}
			}

			int relacaoVert[vertSub][2], v = 0;
			for(linha = 0; linha < grafo->vertices; linha++){
				if(vertVisit[linha] == qualSub){
					relacaoVert[v][0] = linha;
					relacaoVert[v][1] = v;
					printf(" %i = %i;", linha, v);
				}
			}
			Grafo* subGrafo = criaGrado(vertSub);
			for(i = 0; i < grafo->vertices; i++){
				for(j = i; j < grafo->vertices; j++){
					if(vertVisit[i] == qualSub){
						for( v = 0; v < grafo->matriz_adj[i][j]; v++)
							addAresta(subGrafo, (i), (j));
					}
				}
			}
		}
		printf("\n");
	}
}

/*	Função grau de nós para grafo não direcionado
*	essa função calcula o grau de cada nó em um grafo não direcionado
*/
void grauNos(Grafo* grafo){
	int i, j;
	int grau[grafo->vertices];
	for(i = 0; i < grafo->vertices; i++)
		grau[i] = 0;
	for(i = 0; i < grafo->vertices; i++)
		for(j = i; j < grafo->vertices; j++)
			if((i == j) && (grafo->matriz_adj[i][j] > 0)){
				grau[i] += grafo->matriz_adj[i][j] * 2;
			}else if((i != j) && (grafo->matriz_adj[i][j] > 0)){
				grau[i] += grafo->matriz_adj[i][j];
				grau[j] += grafo->matriz_adj[i][j];
			}
	for(i = 0; i < grafo->vertices; i++)
		printf("Grau do nó %i: %i.\n", i+1, grau[i]);	
}