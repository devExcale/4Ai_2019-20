#include <stdio.h>

typedef unsigned char bool;

void leggiArray(int* arr, int len);
bool presente(int value, int* arr, int len);
void stampaArray(int* arr, int len);

void main() {
	
	int len;
	printf("Inserire lunghezza vettore: ");
	scanf("%d", &len);
	
	int arr[len];
	
	leggiArray(arr, len);
	stampaArray(arr, len);
}

void leggiArray(int* arr, int len) {
	int temp, i;
	
	for(i=0; i<len; i++) {
		printf("Inserire valore %d: ", i);
		scanf("%d", &temp);
		
		if(presente(temp, arr, i)) {
			printf("Valore gia' inserito.\n");
			i--;
		} else
			*(arr+i) = temp;
	}
	
}

bool presente(int value, int* arr, int len) {
	bool p = 0;
	int i;
	for(i=0; i<len; i++)
		if(value == *(arr+i)) {
			++p;
			break;
		}
	
	return p;
}

void stampaArray(int* arr, int len) {
	int i;
	printf("\n");
	for(i=0; i<len; i++)
		printf("| %d\n", *(arr+i));
	printf("\n");
}
