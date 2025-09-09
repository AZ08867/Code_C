#include <stdio.h>
int main(void) {
  puts("ptr -> matrix[a][b]");
  int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};

  int (*ptr)[3] = matrix;
  // (*ptr)[3]: ptr是一个指针，它指向一个包含3个int元素的一维数组的指针

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      printf("%d ", ptr[i][j]);
    }
    puts("");
  }
  return 0;
}