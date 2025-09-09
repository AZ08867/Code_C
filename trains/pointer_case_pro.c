#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef int32_t i32;
int main(void) {
  puts("数组的案例--使用指针查找特定元素的索引并返回");
  i32 values[] = {10, 20, 30, 40, 50};
  i32 *start_ptr = values;
  size_t values_size = sizeof(values) / sizeof(values[0]);

  i32 target_value = 30;
  i32 *target_ptr = NULL;

  size_t index = 0;
  bool found = false;

  for (size_t i = 0; i < values_size; ++i) {
    if (*(start_ptr + i) == target_value) {
      // 顺手保存目标的地址值
      target_ptr = start_ptr + i;
      // 找到目标的index
      index = i;
      found = true;
      break;
    }
  }
  if (found) {
    printf("element %" PRId32 " index is :%zu\n", target_value, index);
  } else {
    printf("element %" PRId32 " is not found\n", target_value);
  }
  return 0;
}