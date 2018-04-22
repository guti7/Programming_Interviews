/*
* Implementation of a Singly Linked List for Int
*
* Programming Interviews Exposed, 3rd, Mongan, Giguere, Kindler
* Created by @guti7 on April 15 2018
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Element/Node
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Prototypes
bool insertAtFront(Node **head, int data);
Node *find(Node *head, int data);
bool deleteNode(Node **head, Node *nodeToDelete);
bool insertNode(Node **head, int elemToInsert, int index);
void deleteList(Node **head);
void printList(Node *head);

// Handle a singly linked list(SLL)
int main(void) {
  
  // LL head
  Node *head = malloc(sizeof(Node));
  head->data = 1;
  head->next = NULL;
  
  printf("IntLinkedList head: %i, next: %c\n", head->data, head->next? head->next->data + '0':'n');
  
  // Add mode nodes
  Node *node1 = malloc(sizeof(Node));
  node1->data = 2;
  node1->next = NULL;
  
  Node *node2 = malloc(sizeof(Node));
  node2->data = 3;
  node2->next = NULL;
  
  head->next = node1;
  head->next->next = node2;
  
  printf("\nInsert in front:\n");
  insertAtFront(&head, 0);
  
  printf("Print list:\n");
  printList(head);
  
  printf("\nFind: 5\n");
  Node *element = find(head, 5);
  
  if (element) {
    printf("IntLinkedList node: %i, next: %c\n", element->data, element->next? element->next->data + '0':'n');
  } else {
    printf("item not found.\n");
  }
  
  printf("\nFind: 3\n");
  element = find(head, 3);
  
  if (element) {
    printf("Found node: %i, next: %c\n", element->data, element->next? element->next->data + '0':'n');
  } else {
    printf("item not found.\n");
  }
  
  printf("\nFind: 0\n");
  element = find(head, 0);
  
  if (element) {
    printf("Found node: %i, next: %c\n", element->data, element->next? element->next->data + '0':'n');
  } else {
    printf("Item not found.\n");
  }
  
  printf("\nFind: 2\n");
  element = find(head, 2);
  
  if (element) {
    printf("Found node: %i, next: %c\n", element->data, element->next? element->next->data + '0':'n');
  } else {
    printf("item not found.\n");
  }
  
  printf("\nPrint list:\n");
  printList(head);
  
  // printf("\nDelete head...");
  // deleteNode(&head, head);
  printf("\nDelete node...");
  deleteNode(&head, element);
  
  printf("\nPrint list:\n");
  printList(head);
  
  printf("\nInsert data...\n: (%i, 2), (%i, 0), (%i, 5), (%i, 30)", 5, 9, 20, 30);
  insertNode(&head, 5, 2);
  insertNode(&head, 9, 0);
  insertNode(&head, 20, 5);
  insertNode(&head, 30, 30);
  
  printf("\nPrint list:\n");
  printList(head);
  
  printf("\ndelete list...\n");
  deleteList(&head);
  printf("list: ");
  printList(head);
}


// Delete list, pay attention to freeing allocated memory.
// No garbage collection in C
void deleteList( Node **head) {
  Node *current = *head;
  
  while(current) {
    Node *next = current->next;
    free(current);
    current = next;
  }
  
  *head = NULL;
}

// Insert element at the beggining of the LL
bool insertAtFront(Node **head, int data) {
  Node *newElem = malloc(sizeof(Node));
  
  // Check if memory was successfully allocated
  if (!newElem) {
    return false;
  }
  
  newElem->data = data;
  newElem->next = *head;
  
  *head = newElem;
  return true;
}

// Find the item in the list, null if not found
// Caller must detect error condition by checking for a null return
// Alternatively, consider throwing an exception when an element is not found
Node *find(Node *head, int data) {
  Node *current = head;
  
  // Always test for the end of a list(NULL) as you traverse it
  while(current && current->data != data){
    current = current->next;
  }
  return current;
}

// Delete given node from the list, true if successful, false otherwise
bool deleteNode(Node **head, Node *nodeToDelete) {
  
  // Check for NULL arguments
  if (!head || !*head || !nodeToDelete) {
    return false;
  }
  
  Node *current = *head;
  // check if the node to delete is the head
  if (*head == nodeToDelete) {
    *head = current->next;
    free(nodeToDelete);
    return true;
  }

  // traverse the list checking ->next instead of current
  while(current) {
    if (current->next == nodeToDelete){
      
      // Update pointers
      current->next = current->next->next;
      free(nodeToDelete);
      return true;
    }
    current = current->next;
  }
  
  // Traversed complete list without finding nodeToDelete
  return false;
}

// Insertion(Deletion) require a pointer to the element immemdiately preceding
// the insertion(Delection) location
bool insertNode(Node **head, int elemToInsert, int index) {
  // check for null pointers
  if (!head || !*head) {
    return false;
  }
  // validate index
  if (index < 0) {
    return false;
  }

  // insert in middle, (insert at end is same as middle but with no next elem)
  Node *newElem = malloc(sizeof(Node));
  // Check if memory was successfully allocated
  if (!newElem) {
    return false;
  }
  
  Node *current = *head;
  // Find position to insert
  int i = 0;
  while (i < index - 1 && current) {
    current = current->next;
    i += 1;
  }
  
  if (i < index - 1) {
    printf("\nIndex is out of bounds: %i\n", index);
    return false; 
  }
  
  newElem->data = elemToInsert;
  
  if (index == 0) {
    newElem->next = current;
    *head = newElem;
  } else {
    newElem->next = current->next;
    current->next = newElem;
  }
  
  return true;
}

void printList(Node *head) {
  Node *current = head;
  
  while (current != NULL) {
    printf(" %d,", current->data);
    current = current->next;
  }
  printf("\n");
}
