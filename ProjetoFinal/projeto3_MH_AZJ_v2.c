#include <stdio.h>
#include <stdlib.h>

 /*____________________________________________________________________________________________*/
/*____________________________________________________________________________________________*/
typedef struct{
	int n_arestas; // Numero de arestas do grafo
	int n_vertices; //Numero de vertices do grafo
	int **matriz; // matriz em que se armazena as arestas de um vertice a outro
	int **custo; //matriz em que se armazena o peso entre um vertice e outro
} Grafo, *pGrafo;

 /*____________________________________________________________________________________________*/
/*____________________________________________________________________________________________*/
pGrafo criaGrafo( int n_vertices);
void addAresta( int origem, int destino, int custo, pGrafo grafo);
int removeVertice( int vertice, pGrafo grafo);

//GrafoTools.c

pGrafo leituraTecladoGrafo();
void putsGrafo();
int escolheVertice( pGrafo grafo);

//GrafoEstado.c

int seConectado( pGrafo grafo);
int seDirecionado( pGrafo grafo);

//Dijkstra.c

void dijkstra( pGrafo grafo, int verticeInicial);

 /*____________________________________________________________________________________________*/
/*____________________________________________________________________________________________*/
pGrafo criaGrafo( int n_vertices){
	pGrafo novo;
	novo = ( Grafo*)malloc( sizeof( Grafo));
	novo->n_vertices = n_vertices;
	novo->n_arestas = 0;

	novo->matriz = ( int**)malloc( sizeof( int*) * n_vertices);
	novo->custo =  ( int**)malloc( sizeof( int*) * n_vertices);
	int i, j;
	for( i = 0; i < n_vertices; i++){
		novo->matriz[ i] = ( int*)malloc( sizeof( int) * n_vertices);
		novo->custo[ i] = ( int*)malloc( sizeof( int) * n_vertices);
		for( j = 0; j < n_vertices; j++){
			novo->matriz[ i][ j] = 0;
			novo->custo[ i][ j] = 0;
		}
	}

	return novo;
}

 /*____________________________________________________________________________________________*/
/*____________________________________________________________________________________________*/
void addAresta( int origem, int destino, int custo, pGrafo grafo){
	grafo->matriz[ origem][ destino]++;
	grafo->custo[ origem][ destino] = custo;
	grafo->n_arestas++;
}

 /*____________________________________________________________________________________________*/
/*____________________________________________________________________________________________*/
int removeVertice(int vertice, pGrafo grafo){
	vertice--;
	if( vertice >= 0){
		if( vertice < grafo->n_vertices){
			int i, j;
			int tam_novo = grafo->n_vertices - 1;

			int **novo_vertices, **novo_custo;
			novo_vertices = ( int**)malloc( sizeof( int*) * tam_novo);
			novo_custo = ( int**)malloc( sizeof( int*) * tam_novo);

			for( i = 0; i < grafo->n_vertices; i++){

				novo_vertices[ i] = ( int*)malloc( sizeof( int) * tam_novo);
				novo_custo[ i] = ( int*)malloc( sizeof( int) * tam_novo);

				for( j = 0; j < grafo->n_vertices; j++){

					if( ( i != vertice) && ( j != vertice)){

						if( ( i < vertice) && ( j < vertice)){
							novo_vertices[ i][ j] = grafo->matriz[ i][ j];
							novo_custo[ i][ j] = grafo->custo[ i][ j];
						}else if( ( i < vertice) && ( j > vertice)){
							novo_vertices[ i][ j] = grafo->matriz[ i][ j-1];
							novo_custo[ i][ j] = grafo->custo[ i][ j-1];
						}else if( ( i > vertice) && ( j < vertice)){
							novo_vertices[ i][ j] = grafo->matriz[ i-1][ j];
							novo_custo[ i][ j] = grafo->custo[ i-1][ j];
						}else if( ( i > vertice) && ( j > vertice)){
							novo_vertices[ i][ j] = grafo->matriz[ i-1][ j-1];
							novo_custo[ i][ j] = grafo->custo[ i-1][ j-1];
						}
					}
				}
			}
			grafo->matriz = novo_vertices;
			grafo->custo = novo_custo;
			grafo->n_vertices--;
			return 1;
		}
	}
	printf( "Vertice não existente!\n");
	return 0;
}

 /*____________________________________________________________________________________________*/
/*____________________________________________________________________________________________*/
int seConectado(Grafo* grafo){
	int i, j;
	int n_vertices = grafo->n_vertices;
	int vert_visitado[ n_vertices][2];
	int linha = 0, leave = 1;
	for( i = 0; i < n_vertices; i++){
		vert_visitado[ i][ 0] = 0;
		vert_visitado[ i][ 1] = 0;
	}

	vert_visitado[ linha][0] = 1;
	vert_visitado[ linha][1] = 1;
	j = 0;
	i = linha;
	do{
		leave = 1;
		for( i = 0; i < n_vertices; i++){
			for( j = i + 1; j < n_vertices; j++){
				if(( grafo->matriz[ i][ j] > 0) || ( grafo->matriz[ j][ i] > 0)){
					if((vert_visitado[ i][ 0] == 1) && (vert_visitado[ j][ 0] == 0)){
						vert_visitado[ j][ 0] = 1;
						leave = 0;
					}else if((vert_visitado[ i][ 0] == 0) && (vert_visitado[ j][ 0] == 1)){
						vert_visitado[ i][ 0] = 1;
						leave = 0;
					}
				}
			}
		}
	}while( !leave);

	for( i = 0; i < n_vertices; i++){
		if(vert_visitado[ i][ 0] != 1){
			printf("Grafo não conectado!\n");
			return 0;
		}
	}

	printf("Grafo conexo!\n");
	return 1;
}

 /*____________________________________________________________________________________________*/
/*____________________________________________________________________________________________*/
int seDirecionado(Grafo* grafo){
	int i, j;
	int loop = 0;
	for( i = 0; i < grafo->n_vertices; i++){
		for( j = i; j < grafo->n_vertices; j++){
			if((grafo->matriz[ i][ j] != grafo->matriz[ j][ i]) || 
				(grafo->custo[ i][ j] != grafo->custo[ j][ i])){
				printf( "Grafo direcionado!\n");
				return 1;
			}
		}
		if(grafo->matriz[ i][ i] != 0)
			loop = 1;
	}
	if(!loop)
		printf( "Grafo simples!\n");
	else
		printf( "Grafo não direcionado!\n");
	return 0;
}

 /*____________________________________________________________________________________________*/
/*____________________________________________________________________________________________*/
pGrafo leituraTecladoGrafo(){
	int n_vertices, n_arestas;
	int v1, v2, custo;
	int i;
	pGrafo grafo;

	printf( "Inicindo inserção de dados!\n");

	printf( "\nNumero de vertices: ");
	scanf( "%i", &n_vertices);
	printf( "\nNumero de arestas: ");
	scanf( "%i", &n_arestas);
	grafo = criaGrafo( n_vertices);
	putsGrafo(grafo);
	printf("Modelo de entrada de vertice:\nV1 V2 Custo\n");
	for( i = 0; i < n_arestas; i++){
		int ok = 0;
		while( !ok){
			scanf( "%i%i%i", &v1, &v2, &custo);
			if( ( v1 <= n_vertices) && ( v2 <= n_vertices) && ( v1 > 0) && ( v2 > 0)){
				addAresta( --v1, --v2, custo, grafo);
				grafo->n_arestas++;
				printf("Aresta inserida: %i %i %i\n", v1+1, v2+1, custo);
				ok = 1;
			}else{
				printf("Aresta invalido!\n");
				ok = 0;
			}
		}
	}
	return grafo;
}

 /*____________________________________________________________________________________________*/
/*____________________________________________________________________________________________*/
void putsGrafo( pGrafo grafo){
	int i, j;
	printf( "Grafo: %p;\n\nVertices: %i;\n", ( void*)grafo, grafo->n_vertices);
	printf( "    ");
	for( j = 0; j < grafo->n_vertices; j++)
		printf( " %3i ", j+1);
	printf( "\n\n");
	for( i = 0; i < grafo->n_vertices; i++){
		printf( "%2i  ", i+1);
		for ( j = 0; j < grafo->n_vertices; j++){
			printf( " %3i ", grafo->matriz[i][j]);
		}
		printf("\n    ");
		for( j = 0; j < grafo->n_vertices; j++){
			printf( " %3i ", grafo->custo[i][j]);
		}
		printf( "\n\n");
	}
}


 /*____________________________________________________________________________________________*/
/*____________________________________________________________________________________________*/
int main(){
	
	return 0;
}