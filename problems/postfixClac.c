#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
  int numbers[100];
  int top;
};

void push(int digit, struct stack *postfix) {
  postfix->top++;
  postfix->numbers[postfix->top] = digit;
}

int pop(struct stack *postfix) {
  int ret = postfix->numbers[postfix->top];
  postfix->top--;
  return ret;
}
int main() {
  struct stack *postfix = (struct stack *)(malloc(sizeof(struct stack)));
  postfix->top = -1;
  char *string;
  scanf("%s", string);
  for (int i = 0; i < sizeof(string); i++) {
    if (isdigit(string[i]))
      push(string[i] - '0', postfix);
    else {
      int dig1 = pop(postfix);
      int dig2 = pop(postfix);
      switch (string[i]) {
      case '+':
        push(dig2 + dig1, postfix);
        break;
      case '-':
        push(dig2 - dig1, postfix);
        break;
      case '*':
        push(dig2 * dig1, postfix);
        break;
      case '/':
        push(dig2 / dig1, postfix);
        break;
      }
    }
  }
  printf("%d\n", postfix->numbers[0]);
}
