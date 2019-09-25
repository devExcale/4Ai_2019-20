#include <stdio.h>

void loadOdds(int* arr, int len);
int countMultiples(int* arr, int len, int n);
void loadMultiples(int* multArr, int* valuesArr, int vaLen, int n);
void printArr(int* arr, int len);

void main() {
	int N, X;
	
	// LETTURA VALORI INPUT
	do {
		printf("Inserire numeri da leggere: ");
		scanf("%d", &N);
	} while(N<2 || N>50);
	
	printf("Inserire numero X: ");
	scanf("%d", &X);
	
	int v[N], mults;
	
	loadOdds(v, N);
	mults = countMultiples(v, N, X);
	
	int m[mults];
	
	loadMultiples(m, v, N, X);
	printf((mults) ? "I multipli sono %d:\n" : "I multipli sono %d.\n", mults);
	printArr(m, mults);
}

void loadOdds(int* arr, int len) {
	int i, temp;
	for(i=0; i<len; i++) {
		printf("Inserire valore %d: ", i+1);
		scanf("%d", &temp);
		if(temp%2)
			*(arr+i) = temp;
		else
			i--;
	}
}

int countMultiples(int* arr, int len, int n) {
	int m = 0;
	while(--len>=0)
		if(!(*(arr+len)%n))
			m++;
	
	return m;
}

void loadMultiples(int* multArr, int* valuesArr, int vaLen, int n) {
	int i;
	for(i=0; i<vaLen; i++)
		if(!(*(valuesArr++)%n))
			*(multArr++) = *(valuesArr-1);
}

void printArr(int* arr, int len) {
	int i;
	for(i=0; i<len; i++)
		printf("%d ", *(arr+i));
}
