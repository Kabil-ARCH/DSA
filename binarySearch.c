#include <stdio.h>

int BinarySearch(int arr[], int start, int last, int target) {

  int middle = (last + start) / 2;

  if (start > last) {
    return -1; // Target not found
  }
  if (arr[middle] == target) {
    return middle;
  } else if (arr[middle] < target) {
    start = middle + 1;
    return BinarySearch(arr, start, last, target);
  } else {
    last = middle - 1;
    return BinarySearch(arr, start, last, target);
  }
}
int main() {
  int arr[] = {1, 2, 3, 4, 5, 6};
  int start = 0;
  int last = sizeof(arr) / sizeof(int) - 1;
  int result = BinarySearch(arr, 0, last, 4);
  printf("%d : %d\n", result, arr[result]);
  return 0;
}
