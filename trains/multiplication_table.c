#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;

int main() {
  puts("-----Multiplication Table-----");
  u32 num;
  puts("Enter a number: ");
  scanf_s("%" SCNu32, &num);
  for (u32 i = 1; i <= num; i++) {
    for (u32 j = 1; j <= i; j++) {
      printf("%" PRIu32 " * %" PRIu32 "= %" PRIu32 "\t", j, i, i * j);
    }
    printf("\n");
  }
  return 0;
}