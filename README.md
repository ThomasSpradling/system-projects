# System Projects
This repository consists up of a few small projects/problems I'm working on as I read through [Computer Organization and Design](https://www.amazon.com/Computer-Organization-Design-Fifth-Architecture/dp/0124077269) as well as some parts of the online lectures under [CS61C] (https://inst.eecs.berkeley.edu//~cs61c/sp15/) whose lectures are [on the Internet Archive](https://archive.org/details/ucberkeley-webcast-PL-XXv-cvA_iCl2-D-FS5mk0jFF6cYSJs_?tab=collection). For each project I work on here, I'll give a brief description of the project as well as anything I learned from its completion.

## Projects

### Project 01: Learning C Programming
This first project is less of a project and more of a review towards C programming. I'll lay out the problems I did below and solve them within a relevent folder of the repo.
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

## Upcoming
- [x] ~~Learning C Programming~~
- [ ] Learning MIPS Assembly Programming