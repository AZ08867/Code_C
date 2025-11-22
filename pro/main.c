#include "math_operations.h"
#include <stdio.h>

int main(void) {
  int result = add(3, 42);
  printf("3 + 42 = %d\n", result);

  int res = multiply(12, 3);
  printf("12 * 12 = %d\n", res);
  return 0;
}