#include <ctype.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#define LETTER_COUNT 26

typedef uint32_t u32;
typedef uint8_t u8;

int main() {
  puts("Letter count statistics");

  u32 frequency[LETTER_COUNT] = {0};
  char text[] = "This is an example text lazy for frequency analysis.";

  // 统计每个字母出现的次数
  for (u8 i = 0; text[i] != '\0'; i++) {
    char ch = tolower(text[i]);
    if (ch >= 'a' && ch <= 'z') {
      frequency[ch - 'a']++; // 更新对应字母的频率
    }
  }
  puts("字母频率:");

  for (u8 i = 0; i < LETTER_COUNT; i++) {
    if (frequency[i] > 0) {
      printf("%c: %d\n", 'a' + i, frequency[i]);
    }
  }
  return 0;
}