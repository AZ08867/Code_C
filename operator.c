#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;
typedef int32_t i32;
int main() {
  u32 apple = 5;
  u32 orange = 10;
  u32 total = apple + orange;
  printf("Total: %" PRIu32 "\n", total);

  i32 number = 3;
  printf("Origin Number: %" PRIi32 "\n", number);

  i32 result = number++; // 后缀递增，先赋值再加1
  printf("Result: %" PRIi32 "\n", result);
  printf("Before Number: %" PRIi32 "\n", number);

  i32 res = ++number; // 前缀递增，先加1再赋值
  printf("Res: %" PRIi32 "\n", res);
  printf("After Number: %" PRIi32 "\n", number);

  return 0;
}