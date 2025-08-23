#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;

int main() {
  puts("-----Digital Pyramid-----");
  u32 levels;
  puts("请输入金字塔的层数：");
  scanf_s("%" SCNu32, &levels);
  puts("数字金字塔图案如下：");
  for (u32 i = 1; i <= levels; i++) {
    // printf("%" PRIu32, i); // i --> 控制行号
    u32 space = levels - i;
    for (u32 j = 0; j <= space; j++) {
      printf("  "); // 输出空格
    }
    for (u32 k = 1; k <= i; k++) {
      printf("%" PRIu32 " ", k);
    }
    for (u32 l = i - 1; l >= 1; l--) {
      printf("%" PRIu32 " ", l);
    }
    printf("\n");
  }
  return 0;
}