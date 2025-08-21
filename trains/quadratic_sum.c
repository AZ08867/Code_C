#include "inttypes.h"
#include "stdint.h"
#include "stdio.h"

typedef uint32_t u32;
int main() {
  printf("Welcome to the quadratic sum example!\n");
  /*
  计算前 n 个自然数的平方和
  比如接受用户输入为3，则输出 1^2 + 2^2 + 3^2 = 14
  */
  u32 number;
  u32 sum_of_squares = 0;
  puts("Enter a number:");
  scanf_s("%" SCNu32, &number);
  for (u32 i = 1; i <= number; i++) {
    sum_of_squares += i * i;
  }
  printf("1^2 + ... + %" PRIu32 "^2 = %" PRIu32 "\n", number, sum_of_squares);
  return 0;
}