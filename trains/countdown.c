#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <windows.h>

typedef uint32_t u32;
int main() {
  /*用户输入一个数， 将从这个数倒数到1结束*/
  u32 start_number;
  puts("Enter a number");
  scanf_s(" %" SCNu32, &start_number);
  puts("let's count down:");
  for (u32 i = start_number; i > 0; i--) {
    printf("%" PRIu32 "\n", i);
    Sleep(500); // 单位是毫秒
  };
  puts("Count down is over!");
  return 0;
}