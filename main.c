#include "stdint.h"
#include "stdio.h"
#include <float.h>
#include <inttypes.h>
#include <stdint.h>

int main() {
  // printf("Please enter a number: ");
  // int number;
  // scanf_s("%d", &number);
  // printf("You entered: %d\n", number);

  /*无符号数值类型的用法*/
  // unsigned int age = 25;
  // printf("My age is %u\n", age);

  // x, y positions
  // unsigned short x = 100, y = 200;
  // printf("Position: (%hu, %hu)\n", x, y);

  /* sizeof的用法 */
  // printf("Size of short: %zu bytes\n", sizeof(short));
  // printf("Size of unsigned short: %zu bytes\n", sizeof(unsigned short));
  // printf("Size of int: %zu bytes\n", sizeof(int));
  // printf("Size of unsigned int: %zu bytes\n", sizeof(unsigned int));
  // printf("Size of long: %zu bytes\n", sizeof(long));

  // int16_t my_int_16 = 127;
  // printf("my int 16: %d\n", my_int_16);

  // 正常输出固定整数类型的方法
  /*
  int32_t my_int_32 = INT32_MAX;
  uint32_t my_uint_32 = UINT32_MAX;
  uint64_t my_uint_64 = UINT64_MAX;
  printf("my int 32: %" PRId32 "\n", my_int_32);
  printf("my uint 32: %" PRIu32 "\n", my_uint_32);
  printf("my uint 64: %" PRIu64 "\n", my_uint_64);
  */

  // 关于浮点数，如果是存储的重要性大于精度则使用 float，否则使用 double
  /*
  float temperature = 36.6f;
  float humidity = 45.5f;
  float speed_of_sound = 343.5e2f;
  float length = 12.34f, width = 56.78f, height = 90.12f;

  printf("Temperature: %.1f\n", temperature);
  printf("Humidity: %.1f\n", humidity);
  printf("Speed of Sound: %.1f\n", speed_of_sound);
  printf("Length: %.2f\n", length);
  printf("Width: %.2f\n", width);
  printf("Height: %.2f\n", height);
  */

  // 浮点数输出
  float num = 123.456f;
  printf("Using %%f: %f\n", num);
  printf("Using %%e: %e\n", num);
  printf("Using %%E: %E\n", num);
  printf("Using %%a: %a\n", num);
  printf("Using %%A: %A\n", num);

  // 浮点数溢出
  float max_float = FLT_MAX;
  float min_float = FLT_MIN;
  float overflow = FLT_MAX * 100.0f;
  float underflow = FLT_MIN / 100.0f;
  printf("Max Float: %e\n", max_float);
  printf("Min Float: %e\n", min_float);
  printf("Overflow: %e\n", overflow);
  printf("Underflow: %e\n", underflow);
  return 0;
}