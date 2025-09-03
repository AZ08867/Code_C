#include <stdbool.h>
#include <stdio.h>

#define MONTH_COUNT 12
int get_days_in_month(int month, int year);
bool is_leap_year(int year);
int main(void) {
  puts("表驱动法");
  int res_days = get_days_in_month(2, 2025);
  printf("%d\n", res_days);
  return 0;
}
bool is_leap_year(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int get_days_in_month(int month, int year) {
  const int days_in_months[MONTH_COUNT] = {
      31, is_leap_year(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return days_in_months[month - 1];
}