#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  puts("Dynamic memory allocation");

  int static_arr[5] = {1, 2, 3, 4, 5};
  puts("static_arr is");
  for (size_t i = 0; i < 5; ++i) {
    printf("%d ", static_arr[i]);
  }
  puts("");

  int *dynamic_arr = (int *)malloc(5 * sizeof(int));
  // void* 指针在c语言中用于泛型编程

  if (dynamic_arr == NULL) {
    perror("动态数组分配失败");
    exit(EXIT_FAILURE);
  }
  for (size_t i = 0; i < 5; i++) {
    dynamic_arr[i] = (i + 1) * 2;
  }
  puts("dynamic_arr is");
  for (size_t i = 0; i < 5; i++) {
    printf("%d ", dynamic_arr[i]);
  }
  free(dynamic_arr);
  return 0;
}
