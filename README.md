# System Projects
This repository consists up of a few small projects/problems I'm working on as I read through [Computer Organization and Design](https://www.amazon.com/Computer-Organization-Design-Fifth-Architecture/dp/0124077269) as well as some parts of the online lectures under 
[CS61C](https://inst.eecs.berkeley.edu//~cs61c/sp15/) whose lectures are [on the Internet Archive](https://archive.org/details/ucberkeley-webcast-PL-XXv-cvA_iCl2-D-FS5mk0jFF6cYSJs_?tab=collection). For each project I work on here, I'll give a brief description of the project as well as anything I learned from its completion.

## Projects

### Project 01: Learning C Programming
*Language: C*

This first project is less of a project and more of a review towards C programming. I'll lay out the problems I did below and solve them within a relevent folder of the repo. In each case, I am compiling my programs using the GCC compiler.

1. Write a function `strlen` that returns the number of bytes in a string.

2. Given a linked list node of the form:
```c
typedef struct node {
  int value;
  struct node *next;
} node;
```
write a function to detect if the linked list has a cycle.

3. Create a dynamic array using a `struct` as a pointer in C. Make it such that if at least 3/4th the capacity is full-filled, double the size of the array. Similarly, if at most 1/4th the capacity is fullfilled, reduce capacity by half. Despite the above, there must always exist at least four entries in the array. Write two functions, `vector_push(vector *v, int a)` to add `a` at the end of the vector and `vector_pop(vector *v)` to return and remove the last element of the vector.

### Project 02: Simple Git Clone
*Language: C*

Since this is a more substantial project, the code for it will be available at [another repo](https://github.com/ThomasSpradling/git-clone). The basic concept involves the building of a small clone of git, aptly named "pit", that supports tracking, committing, and branching. Checkout that repository for a more full description and the source code.

### Project 03: Learning MIPS Assembly Programming
*Language: Assembly (MIPS)*

Much like project 01, this project will primarily focus on learning to program via a few illustrative problems. As a cheathseet for MIPS, I am used this convenient ["Green Sheet"](https://inst.eecs.berkeley.edu//~cs61c/resources/MIPS_Green_Sheet.pdf). In each problem below, I'm compiling using [SPIM](https://formulae.brew.sh/formula/spim), which is a MIPS simulator. To use, you would run `spim` in the terminal, which will start the simulator. One can then use `load "example.s"` to load an assembly file `example.s` which can be ran using the `run` SPIM command. Below are the main problems I did:
0. Compute and print `6 + 7` in MIPS.

1. Convert the following suggestive implementation of `strcpy()` code from C to MIPS:
```c
// $s1 -> s1
// $s2 -> s2
int i = 0;
do {
  s2[i] = s1[i];
  i++;
} while (s1[i] != '\0');
s2[i] = '\0';
```

2. Write an implementation of `map` over a linked list in MIPS using the following C code:
```c
struct node {
  int value;
  struct node *next;
};

void map(struct node *head, int (*f)(int)) {
  if (!head) { return; }
  head->value = f(head->value);
  map(head->next, f);
}
```

3. Write the following memoized Fibonacci function in MIPS:
```c
int fib(int n, int* cache) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  }
  if (cache[n]) {
    return cache[n];
  }

  cache[n] = fib(n - 1, cache) + fib(n - 2, cache);
  return cache[n];
}
```

### Project 04: MIPS Assembler and Linker
*Languages: C, Assembly (MIPS)*

Similar to the git project above, this project is substantial enough to deserve [its own repository](https://github.com/ThomasSpradling/assembler-and-linker). The basic concept here will be to build an assembly in the C programming language that converts the `.text` code into the MIPS architecture instructions in two passes. After that a linker will built using assembly itself to link the various components together.


## Upcoming
- [x] ~~Learning C Programming~~
- [x] ~~Simple Git Clone~~
- [x] ~~Learning MIPS Assembly Programming~~
- [ ] MIPS Assembler and Linker
- [ ] Learning OpenMP
