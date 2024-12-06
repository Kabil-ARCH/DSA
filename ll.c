#include <stdio.h>
#include <stdlib.h>
struct LinkedList {
  char *data;
  struct LinkedList *next;
};

struct LinkedList *createNode(char *song) {
  struct LinkedList *newNode =
      (struct LinkedList *)(malloc(sizeof(struct LinkedList)));
  newNode->data = song;
  newNode->next = NULL;
  return newNode;
}
void initLinkedList(struct LinkedList **ll, char *song) {
  struct LinkedList *NewNode = createNode(song);
  if (*ll == NULL) {
    *ll = NewNode;
  } else {
    struct LinkedList *temp = *ll;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = NewNode;
  }
}
void displayLinkedList(struct LinkedList *node) {
  struct LinkedList *temp = node;
  while (temp != NULL) {
    printf("%s", temp->data);
    temp = temp->next;
  }
}
int main() {
  struct LinkedList *ll = NULL;
  initLinkedList(&ll, "Kanguva\n");
  initLinkedList(&ll, "Syriya's saturday\n");
  displayLinkedList(ll);
  return 0;
}
