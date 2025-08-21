#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;
int main() {
  u32 number;
  puts("Enter a number:");
  scanf_s("%" SCNu32, &number);

  u32 factorial = 1;
  for (u32 i = 1; i <= number; i++) {
    factorial *= i;
  }
  printf("%" PRIu32 "! = %" PRIu32 "\n", number, factorial);
  return 0;
}