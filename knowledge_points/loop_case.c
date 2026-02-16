#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;
int main() {
  /*
  计算求和的案例
  用户从终端输入一系列数字，用回车隔开，直到用户输入一个单个的 0
  作为结束，然后把之前的所有数都相加，输出最终的计算结果。
  */
  printf("Welcome to the addition calculator!\n");
  u32 sum = 0; // 初始化和为 0
  u32 num;     // 输入的数字
  while (1) {
    puts("请输入一个数字 (输入 0 结束): ");
    scanf_s("%" PRIu32, &num);
    if (num == 0) {
      break;
    }
    sum += num;
  }
  printf("最终的计算结果是: %" PRIu32, sum);
  return 0;
}