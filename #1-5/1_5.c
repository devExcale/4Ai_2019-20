#include <stdio.h>

int countDivisors(int x);
void loadDivisors(int x, int* arr);

void main() {
	int x;
	
	printf("Inserisci numero: ");
	scanf("%d", &x);
	
	if(!x) {
		printf("0 non ha divisori. Non rompere il programma.");
		return;
	}
	
	int len = countDivisors(x);
	
	if(len == 2) {
		printf("Il numero %d ha solo due divisori, di conseguenza e' primo.", x);
		return;
	}
	
	int divisors[len];
	loadDivisors(x, divisors);
	
	printf("Il numero %d ha %d divisori, di conseguenza non e' primo:\n  1", x, len);
	int i;
	for(i=1; i<len; i++)
		printf(", %d", divisors[i]);
}

int countDivisors(int x) {
	
	if(x == 1)
		return x;
	
	int i, d=2;
	
	for(i=2; i<=x/2; i++) {
		if(!(x%i))
			d++;
	}
	
	return d;
}

void loadDivisors(int x, int* arr) {
	
	if(x == 1) {
		*arr = 1;
		return;
	}
	
	int i, *p = arr+1;
	for(i=2; i<=x/2; i++) {
		if(!(x%i))
			*(p++) = i;
	}
	*arr = 1;
	*p = x;
}
