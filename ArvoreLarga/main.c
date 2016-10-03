// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

//gcc -Wall ArvoreLarga.c ArvoreLarga.h CGrafos.c CGrafos.h main.c -o arvoreLargura

#include <stdio.h>
#include "CGrafos.h"
#include "ArvoreLarga.h"

int main(void){
	Grafo* grafo = leituraArquivo();
	putsGrafo(grafo);
	/*Arvore* tree = testeArvore();
	putsArvore(tree);
	buscaVerticeArvore(0, tree);
	buscaVerticeArvore(3, tree);
	buscaVerticeArvore(6, tree);
	buscaVerticeArvore(9, tree);*/
	Arvore* tree = criarArvoreLargura( pedeVerticeInicial(),grafo);

	printf("\n\n");
	putsArvore(tree);
	putsDescendentes(pedeVerticeDesejado(), tree);
	putsAscendentes(pedeVerticeDesejado(), tree);
	return 0;
}
