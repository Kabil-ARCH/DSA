#include <stdio.h>
#include <stdlib.h>
struct queue {
  int queueItems[100];
  int front;
  int rear;
};

void enque(struct queue *que, int data) {
  if (que->front == -1) {
    que->front++;
  }
  que->rear++;
  que->queueItems[que->rear] = data;
  printf("Inserted data: %d\n", que->queueItems[que->rear]);
}

void deque(struct queue *que) {
  printf("Deleted element :%d\n", que->queueItems[que->front]);
  que->front++;
}

void displayQueue(struct queue *que) {
  int temp = que->front;
  for (; temp <= que->rear; temp++) {
    printf("%d", que->queueItems[temp]);
    if (temp < que->rear)
      printf("->");
  }
}

int main() {
  struct queue *que = (struct queue *)malloc(sizeof(struct queue));
  que->rear = que->front = -1;
  enque(que, 10);
  enque(que, 20);
  enque(que, 30);
  enque(que, 40);
  deque(que);
  deque(que);
  displayQueue(que);
  printf("\n");
  return 0;
}
