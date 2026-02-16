#include <stdint.h>
#include <stdio.h>
typedef uint32_t u32;
typedef int32_t i32;
int main() {
  /*
  计算求和的案例 -- 升级版 (可以输入负数，但不计入总和)
  用户从终端输入一系列数字，用回车隔开，直到用户输入一个单个的 0
  作为结束，然后把之前的所有数都相加，输出最终的计算结果。
  */
  printf("Welcome to the addition calculator!\n");
  u32 sum = 0;
  i32 num;
  while (1) {
    printf("请输入一个数字 (输入 0 结束): ");
    scanf_s("%d", &num);
    if (num == 0) {
      break;
    }
    if (num < 0) {
      printf("负数 %d 不计入总和。\n", num);
      continue; // 跳过负数，不计入总和
    }
    if (num > 0) {
      sum += num;
    }
  }
  printf("最终的计算结果是: %d\n", sum);
  return 0;
}