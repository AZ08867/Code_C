#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;
typedef int32_t i32;
typedef uint8_t u8;

void printBinary(u8 num);

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

  // 按位运算

  // 左移n位相当于乘以2的n次方
  // 例如：左移2位相当于乘以4
  // 左移操作符是 <<，右移操作符是 >>
  // 按位与操作符是 &，按位或操作符是 |，按位异或操作符是 ^
  u8 num = 22; // 22 = 10110
  num <<= 2;   // 左移2位，变为 1011000
  printf("Left Shift: %" PRIu8 "\n", num);
  num >>= 3;
  printf("Right Shift: %" PRIu8 "\n", num);

  // 使用按位运算来实现变量的交换
  u32 a = 10, b = 20; // 10 = 1010; 20 = 10100
  printf("Before Swap: a = %" PRIu32 ", b = %" PRIu32 "\n", a, b);
  a ^= b;
  b ^= a;
  a ^= b;
  printf("After Swap: a = %" PRIu32 ", b = %" PRIu32 "\n", a, b);

  // 按位取反
  u8 status = 0b10101010; // 二进制表示
  printf("Original Status: ");
  printBinary(status);
  printf("\n");
  status = ~status; // 按位取反
  printf("After Inversion: ");
  printBinary(status);
  printf("\n");
  return 0;
}

void printBinary(u8 num) {
  for (int i = 7; i >= 0; i--) {
    printf("%d", (num >> i) & 1);
  }
}