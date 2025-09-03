#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;
u32 factorial(u32 n);
int main() {
  puts("Factorial Recursion Example");
  u32 number;
  puts("Enter a number:");
  scanf_s("%" SCNu32, &number);
  printf("%" PRIu32 "! = %" PRIu32 "\n", number, factorial(number));
  return 0;
}

u32 factorial(u32 n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}