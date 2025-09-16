/// Passing by Value
#include <inttypes.h>
#include <stdio.h>

typedef int32_t i32;
void add_ten_by_value(i32 value);
void add_ten_by_reference(i32 *value);

int main(void) {
  puts("函数的值传递");
  i32 my_value = 5;
  printf("Original value is %" PRId32 "\n", my_value);

  add_ten_by_value(my_value);
  printf("Pass by value also is %" PRId32 "\n", my_value);

  /// Passing by Reference
  puts("函数的地址引用传递");
  add_ten_by_reference(&my_value);
  printf("Pass by reference is %" PRId32 "\n", my_value);

  return 0;
}

void add_ten_by_value(i32 value) {
  value += 10;
  printf("%" PRId32 "\n", value);
}
void add_ten_by_reference(i32 *value) { *value += 10; }