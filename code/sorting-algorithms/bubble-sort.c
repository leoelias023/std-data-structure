#include <stdlib.h>
#include <stdio.h>
#define SIZE 10

void bubble_sort(int vector[], int vector_size) {
  int reordered, i;
  int size = vector_size;

  do {

    size--;
    reordered = 0;
    for (i = 0; i < size; i++) {
      if (vector[i] > vector[i+1]) {
        int aux = vector[i];
        vector[i] = vector[i+1];
        vector[i+1] = aux;
        reordered = 1;
      }
    }

  } while(reordered);
}

void print(int vector[], int vector_size, char * title) {
  printf("\n\n%s", title);

  for (int i = 0; i < vector_size; i++) {
    printf("\n[%i] - %i", i, vector[i]);
  }
}

int main() {

  int vector[SIZE] = {0, 5, 2, -1, 6, 2, 10, 11, 5, 3};

  print(vector, SIZE, "Vetor não ordenado");
  bubble_sort(vector, SIZE);
  print(vector, SIZE, "Vetor ordenado");

  printf("\n");

  return 0;
}