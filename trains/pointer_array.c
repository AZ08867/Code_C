#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef int32_t i32;
int main(void) {
  puts("pointer array case");

  i32 department1[] = {1001, 1002, 1003};
  i32 department2[] = {2001, 2002};
  i32 department3[] = {3001, 3002, 3003, 3004};

  i32 *department_ptrs[3] = {department1, department2, department3};

  size_t department_size[3] = {
      sizeof(department1) / sizeof(int),
      sizeof(department2) / sizeof(int),
      sizeof(department3) / sizeof(int),
  };

  for (size_t i = 0; i < 3; ++i) {
    printf("Department%zu: ", i + 1);
    for (size_t j = 0; j < department_size[i]; ++j) {
      printf("%" PRId32 " ", department_ptrs[i][j]);
    }
    puts("");
  }
  return 0;
}