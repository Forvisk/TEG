#include <stdio.h>

int main(){
	
	int grafo[20][20][2];
	
	int **grafo2, **flag2;
	
	FILE *fp = NULL;
	int nVert = 0, nArest = 0;
	char arest, direcional = 'n';
	
	
	int a, b, i, j;
	
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
	
	//alocação teste
	grafo2 == (int **) malloc(sizeof(int)*nVert);
	flag2 == (int **) malloc(sizeof(int)*nVert);
	for(i = 0; i < nVert; i++){	
		grafo2[i] == (int **) malloc(sizeof(int)*nVert);
		flag2[i] == (int **) malloc(sizeof(int)*nVert);
	}
	
	//zerar vertices
	for(i = 0; i< nVert; i++)
		for(j = 0; j<nVert; j++){
			grafo2[i][j] = 0;
			flag2[i][j] = 0;
		}
	
	//leitura do arquivo para grafo
	for (i = 0; i < nArest; i++){
		fscanf( fp, "%c: %i, %i;\n", &arest, &a, &b);
		printf("%c: %i, %i\n", arest, a, b);
		++grafo[a][b];
		grafo[a][b][1] = 0;
		
		++grafo2[a][b];
		flag2[a][b] = 0;
		if(direcional == 'n'){
			++grafo[b][a][0];
			grafo[b][a][1] = 0;
			
			++grafo2[b][a];
			flag2[b][a] = 0;
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
