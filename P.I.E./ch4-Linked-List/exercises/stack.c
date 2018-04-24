/*
* Implementation of a Stack using a linked list
*
* Programming Interviews Exposed, 3rd, Mongan, Giguere, Kindler
* Created by @guti7 on April 23 2018
*/

#include <stdio.h>
#include <stdbool.h>

typedef struct Element {
  struct Element *next;
  void *data;
} Element;

bool createStack(Element **stack);
bool deleteStack(Element **stack);
bool push(Element **stack, void *data);
bool pop(Element **stack , void **data);

int main(void) {
  
  return 0;
}

bool createStack(Element **stack) {
  *stack = NULL;
  return true;
}