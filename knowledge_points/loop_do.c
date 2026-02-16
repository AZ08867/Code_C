#include "inttypes.h"
#include "stdint.h"
#include "stdio.h"
#include <stdlib.h>
#include <time.h>

#define TOTAL_LAPS 6
typedef uint32_t u32;

int main() {
  printf("do_while loop\n");
  /* 跑圈案例 */
  // u32 current_lap = 0;
  // do {
  //   current_lap++;
  //   printf("lap %" PRIu32 "\n", current_lap);
  // } while (current_lap < TOTAL_LAPS);

  // 生成随机数的猜数游戏案例
  u32 secret_number, guess;
  srand(time(NULL));
  // 生成1到100之间的随机数
  secret_number = rand() % 100 + 1;

  do {
    puts("请输入1到100之间的整数：");
    if (scanf_s("%" PRIu32, &guess) != 1 || guess < 0 || guess > 100) {
      puts("输入错误，请输入1到100之间的整数！");
      continue; // 如果输入错误，重新开始循环
    }

    if (guess == 0) {
      puts("游戏结束！");
      break; // 如果输入0，结束游戏
    } else if (guess < secret_number) {
      puts("猜小了，请再试一次！");
    } else if (guess > secret_number) {
      puts("猜大了，请再试一次！");
    } else {
      puts("恭喜你猜对了！");
    }
  } while (guess != secret_number);

  return 0;
}