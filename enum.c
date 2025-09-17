/// Enumeration
#include <stdio.h>
int main(int argc, char *argv[]) {
  typedef enum {
    MONDAY, // 0 TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FARIDAY,
    SATURDAY,
    SUNDAY
  } Weekday;

  printf("%d", MONDAY);
  return 0;
}
