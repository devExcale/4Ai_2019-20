#include <stdio.h>
#include <math.h>

typedef char bool;

void readArr(float* arr, int len);
float evenArr(float* arr, int len);
bool checkCloser(float even, float num, float* delta);

void main() {
	int len;
	
	printf("Inserire lunghezza vettore: ");
	scanf("%d", &len);
	
	float arr[len];
	readArr(arr, len);
	
	float media = evenArr(arr, len);
	float delta = abs(media-arr[0]);
	int index=0;
	for(int i=1; i<len; i++)
		if(checkCloser(media, arr[i], &delta))
			index = i;
	
	printf("Il valore che si avvicina di piu' alla media e' %.2f, con indice %d.\n", arr[index], index);
}

void readArr(float* arr, int len) {
	for(int i=0; i<len; i++) {
		printf("Inserire valore %d: ", i);
		scanf("%f", arr+i);
	}
}

float evenArr(float* arr, int len) {
	float sum = 0;
	for(int i=0; i<len; i++)
		sum += *(arr+i);
	
	return sum/(float)len;
}

bool checkCloser(float even, float num, float* delta) {
	bool closer = 0;
	float currentDelta = abs(even-num);
	if(currentDelta < *delta) {
		*delta = currentDelta;
		++closer;
	}
	return closer;
}
