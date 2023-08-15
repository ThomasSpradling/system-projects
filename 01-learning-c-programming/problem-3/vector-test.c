#include "vector.c"

int main(int argc, char const *argv[])
{
  vector *vec = init_vector();
  vector_push(vec, 5);
  vector_push(vec, 4);
  print_vector(vec); // [5, 4, ], size = 4

  vector_pop(vec);
  vector_push(vec, 3);
  vector_push(vec, 3);
  vector_push(vec, 3);
  vector_push(vec, 3);
  print_vector(vec); // [5, 3, 3, 3, 3, ], size = 8

  vector_push(vec, 5);
  print_vector(vec); // [5, 3, 3, 3, 3, 5], size = 16

  vector_pop(vec);
  vector_pop(vec);
  print_vector(vec); // [5, 3, 3, 3, ], size = 8
  
  vector_pop(vec);
  vector_pop(vec);
  vector_pop(vec);
  vector_pop(vec);
  print_vector(vec); // [], size = 4

  vector_pop(vec); // Cannot pop from vector of length zero!
  print_vector(vec); // [], size = 4
  free_vector(vec);
  return 0;
}
