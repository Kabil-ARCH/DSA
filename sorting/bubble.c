#include <stdio.h>

int main() {
  int arr[] = {12, 2, 4, 3, 5, 7};
  int size = sizeof(arr) / sizeof(int);
  for (int outer = 0; outer < size; outer++) {
    for (int inner = 0; inner < size - 1; inner++) {
      if (arr[inner] > arr[inner + 1]) {
        int temp = arr[inner];
        arr[inner] = arr[inner + 1];
        arr[inner + 1] = temp;
      }
    }

    for (int i = 0; i < size; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
  }
}
