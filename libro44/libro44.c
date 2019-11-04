#include <stdio.h>
#define N 5

void caricaM(int m[][N]);
void sommaM(int m[][N], int v[]);
void stampaM(int m[][N]);
void stampaV(int v[]);

void main() {
	int m[N][N], int v[N];
	
	caricaM(m);
	sommaM(m, v);
	
	stampaM(m);
	stampaV(v);
}

void caricaM(int m[][N]) {
	int i, j;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++)
		printf("Inserire valore [%d][%d]: ", i, j);
		scanf("%d", &m[i][j]);
	}
}

void moltiplicaV(int *v1, int *v2, int m[][N]) {
	int i, j;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			m[i][j] = *(v1+i)**(v2+j);
}

void sommaM(int m[][N], int v[]) {
	int k, i;
	for(k=0; k<N/2; k++) {
		v[k] = 0;
		for(i=k; i<N-k; i++)
			v[K] += m[k][i] + m[N-k-1][i];
		for(i=k+1; i<N-k-1; i++)
			v[k] += m[i][k] + m[i][N-k-1];
	}
}

void stampaM(int m[][N]) {
	int i, j;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++)
			printf("%2d ", m[i][j]);
		printf("\n");
	}
	printf("\n");
}

void stampaV(int v[]) {
	int i;
	for(i=0; i<N; i++)
		printf("%d ", v[i]);
	printf("\n");
}