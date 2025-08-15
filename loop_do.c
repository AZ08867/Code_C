#include "inttypes.h"
#include "stdint.h"
#include "stdio.h"

#define TOTAL_LAPS 6
typedef uint32_t u32;

int main() {
  printf("do_while loop\n");
  u32 current_lap = 0;
  do {
    current_lap++;
    printf("lap %" PRIu32 "\n", current_lap);
  } while (current_lap < TOTAL_LAPS);
  return 0;
}