#include <iostream>

int main() {
  int arr[] = {4, 2, 5, 7, 1};
  int size = sizeof(arr) / sizeof(int);
  for (int counter = 1; counter < size; counter++) {
    int current = counter - 1;
    int lastElement = arr[counter];
    while (current >= 0 && arr[current] > lastElement) {
      arr[current + 1] = arr[current];
      current--;
    }
    arr[current + 1] = lastElement;
  }
  for (int iter = 0; iter < size; iter++) {
    std::cout << arr[iter] << '\t';
  }
  return 0;
}
