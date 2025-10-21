#include <stdint.h>
#include <stdio.h>
typedef int32_t i32;
typedef i32 (*operation_t)(i32, i32);

i32 add(i32 a, i32 b);
i32 subtract(i32 a, i32 b);
i32 multiply(i32 a, i32 b);
i32 divide(i32 a, i32 b);

operation_t operation[4] = {add, subtract, multiply, divide};
int main(void) {
  i32 a = 10, b = 5;
  i32 result = 0;

  result = operation[0](a, b);
  printf("%d\n", result);

  result = operation[1](a, b);
  printf("%d\n", result);

  result = operation[2](a, b);
  printf("%d\n", result);

  result = operation[3](a, b);
  printf("%d\n", result);

  return 0;
}
i32 add(i32 a, i32 b) { return a + b; }
i32 subtract(i32 a, i32 b) { return a - b; }
i32 multiply(i32 a, i32 b) { return a * b; }
i32 divide(i32 a, i32 b) {
  if (b == 0) {
    puts("Error: Divide by z");
    return 0;
  }
  return a / b;
}