#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

// 可变参数

/*
 * 计算平均数
 * @param num_args 参数的数量
 * @param ... 可变参数列表, 即要计算平均的数字
 * @return 平均数
 */

double average(int num_args, ...);
double average_float(double num_args, ...);
int main(void) {
  printf("Ave(2 3 4 5) = %f\n", average(4, 2, 3, 4, 5));
  printf("Ave(2.2 3.3 4.4 5.5) = %f\n", average_float(4.0, 2.2, 3.3, 4.4, 5.5));
  return 0;
}

double average(int num_args, ...) {
  va_list args;
  double sum = 0.0;

  // 初始化可变参数列表
  va_start(args, num_args);

  // 遍历所有参数并计算总和
  for (size_t i = 0; i < num_args; ++i) {
    sum += va_arg(args, int); // va_arg 获取下一个参数
  }

  // 清理可变参数列表
  va_end(args);

  // 返回平均值
  return num_args > 0 ? sum / num_args : 0;
}
double average_float(double num_args, ...) {
  va_list args;
  double sum = 0.0;

  // 初始化可变参数列表
  va_start(args, num_args);

  // 遍历所有参数并计算总和
  for (size_t i = 0; i < num_args; ++i) {
    sum += va_arg(args, double); // va_arg 获取下一个参数
  }

  // 清理可变参数列表
  va_end(args);

  // 返回平均值
  return num_args > 0 ? sum / num_args : 0;
}
