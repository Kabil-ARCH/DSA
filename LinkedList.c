#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct playList {
  char song[50];
  struct playList *nextSong;
};

struct playList *createNode(char *song) {
  struct playList *node = (malloc(sizeof(struct playList)));
  strcpy(node->song, song);
  node->nextSong = NULL;
  return node;
}
void addSong(struct playList **LinkedList, char *song) {
  printf("%p", *LinkedList);
  printf("%p", LinkedList);
  struct playList *newNode = createNode(song);
  if (*LinkedList == NULL) {
    *LinkedList = newNode;
    printf("Head initialized successfully....");
  }
  struct playList *temp = *LinkedList;
}

int main() {
  struct playList *LinkedList = NULL;
  printf("%p\n", LinkedList);
  addSong(&LinkedList, "Yolo -> Kanguva\n");
  printf("%p\n", LinkedList);
  addSong(&LinkedList, "Mansilayo -> vetiyan\n");
  printf("%p", LinkedList);
  printf("\n");
}
