// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

#include <stdlib.h>
#include <stdio.h>
#include "ArvoreLarga.h"
#include "CGrafos.h"

Arvore* criarArvore(Grafo* grafo, int verticeInicial){

	/*int marcacao[2][grafo->vertices];
	int i;
	for(i = 0; i < grafo->vertices; i++){
		marcacao[0][i] = SEMMARCA;
		marcacao[1][i] = SEMMARCA;
	}
	marcacao[0][--verticeInicial] = MARCA;*/

	Arvore *tree = (Arvore*)malloc(sizeof(Arvore));

	Vertice *primeiro = (Vertice*)malloc(sizeof(Vertice));
	primeiro->filho = NULL;
	primeiro->pai = NULL;
	primeiro->nome = verticeInicial;

	/*
	tree->inicio = primeiro;
	Vertice *verticeAtual = primeiro;
	Vertice *listaPrimeiro = primeiro->filho;
	Vertice *vertAux;
	Filhos *listaAux;
	*/
	/*do{
		if(marcacao[0][verticeAtual->nome] == MARCA){
			for(int j = 0; j < grafo->vertices; j++){
				if(j != verticeAtual->nome){
					if((grafo->matriz_adj[verticeAtual->nome][j] > 0) && (marcacao[0][j] != MARCA)){

						if(verticeAtual->filho == NULL){//Caso o vertice não possua nenhuma lista para os 
														 filho, criar a lista
							Filhos *novaLista = (Filhos*)malloc(sizeof(Filhos));
							novaLista->vertice = NULL;
							novaLista->proximo = NULL;

							verticeAtual->filho = novaLista;
						}
						listaAux = verticeAtual->filho;

						while(listaAux->vertice != NULL){//caminha alista de filhos
							if(listaAux->proximo == NULL){
								Filhos *novaLista = (Filhos*)malloc(sizeof(Filhos));
								novaLista->vertice = NULL;
								novaLista->proximo = NULL;

								listaAux->proximo = novaLista;
							}

							listaAux = listaAux->proximo;
						}
						Vertice *novoVert = (Vertice*)malloc(sizeof(Vertice));
						novoVert->filho = NULL;
						novoVert->pai = verticeAtual;
						novoVert->nome = j;

						listaAux->vertice = novoVert;

						marcacao[0][j] = MARCA;
					}
				}
			}
			marcacao[1][verticeAtual->nome] = MARCA;
		}

	}while(1);*/
	


	return tree;
}

int adicionaVertice(int novoVertice, int verticePai, Arvore *tree){
	Vertice *new = (Vertice*)malloc(sizeof(Vertice));
	new->pai = NULL;
	new->filho = NULL;
	new->nome = novoVertice;
	if(verticePai = -1){
		tree->inicio = new;
		return SUCESSO;
	}else{
		Vertice *paizao = buscaVertice(verticePai, tree->inicio);
		if(paizao == NULL)
			return FRACASSO;
		else{
			Filhos *lista = paizao->filho;
			Filhos *newLista = (Filhos*)malloc(sizeof(Filhos));
			newLista->vertice = new;
			newLista->proximo = NULL;
			if(lista == NULL)
				paizao->filho = newLista;
			else{
				while(lista->proximo != NULL)
					lista = lista->proximo;
				lista->proximo = newLista;
			}
			return SUCESSO;
		}
	}
}

Vertice* buscaVertice(int nome, Vertice *verticeAtual){
	int ok = 0;
	Filhos *lista = verticeAtual->filho;
	Vertice *vertVerif;
	if(lista == NULL)
		return NULL;
	else{
		do{
			vertVerif = lista->vertice;
			if(vertVerif->nome == nome)
				return vertVerif;
			else
				if(vertVerif->filho != NULL){
					vertVerif = buscaVertice(nome, vertVerif)
					if(vertVerif != NULL)
						return vertVerif;
				}
			lista = lista->proximo;
		}while(lista != NULL);
		return NULL;
	}
}

/*
	if(verticeAtual->filho == NULL){
		Filhos novaLista = (Fihos*)malloc(sizeof(Filhos));
		verticeAtual->filho = novaLista;
	}
*/

void putsArvore(Arvore* arvore){

}