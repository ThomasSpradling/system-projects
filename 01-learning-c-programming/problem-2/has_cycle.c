#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node {
  int value;
  struct node *next;
} node;

bool has_cycle(node *head) {
  node *slow = head;
  node *fast = head;
  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;

    if (fast == slow) {
      return true;
    }
  }
  return false;
}

int main(int argc, char const *argv[])
{
  // empty list
  node *head = NULL;
  printf("%d\n", has_cycle(head) == false);

  // list w/o cycle
  node node3 = {3, NULL};
  node node2 = {2, &node3};
  node node1 = {1, &node2};
  printf("%d\n", has_cycle(&node1) == false);

  // list with cycle
  node node4 = {4, NULL};
  node node3_cyclic = {3, &node4};
  node node2_cyclic = {2, &node3_cyclic};
  node node1_cyclic = {1, &node2_cyclic};
  node4.next = &node2_cyclic;
  printf("%d\n", has_cycle(&node1_cyclic) == true);
  return 0;
}
