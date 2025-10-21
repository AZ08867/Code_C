#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
void printBudgets(double *budgets, int size);
int main(int argc, char *argv[]) {
  /// 动态调整部门预算列表
  int size = 3; // 初始的预算项数

  double *budgets = (double *)malloc(size * sizeof(double));
  if (budgets == NULL) {
    perror("Failed to allocate initial bufgets");
    return EXIT_FAILURE;
  }

  // 假设的初始预算分配
  budgets[0] = 10000;
  budgets[1] = 15000;
  budgets[2] = 12000;

  printBudgets(budgets, size);

  // 新的一年需要增加预算项
  int newSize = 5;
  double *newBudgets = (double *)realloc(budgets, newSize * sizeof(double));

  if (budgets == NULL) {
    perror("Failed to realloc bufgets");
    free(budgets);
    return EXIT_FAILURE;
  }

  budgets = newBudgets; // 更新指针
  budgets[3] = 18000;
  budgets[4] = 12500;

  printBudgets(budgets, newSize);
  free(budgets);

  return EXIT_SUCCESS;
}
void printBudgets(double *budgets, int size) {
  puts("Current budgets:");
  for (size_t i = 0; i < size; i++) {
    printf("Department %zd: $%.2f; ", i + 1, budgets[i]);
  }
  puts("");
}
