#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <windows.h>
#define TOTAL_STEPS 100

typedef uint32_t u32;

int main() {
  puts("Progress Bar");
  puts("处理中...");
  for (u32 i = 0; i <= TOTAL_STEPS; i++) {
    printf("\r[");
    // 打印进度条的完整部分
    for (u32 j = 1; j < i; j++) {
      printf("#");
    }
    for (u32 k = i; k < TOTAL_STEPS; k++) {
      printf(" ");
    }
    printf("] %" PRIu32 "%%", (i * 100) / TOTAL_STEPS);
    Sleep(100);
  }
  puts("\n处理完成");
  return 0;
}