#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
  double input_angle_degress = 0.0;
  double input_angle_radians = 0.0;
  double sin_value = 0.0;
  double cos_value = 0.0;
  double tan_value = 0.0;


  scanf_s("%lf", &input_angle_degress);

  // 将角度转换为弧度
  input_angle_degress = input_angle_degress * (M_PI / 180.0);

  // 计算三角函数值
  sin_value = sin(input_angle_degress);
  cos_value = cos(input_angle_degress);
  tan_value = tan(input_angle_degress);

  printf("The sine of %.2f degress is: %.2f", input_angle_degress, sin_value);
  return 0;
}
