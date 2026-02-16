#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
typedef uint32_t u32;

int main() {
  printf("Welcome to the for loop example!\n");
  const u32 total_laps = 7;
  for (u32 current_lap = 1; current_lap <= total_laps; current_lap++) {
    printf("第 %" PRIu32 " 圈，你已经跑了 %" PRIu32 " 米！\n", current_lap,
           current_lap * 400);
  }
  return 0;
}