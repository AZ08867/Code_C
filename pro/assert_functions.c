#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int findMaximum(int *arr, int length);
int main(void) {
  printf("This is a placeholder for assert_functions.c\n");
  int numbers[] = {3, 1, 4, 5, 7, 9, 8};
  int max = findMaximum(numbers, sizeof(numbers) / sizeof(numbers[0]));
  printf("The max element is %d\n", max);

  findMaximum(NULL, 0); // output: Assertion failed: arr != NULL && length > 0,
                        // file assert_functions.c, line 19

  return EXIT_SUCCESS;
}

// 在一个给定整数数组中寻找元素的最大值
int findMaximum(int *arr, int length) {
  assert(arr != NULL && length > 0);
  int max = arr[0];
  for (size_t i = 0; i < length; ++i) {

    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}