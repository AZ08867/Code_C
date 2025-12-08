#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *ptr = (int *)malloc(sizeof(int));
  if (ptr == NULL) {
    printf("Memory allocation failed\n");
    return EXIT_FAILURE;
  }
  *ptr = 42;
  printf("Value at ptr: %d\n", *ptr);

  free(ptr);

  // 此时的ptr已经被释放，成为悬挂指针
  // 如果再访问则非常危险！！
  // printf("Value at ptr: %d\n", *ptr); // gcc and clang 都可以编译通过运行，只不过是随机数值（msvc会直接报错！）

  // 为了安全起见，将指针设置为NULL
  ptr = NULL;
  return EXIT_SUCCESS;
}
