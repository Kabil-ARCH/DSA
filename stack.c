#include <stdio.h>
#include <stdlib.h>

struct stack {
  int stackArray[100];
  int counter;
};

void push(struct stack *stk, int data) {

  stk->counter++;
  stk->stackArray[stk->counter] = data;
  printf("%d", stk->stackArray[stk->counter]);
}
int main() {
  struct stack *stk = (struct stack *)malloc(sizeof(struct stack));
  stk->counter = -1;
  int data;
  scanf("%d", &data);
  push(stk, data);
  return 0;
}
