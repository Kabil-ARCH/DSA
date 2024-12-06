#include <stdio.h>
int main() {
  int arr[] = {1, 4, 2, 5, 3, 18, 11, 14};
  int size = sizeof(arr) / sizeof(int);

  for (int iter = 0; iter < size; iter++) {
    int lastElement = arr[iter];
    int checker = iter - 1;
    while (checker >= 0 && arr[checker] > lastElement) {
      if (lastElement < arr[checker]) {
        arr[checker + 1] = arr[checker];
        checker--;
      }
      arr[checker + 1] = lastElement;
    }
    for (int index = 0; index < size; index++) {
      printf("%d", arr[index]);
      if (index < size - 1) {
        printf("->");
      }
    }
    return 0;
  }
}
