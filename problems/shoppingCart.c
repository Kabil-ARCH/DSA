#include <stdio.h>
#include <stdlib.h>
struct stackOfPuchaseItems {
  char *item;
  int price;
  struct stackOfPuchaseItems *next;
};

struct stackOfPuchaseItems *createItem(char *item, int price) {
  struct stackOfPuchaseItems *newNode = (struct stackOfPuchaseItems *)(malloc(
      sizeof(struct stackOfPuchaseItems)));
  newNode->item = item;
  newNode->price = price;
  newNode->next = NULL;
  return newNode;
}
void push(struct stackOfPuchaseItems **cart, char *item, int price) {
  struct stackOfPuchaseItems *newItem = createItem(item, price);
  newItem->next = *cart;
  *cart = newItem;
}
void displayCart(struct stackOfPuchaseItems *cart) {
  struct stackOfPuchaseItems *display = cart;
  while (display != NULL) {
    printf("%s : RS.%d", display->item, display->price);
    display = display->next;
  }
  free(display);
}
void pop(struct stackOfPuchaseItems **cart) { printf("%s\n", (*cart)->item); }
int main() {
  struct stackOfPuchaseItems *cart = NULL;
  push(&cart, "pen", 20);
  push(&cart, "pencil", 20);
  pop(&cart);
  displayCart(cart);
  return 0;
}
