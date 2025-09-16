#include <corecrt_math.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#define EMPLOYEES_COUNT 5
typedef uint32_t u32;

void update_salary(u32 *salaries, u32 increment);
void print_emp_info(u32 *salaries);
u32 calc_bonus(u32 salary);
u32 *find_highest_salary(const u32 *salaries);

int main(int argc, char *argv[]) {
  puts("pointer func case");

  /*
   *员工薪资管理系统
   * - 批量涨工资
   * - 计算并返回员工的年终奖
   * - 查找最高薪资的员工
   * */
  u32 salaries[EMPLOYEES_COUNT] = {3000, 4000, 5500, 4200, 3500};
  u32 increment = 10000;

  // update
  update_salary(salaries, increment);

  // print emp info
  print_emp_info(salaries);

  u32 *highest_salary = find_highest_salary(salaries);
  printf("The highest salary is %" PRIu32 "\n", *highest_salary);

  printf("最高薪资者的年终奖为: %" PRIu32 "\n", calc_bonus(*highest_salary));

  return 0;
}
void update_salary(u32 *salaries, u32 increment) {
  for (u32 i = 0; i < EMPLOYEES_COUNT; ++i) {
    salaries[i] += increment;
  }
}

void print_emp_info(u32 *salaries) {
  for (u32 i = 0; i < EMPLOYEES_COUNT; ++i) {
    printf("%" PRIu32 " ", salaries[i]);
  }
  puts("");
}

u32 calc_bonus(u32 salary) { return salary / 10; }

u32 *find_highest_salary(const u32 *salaries) {
  const u32 *highest = salaries;
  for (size_t i = 0; i < EMPLOYEES_COUNT; ++i) {
    if (salaries[i] > *highest) {
      highest = &salaries[i];
    }
  }
  return (u32 *)highest;
}
