#include <stdio.h>
#include <stdlib.h>

// 结构体中的指针成员 Pointer Members in Structs
// 访问成员变量需要使用箭头运算符（->）而不是点运算符（.）
// 这是因为指针变量存储的是结构体的地址，而不是结构体本身
int main() {
  struct Point {
    int x;
    int y;
  };

  struct Point p1 = {10, 20};
  struct Point *ptr = &p1;

  printf("Point p1: (%d, %d)\n", p1.x, p1.y);
  printf("Point via pointer: (%d, %d)\n", ptr->x, ptr->y);

  int n;
  printf("Input number:\n");
  scanf_s("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));
  if (arr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }

  for (int i = 0; i < n; ++i) {
    arr[i] = i + 1; // Initialize array with values 1 to n
  }

  puts("数组内容：");
  for (int i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);  // 释放内存
  arr = NULL; // 避免悬空指针
  return 0;
}