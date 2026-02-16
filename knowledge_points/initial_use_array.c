#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;
typedef uint8_t u8;
int main() {
  puts("initial use of array");
  u32 numbers[5] = {1, 3, 5, 7, 9};
  numbers[3] = 99;
  for (u8 i = 0; i < 5; i++) {
    printf("%" PRIu32 "\n", numbers[i]);
  }
  return 0;
}