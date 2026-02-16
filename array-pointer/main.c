#include <stdio.h>
#define ROWS 3
#define COLS 4

void printMatrix(int cols, int (*matrix)[cols], int rows);

void flip_image(int image[ROWS][COLS], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols / 2; j++) {
      int temp = image[i][j];
      image[i][j] = image[i][cols - j - 1];
      image[i][cols - j - 1] = temp;
    }
  }
}

int main(void) {
  int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

  int (*ptr)[3] = arr; // ptr is a pointer to an array of 3 integers, ptr
                       // 指向二维数组的第一行
  // 数组指针 pointer to array
  printf("%d\n", (*ptr)[1]);

  ptr++; // ptr now points to the second row of the array
  printf("%d\n", (*ptr)[1]);

  puts("----------------------");
  printMatrix(3, arr, 2);

  puts("----------------------");
  int array[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  printMatrix(4, array, 3);
  puts("----------------------");
  flip_image(array, 3, 4);
  printMatrix(4, array, 3);
  return 0;
}

void printMatrix(int cols, int (*matrix)[cols], int rows) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}