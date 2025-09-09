#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef int32_t i32;
int main(void) {
  puts("Pointer case");
  i32 arrays[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

  i32 *ptr = arrays;
  size_t array_size = sizeof(arrays) / sizeof(arrays[0]);

  puts("Original array value is:");
  for (size_t i = 0; i < array_size; ++i) { // 使用 ++i 速度会更快一点
    printf("%" PRId32 " ", arrays[i]);
  }
  puts("");

  // 使用指针来增加数组的每个元素的值
  puts("Modified array value is:");
  for (size_t i = 0; i < array_size; ++i) {
    *(ptr + i) += 3;
    printf("%" PRId32 " ", *(ptr + i));
  }
  puts("");
  return 0;
}
