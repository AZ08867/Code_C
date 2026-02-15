#include <stdio.h>
#include <stdlib.h>

// C语言函数参数中的数组传递

void printArray(const int *arr, int size);
int main(int argc, char *argv[]) {
  int number[] = {1, 2, 3, 4, 5};
  printArray(number, sizeof(number) / sizeof(number[0]));
  return EXIT_SUCCESS;
}

void printArray(const int *arr, int size) {
  for (int index = 0; index < size; ++index) {
    printf("%d ", arr[index]);
  }
  puts("");
}
