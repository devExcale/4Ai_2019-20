#include <stdio.h>

typedef unsigned long long int hecklong;

int countDivisors(hecklong x);
void loadDivisors(hecklong x, hecklong* arr);

void main() {
	hecklong x;
	
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
	
	hecklong divisors[len];
	loadDivisors(x, divisors);
	
	printf("Il numero %d ha %d divisori, di conseguenza non e' primo:\n  1", x, len);
	hecklong i;
	for(i=1; i<len; i++)
		printf(", %d", divisors[i]);
}

int countDivisors(hecklong x) {
	
	if(x == 1)
		return x;
	
	hecklong i;
	int d = 2;
	for(i=2; i<=x/2; i++) {
		if(!(x%i))
			d++;
	}
	
	return d;
}

void loadDivisors(hecklong x, hecklong* arr) {
	
	if(x == 1) {
		*arr = 1;
		return;
	}
	
	hecklong i, *p = arr+1;
	for(i=2; i<=x/2; i++) {
		if(!(x%i))
			*(p++) = i;
	}
	*arr = 1;
	*p = x;
}
