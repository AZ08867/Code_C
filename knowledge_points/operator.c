#include <inttypes.h>
#include <stdbool.h>
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
  u8 status = 0b00001100; // 二进制表示
  printf("Original Status: ");
  printBinary(status);
  printf("\n");
  status = ~status; // 按位取反
  printf("After Inversion: ");
  printBinary(status);
  printf("\n");

  // 逻辑运算
  bool flag = true;
  bool result1 = flag && true;  // 逻辑与
  bool result2 = flag || false; // 逻辑或
  bool result3 = !flag;         // 逻辑非
  printf("Logical AND: %s\n", result1 ? "true" : "false");
  printf("Logical OR: %s\n", result2 ? "true" : "false");
  printf("Logical NOT: %s\n", result3 ? "true" : "false");

  // , 运算符, 只会使用最后一个表达式的值
  u8 x = 1, y = 2, z = 3;
  u8 result_value = (x += 1, y += 2, z += 3, 41); // 链式赋值
  printf("x = %" PRIu8 ", y = %" PRIu8 ", z = %" PRIu8 "\n", x, y, z);
  printf("Result Value: %" PRIu8 "\n", result_value);
  return 0;
}

void printBinary(u8 num) {
  for (int index = 7; index >= 0; index--) {
    printf("%d", (num >> index) & 1);
  }
}
