#include <float.h>
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
  return 0;
}
