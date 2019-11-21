#include <stdio.h>
#define N 3
#define CC_LIM 1500

typedef struct {
	char marca[15];
	int cilindrata;
	int anno_immat;
	struct {
		char nome[20];
		char cognome[20];
	} acquirente;
} Auto;

void caricaAutosalone(Auto autosalone[]);
void visualizzaAutosalone(Auto autosalone[]);
void acquirentiSuperiori(Auto autosalone[]);
int immatricolateNel(int anno, Auto autosalone[]);

void main() {
	Auto autosalone[N];
	caricaAutosalone(autosalone);
	visualizzaAutosalone(autosalone);
}


void caricaAutosalone(Auto autosalone[]) {
	int i, immat;
	for(i=0; i<N; i++) {
		printf("[%d] Inserire marca: ", i);
	//	fgets(&autosalone[i].marca, 15, stdin);
		scanf(" %s", &autosalone[i].marca);
		printf("[%d] Inserire cilindrata: ", i);
		scanf(" %d", &autosalone[i].cilindrata);
		printf("[%d] Inserire anno immatricolazione: ", i);
		scanf("%d", &autosalone[i].anno_immat);
		printf("[%d] Inserire cognome acquirente: ", i);
		scanf(" ");
	//	fgets(&autosalone[i].acquirente.cognome, 20, stdin);
		scanf(" %s", &autosalone[i].acquirente.cognome);
		printf("[%d] Inserire nome acquirente: ", i);
	//	fgets(&autosalone[i].acquirente.nome, 20, stdin);
		scanf(" %s", &autosalone[i].acquirente.nome);
	}
	
	printf("Inserire anno immatricolazione da ricercare: ");
	scanf("%d", &immat);
	
	acquirentiSuperiori(autosalone);
	printf("Immatricolati nel %d: %d\n", immat, immatricolateNel(immat, autosalone));
	
}

void visualizzaAutosalone(Auto autosalone[]) {
	int i;
	for(i=0; i<N; i++)
		printf("[%d]\nMarca: %s\nCilindrata: %d\nImmatricolazione: %d\nAcquirente: %s %s\n", i, autosalone[i].marca, autosalone[i].cilindrata, autosalone[i].anno_immat, autosalone[i].acquirente.cognome, autosalone[i].acquirente.nome);
}

void acquirentiSuperiori(Auto autosalone[]) {
	int i;
	printf("\n\tSuperiori a %d cc\n", CC_LIM);
	for(i=0; i<N; i++)
		if(autosalone[i].cilindrata > CC_LIM)
			printf("[%d] %s\n", i, autosalone[i].acquirente.cognome);
}

int immatricolateNel(int anno, Auto autosalone[]) {
	int i, j=0;
	for(i=0; i<N; i++)
		if(autosalone[i].anno_immat == anno)
			j++;
	return j;
}
