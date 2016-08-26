/*
	gcc -Wall main.c CGrafoVetorAdj.c CGrafoVetorAdj.h -o grafoVetorAdj
*/

#include <stdio.h>
#include "CGrafoVetorAdj.h"

int main(){
	Vetor* vetor = leituraArquivo();

	putsGrafo(vetor);
	return 0;
}