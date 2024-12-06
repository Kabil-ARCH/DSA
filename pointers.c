#include <stdio.h>
#include <stdlib.h>

struct ll {
  int data;
  struct ll *addOfNext;
};

struct ll *createNode(int data) {
  struct ll *node = malloc(sizeof(struct ll));
  node->data = data;
  node->addOfNext = NULL;
  return node;
}
void insertToLL(struct ll **head, int data) {
  struct ll *NewNode = createNode(data);
  if (*head == NULL) {
    *head = NewNode;
  } else {
    struct ll *temp = *head;
    while (temp->addOfNext != NULL) {
      temp = temp->addOfNext;
    }
    temp->addOfNext = NewNode;
  }
}
void printDataInLL(struct ll **head) {
  struct ll *temp = *head;
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    printf("%p ", temp);
    temp = temp->addOfNext;
  }
}
int main() {
  struct ll *head = NULL;
  insertToLL(&head, 10);
  insertToLL(&head, 20);
  insertToLL(&head, 30);
  printDataInLL(&head);
  printf("\n");
  return 0;
}
