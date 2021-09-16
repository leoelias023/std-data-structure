#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO_VET 20

// Funcoes utilitarias
// Preenche um vetor de tamanho n com numeros aleatorios de 0 ate limite
void initRand(int* vetor, int n, int limite) {
	int i;
	float fatorMult = ((float)limite)/(float)RAND_MAX;
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		vetor[i] = rand() * fatorMult;
	}
}

// Calcula o tempo entre duas tomadas de tempo em segundos
float calculaTempoSegundos(clock_t ini, clock_t fim) {
	return ((double)fim-ini)/CLOCKS_PER_SEC;
}

// Faz o processador aguardar ms milisegundos - Consome CPU !
void dormir(unsigned int ms)
{
    clock_t goal = ms + clock();
    while (goal > clock());
}


// Imprime o vetor
void imprimeVetor(int v[], int tam) {
 	int i;
 	for (i = 0; i < tam; i++) {
 		if (i > 0) printf(", ");
 		printf("%d", v[i]);
	}
	printf("\n");
 }

 int *copiarVetor(int vet[], int tamanho) {
 	int *v = malloc(tamanho * sizeof(int));
 	int i;
 	for (i = 0; i < tamanho; i++) {
 		v[i] = vet[i];
	}
	return v;
 }

void bubbleSort(int v[], int tam) {
    int i, aux, trocou;
    do {
    	tam--;
        // usado para otimizar o algoritmo
        trocou = 0;
        for(i = 0; i < tam; i++)
            if(v[i] > v[i + 1]) {
               aux=v[i];
               v[i]=v[i+1];
               v[i+1]=aux;
               trocou = 1;
            }
    } while(trocou);
}

void insertionSort(int v[], int n) {
  int i, j, chave;
  for(j=1; j<n; j++) {
       chave = v[j];
       i = j-1;
       while(i >= 0 && v[i] > chave){
               v[i+1] = v[i];
               i--;
       }
        v[i+1] = chave;
     }
 }

 void selectionSort(int v[], int n) {
   int i, index_minor;

   for (i = 0; i < n; i++) {
     index_minor = i;
     for (int j = i; j < n; j++) {
       if (v[index_minor] > v[j]) {
         index_minor = j;
       }
     }

		 int minor = v[index_minor];
     v[index_minor] = v[i];
     v[i] = minor;
   }
 }

void shellSort(int *vet, int size) {
    int i, h = 1;

    while(h < size) {
        h = 3 * h + 1;
    }

    while (h > 0) {
        for(i = h; i < size; i++) {
            int current_value = vet[i], j = i;
            while (j > h - 1 && current_value <= vet[j - h]) {
                vet[j] = vet[j - h];
                j -= h;
            }
            vet[j] = current_value;
        }
        h /= 3;
    }
}
 int main(int argc, char *argv[]) {
	clock_t ini, fim;
	int vetBubble[TAMANHO_VET];
	int *vetInsertion, *vetSelection, *vetShell;

	initRand(vetBubble, TAMANHO_VET, 5000);

	// So podemos comparar a performance se os
	// metodos de ordenacao ordenarem exatamente os
	// mesmos dados
	vetInsertion = copiarVetor(vetBubble, TAMANHO_VET);
	vetSelection = copiarVetor(vetBubble, TAMANHO_VET);
  vetShell = copiarVetor(vetBubble, TAMANHO_VET);

	printf("\nBubble Sort\n");

	imprimeVetor(vetBubble, 20); // apenas 20 posicoes

	ini = clock();
	bubbleSort(vetBubble, TAMANHO_VET);
	fim = clock();

	imprimeVetor(vetBubble, 20); // apenas 20 posicoes
	printf("Tempo Bubble Sort %f\n", calculaTempoSegundos(ini,fim));




	printf("\nsertion Sort\n");

	imprimeVetor(vetInsertion, 20); // apenas 20 posicoes

	ini = clock();
	insertionSort(vetInsertion, TAMANHO_VET);
	fim = clock();

	imprimeVetor(vetInsertion, 20); // apenas 20 posicoes
	printf("Tempo Insertion Sort %f\n", calculaTempoSegundos(ini,fim));

	imprimeVetor(vetInsertion, 20); // apenas 20 posicoes





	printf("\nSelection Sort\n");

	imprimeVetor(vetSelection, 20);

	ini = clock();
	selectionSort(vetSelection, TAMANHO_VET);
	fim = clock();

	imprimeVetor(vetSelection, 20);
	printf("Tempo Selection Sort %f\n", calculaTempoSegundos(ini, fim));
	imprimeVetor(vetSelection, 20);




  printf("\nShell Sort\n");

  imprimeVetor(vetShell, 20);

  ini = clock();
  shellSort(vetShell, TAMANHO_VET);
  fim = clock();

  imprimeVetor(vetShell, 20);
	printf("Tempo Shell Sort %f\n", calculaTempoSegundos(ini, fim));
	imprimeVetor(vetShell, 20);

	return 0;
}