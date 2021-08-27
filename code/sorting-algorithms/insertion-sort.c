#include <stdio.h>
#define SIZE 6

void insertion_sort(int vector[], int vector_size) {
  for (int i = 1; i < vector_size; i++) {
    int current = vector[i];
    int index_previous = i - 1;

    while (index_previous >= 0 && vector[index_previous] > current) {
      vector[index_previous+1] = vector[index_previous];
      index_previous--;
    }

    vector[index_previous + 1] = current;
  }

}

void print(int vector[], int vector_size, char * title) {
  printf("\n\n%s", title);

  for (int i = 0; i < vector_size; i++) {
    printf("\n[%i] - %i", i, vector[i]);
  }
}


int main() {
  printf("Insertion sort\n");

  int vector[SIZE] = { 3, 2, 6, 1, -2, -1 };

  print(vector, SIZE, "Não ordenado");
  insertion_sort(vector, SIZE);
  print(vector, SIZE, "Ordenado");


  printf("\n");
}