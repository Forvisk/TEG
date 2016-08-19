#include <stdio.h>

int main(){
	
	int grafo[20][20], flag[20][20];
	
	FILE *fp = NULL;
	int nVert = 0, nArest = 0;
	char arest, direcional = 'n';
	
	
	int a, b, i;
	
	printf("%i", grafo[2][6]);
	
	//Abertura do arquivo
	fp = fopen("grafo.txt", "r");
	if(fp == NULL){
		printf("\nArquivo não existe\n");
		return 0;
	}
	
	//leitura do arquivo para vertica, direcionado e arestas
	fscanf( fp, "%c\n", &direcional);
	fscanf( fp, "%i\n", &nVert);
	printf("%i\n", nVert);
	fscanf( fp, "%i\n", &nArest);
	printf("%i\n", nArest);
	
	
	
	//leitura do arquivo para grafo
	for (i = 0; i < nArest; i++){
		fscanf( fp, "%c: %i, %i;\n", &arest, &a, &b);
		printf("%c: %i, %i\n", arest, a, b);
		++grafo[a][b];
		if(direcional == 'n'){
			++grafo[b][a];
		}
	}
	
	
	//grafo completo
	if(direcional == 'n'){
		printf("\ngrafo não direcionado: implementação necessaria");
		int p[2];
		/*do{
			
		}while(1);*/
	}else{
		printf("\ngrafo direcionado: implementação a ser feita");
	}
	
	return 0;
}
