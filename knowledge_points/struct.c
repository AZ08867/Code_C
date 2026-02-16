/// Struct
#include <stdio.h>

// 这里定义了一个表示日期的结构体 Date
// 整个结构体包含了三个int类型的成员
typedef struct Date {
  int day;
  int month;
  int year;
} Date;

int main(int argc, char *argv[]) {
  puts("Structures");
  Date today = {17, 9, 2025};

  // 通过 点 来访问结构体成员
  printf("Today is %d-%d-%d\n", today.year, today.month, today.day);

  // 通过指针来访问,则采用 -> 的方式
  Date *date_ptr = &today;
  printf("Accessed via pointer, Today is %d-%d-%d\n", date_ptr->year,
         date_ptr->month, date_ptr->day);

  return 0;
}
