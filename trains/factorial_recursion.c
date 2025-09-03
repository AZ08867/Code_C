#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;
u32 factorial(u32 n, u32 acc);
int main(void) {
  puts("Factorial Recursion Example");
  u32 number;
  puts("Enter a number:");
  scanf_s("%" SCNu32, &number);
  printf("%" PRIu32 "! = %" PRIu32 "\n", number, factorial(number, 1));
  return 0;
}

u32 factorial(u32 n, u32 acc) {
  if (n == 0) {
    return acc;
  } else {
    return factorial(n - 1, n * acc);
  }
}