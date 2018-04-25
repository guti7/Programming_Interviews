/*
* Implementation of a Stack using a linked list
*
* Programming Interviews Exposed, 3rd, Mongan, Giguere, Kindler
* Created by @guti7 on April 23 2018
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Element {
  struct Element *next;
  void *data;
} Element;

bool createStack(Element **stack);
bool deleteStack(Element **stack);
bool push(Element **stack, void *data);
bool pop(Element **stack , void **data);
void printStack(Element *stack);

int main(void) {
  
  Element *stack = malloc(sizeof(Element));
  if (createStack(&stack)) {
    printf("Stack creation successful\n");
  }
  
  printStack(stack);

  int integer1 = 5;
  int integer2 = 6;
  int integer3 = 8;
  int integer4 = 9;
  
  // push elements
  push(&stack, &integer1);
  push(&stack, &integer2);
  push(&stack, &integer3);
  push(&stack, &integer4);
  
  // Report
  printStack(stack);
  
  // Pop elements
  void *data;
  pop(&stack, &data);
  printf("Pop: %i\n", *(int*)data);
  printStack(stack);
  
  // Delete Stack
  printf("Deleting stack...\n");
  deleteStack(&stack);
  printStack(stack);
  
  return 0;
}

// Create an empty stack (NULL), return success indication
bool createStack(Element **stack) {
  *stack = NULL;
  return true;
}

// Empty stack by removing all elements return success indication
bool deleteStack(Element **stack) {
  Element *next;
  while(*stack) {
    next = (*stack)->next;
    free(*stack);
    *stack = next;
  }
  return true;
}

// Push the element at the top of the Stack, indicates success or failure
bool push(Element **stack, void *data) {
  Element *top = malloc(sizeof(Element));
  if (!top) return false; // check if allocation was successful
  
  top->data = data;
  top->next = *stack;
  *stack = top;
  return true;
}

// Pop the top of the stack, indicates success or failure
bool pop(Element **stack, void **data) {
  
  // check for empty stack
  if (!*stack) return false;
  
  Element *curr = *stack;
  // *data = (*stack)->data;
  // *stack = (*stack)->next;
  *data = curr->data;
  *stack = curr->next;
  
  free(curr);
  
  return true;
  
}

// Display stack elements to console
void printStack(Element *stack) {
  Element *top = stack;
  
  printf("Stack: ");
  if(!top) {
    printf("Empty stack.");
  } else {
    while(top) {
      printf("\t%i", *(int *)(top->data)); // dereferencing a void pointer, with type cast
      top = top->next;
    }
  }
  printf("\n");
}