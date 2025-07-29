#include <float.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
  double num1 = 123.456;
  double num2 = 789.012;
  printf("%f + %f = %f\n", num1, num2, num1 + num2);
  printf("%f - %f = %f\n", num1, num2, num1 - num2);
  printf("%f * %f = %f\n", num1, num2, num1 * num2);
  printf("%f / %f = %f\n", num1, num2, num1 / num2);

  float floatNum = 1.0 / 3.0;
  double doubleNum = 1.0 / 3.0;
  long double longDoubleNum = 1.0 / 3.0;
  printf("Float division:           %.20f\n", floatNum);
  printf("Double division:          %.20f\n", doubleNum);
  printf("Long double division:     %.20Lf\n", longDoubleNum);

  printf("digits of precision for float: %d\n", FLT_DIG);
  printf("digits of precision for double: %d\n", DBL_DIG);
  printf("digits of precision for long double: %d\n", LDBL_DIG);

  // char
  char mychar = 'Q';
  printf("Character: %c\n", mychar);

  printf("%%?");
  //%%
  // 用于打印字面量%字符。由于%在printf中有特殊含义（用作格式说明符），所以需要%%来输出实际的%符号
  printf("\\?\n");

  // 转义序列
  printf("first line\n\tsecond line\n\t\tthird line\n");

  // 布尔类型
  // true == 1
  // false == 0

  bool is_game_over = true;
  if (is_game_over) {
    printf("Game Over\n");
  } else {
    printf("Game is still running\n");
  }
  return 0;
}
