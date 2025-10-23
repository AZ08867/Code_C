#include <stdio.h>
#include <stdlib.h>

typedef void (*Callback)(int);

// 传递一个指向函数的指针
void traverseArray(int *array, int size, Callback callback);
void printElement(int element);
void doubleElement(int element);
void checkIfEven(int element);

int main(void) {
  int numbers[] = {1, 2, 3, 4, 5};
  int size = sizeof(numbers) / sizeof(numbers[0]);

  traverseArray(numbers, size, printElement);
  puts("---------------------------");
  traverseArray(numbers, size, doubleElement);
  puts("---------------------------");
  traverseArray(numbers, size, checkIfEven);

  return EXIT_SUCCESS;
}

void traverseArray(int *array, int size, Callback callback) {
  for (int i = 0; i < size; ++i) {
    callback(array[i]);
  }
}

void printElement(int element) { printf("%d\n", element); }
void doubleElement(int element) {
  printf("%d * 2 = %d\n", element, element * 2);
}
void checkIfEven(int element) {
  if (element % 2 == 0) {
    printf("%d is even number\n", element);
  } else {
    printf("%d is odd number\n", element);
  }
}