// Rappresentiamo una palude con un array bidimensionale di 0 e 1, in cui 1 rappresenta un punto attraversabile della palude, mentre 0 rappresenta un punto inaccessibile.
// Scriviamo un programma che, data la mappa di una palude, ne cerca un attraversamento e, se esiste, lo visualizza.

#include <stdio.h>
#define N 6
#define vuot { 0, 0, 0, 0, 0, 0 }
#define rig1 { 1, 0, 0, 1, 0, 0 }
#define rig2 { 1, 0, 0, 0, 0, 0 }
#define rig3 { 0, 1, 0, 0, 0, 1 }
#define rig4 { 0, 0, 1, 1, 1, 0 }
#define rig5 { 0, 1, 0, 0, 0, 0 }

struct Coords {
	int i;
	int j;
};

// Carica scontata
void carica(int m[][N]);
int attraversa(int m[][N], int perc[N]);
void stampaArr(int perc[N]);

void main() {
	int m[N][N] = {rig1, rig2, rig3, rig4, rig5, vuot};
	int perc[N];
	
	// carica(m);
	if(attraversa(m, perc)) {
		puts("Percorso per attraversare:");
		stampaArr(perc);
	} else
		printf("Palude non attraversabile.");
}

int attraversa(int m[][N], int perc[N]) {
	struct Coords coords;
	coords.j = 0;
	int r;
	for(coords.i=0; coords.i<N; coords.i++)
		if(rec(m, perc, coords))
			return 1;
	return 0;
}

int rec(int m[][N], int perc[N], struct Coords coords) {
	
	if(coords.j == N)
		return 1;
	
	int k = (!coords.i) ? 0 : -1;
	int w = (coords.i == N-1) ? 1 : 2;
	
	if(m[coords.i][coords.j])
		for(k=k; k<w; k++) {
			struct Coords tcoords = coords;
			tcoords.i += k;
			tcoords.j++;
			if(rec(m, perc, tcoords)) {
				perc[coords.j] = coords.i;
//				printf("i: %d | j: %d | k: %d\n", coords.i, coords.j, k);
				return 1;
			}
		}
	return 0;
}

void stampaArr(int perc[N]) {
	int i;
//	puts("\n");
	for(i=0; i<N; i++)
		printf("%d ", perc[i]);
	puts("");
}
