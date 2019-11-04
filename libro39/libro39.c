#include <stdio.h>
#define N 5

void caricaV(int *v);
void moltiplicaV(int *v1, int *v2, int m[][N]);
void stampaV(int *v);
void stampaM(int m[][N]);

void main() {
	
	int v1[N], v2[N], m[N][N];
	
	caricaV(v1);
	caricaV(v2);
	
	moltiplicaV(v1, v2, m);
	
	stampaV(v1);
	stampaV(v2);
	stampaM(m);
}

void caricaV(int *v) {
	int i;
	for(i=0; i<N; i++) {
		printf("Inserire valore [%d]: ", i);
		scanf("%d", v+i);
	}
}

void moltiplicaV(int *v1, int *v2, int m[][N]) {
	int i, j;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			m[i][j] = *(v1+i)**(v2+j);
}

void stampaV(int *v) {
	int i;
	for(i=0; i<N; i++)
		printf("%d ", *(v+i));
	printf("\n");
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