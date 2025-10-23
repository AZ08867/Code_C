/// Enumeration
#include <stdio.h>
int main(int argc, char *argv[]) {
  typedef enum {
    MONDAY, // 0 TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
  } Weekday;

  // printf("%d", MONDAY);
  printf("%d", SUNDAY);
  return 0;
}
