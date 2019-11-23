#include <stdio.h>
#define N 4

typedef char bool;

void caricaMatrice(int m[][N]);
bool controlla(int m[][N]);
void stampaM(int m[][N]);

void main() {
	int m[N][N];
	
	caricaMatrice(m);
	if(controlla(m))
		printf("La matrice e' simmetrica.\n");
	else
		printf("La matrice non e' simmetrica.\n");
	
	stampaM(m);
}

void caricaMatrice(int m[][N]) {
	int i, j;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++) {
			printf("Inserire valore [%d][%d]: ", i, j);
			scanf("%d", &m[i][j]);
		}
}

bool controlla(int m[][N]) {
	int i, j;
	for(i=1; i<N; i++)
		for(j=0; j<i; j++)
			if(m[i][j] != m[j][i])
				return 0;
	return 1;
}

void stampaM(int m[][N]) {
	int i, j;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++)
			printf("%2d ", m[i][j]);
		printf("\n");
	}
}
