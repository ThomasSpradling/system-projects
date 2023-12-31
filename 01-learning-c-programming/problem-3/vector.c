#include "vector.h"

vector *init_vector() {
    int *head = malloc(sizeof(int) * 4);
    if (head == NULL) {
        printf("Not enough memory!\n");
        exit(1);
        return NULL;
    }
    
    vector *vec = malloc(sizeof(vector));
    if (vec == NULL) {
        free(head);
        printf("Not enough memory for the vector structure!\n");
        exit(1);
        return NULL;
    }
    
    vec->head = head;
    vec->size = 4;
    vec->length = 0;
    
    return vec;
}

void free_vector(vector *vec) {
  free(vec->head);
}

void vector_push(vector *vec, int a) {
  // if length is at least 3/4th the current size
  if (4 * (vec->length + 1) >= 3 * vec->size) {
    vec->head = realloc(vec->head, sizeof(int) * vec->size * 2);
    if (vec->head == NULL) {
      printf("Not enough memory!\n");
      exit(1);
      return;
    }
    vec->size *= 2;
  }
  vec->head[vec->length] = a;
  vec->length++;
}

int vector_pop(vector *vec) {
  if (vec->length == 0) {
    printf("Cannot pop from vector of length zero!\n");
    return -1;
  }

  // if length is at most 1/4th the current size
  if (4 * (vec->length - 1) <= vec->size && vec->size >= 8) {
    vec->head = realloc(vec->head, sizeof(int) * vec->size / 2);
    if (vec->head == NULL) {
      printf("Not enough memory!\n");
      exit(1);
      return -1;
    }

    vec->size /= 2;
  }
  vec->length--;
  return vec->head[vec->length];
}

void print_vector(vector *vec) {
  int *current = vec->head;
  printf("[");
  for (int i = 0; i < vec->length; i++) {
    printf("%d, ", current[i]);
  }
  printf("], size = %d\n", vec->size);
}