#include <stdio.h>
void displayQuick(int arr[], int size) {
  for (int i = 0; i <= size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pivot = arr[high];
    int pointer1 = low - 1;
    int pointer2 = low;
    while (pointer2 < high) {
      if (arr[pointer2] < pivot) {
        pointer1++;
        int temp = arr[pointer1];
        arr[pointer1] = arr[pointer2];
        arr[pointer2] = temp;
      }
      pointer2++;
    }
    int temp = arr[high];
    arr[high] = arr[pointer1 + 1];
    arr[pointer1 + 1] = temp;

    quickSort(arr, low, pointer1); // Left subarray
    quickSort(arr, pointer1 + 1, high);
  }
}

int main() {
  int arr[] = {210, 180, 1119, 10, 12, 9, 11};
  int size = sizeof(arr) / sizeof(int);
  quickSort(arr, 0, size - 1);
  displayQuick(arr, size - 1);
}
