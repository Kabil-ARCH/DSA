#include <stdio.h>

int main() {
  int arr[] = {1, 3, 2, 4, 10, 6, 12};
  int size = sizeof(arr) / sizeof(int);

  for (int startPointer = 0; startPointer < size; startPointer++) {
    int largestElementIndex = startPointer;
    int iter = startPointer + 1;
    while (iter < size) {
      if (arr[largestElementIndex] > arr[iter]) {
        largestElementIndex = iter;
      }
      iter++;
    }

    if (largestElementIndex != startPointer) {
      int temp = arr[largestElementIndex];
      arr[largestElementIndex] = arr[startPointer];
      arr[startPointer] = temp;
    }
  }
  for (int index = 0; index < size; index++) {
    printf("%d ", arr[index]);
  }
  return 0;
}
