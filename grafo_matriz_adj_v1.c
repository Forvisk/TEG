#include <stdio.h>

int main(){
	int grafo[20][20][2];
	FILE *fp = NULL;
	int nVert = 0, nArest = 0;
	char arest, direcional = 'n';
	
	printf("%i", grafo[2][6][1]);
	
	fp = fopen("grafo.txt", "r");
	if(fp == NULL){
		printf("\nArquivo não existe\n");
		return 0;
	}
	fscanf( fp, "%c\n", &direcional);
	fscanf( fp, "%i\n", &nVert);
	printf("%i\n", nVert);
	fscanf( fp, "%i\n", &nArest);
	printf("%i\n", nArest);
	int a, b, i;
	for (int i = 0; i < nArest; i++){
		fscanf( fp, "%c: %i, %i;\n", &arest, &a, &b);
		printf("%c: %i, %i\n", arest, a, b);
		++grafo[a][b][0];
		grafo[a][b][1] = 0;
		if(direcional == 'n'){
			++grafo[b][a][0];
			grafo[b][a][1] = 0;
		}
	}
	
	//grafo completo
	
	if(direcional == 'n'){
		printf("\ngrafo não direcionado: implementação necessaria");
	}else{
		printf("\ngrafo direcionado: implementação a ser feita");
	}
	
	return 0;
}
