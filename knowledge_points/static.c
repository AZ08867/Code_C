#include <stdio.h>
void increment_counter(void);
int main(void) {
  puts("Static Variables");
  for (int i = 0; i < 5; i++) {
    increment_counter();
  }
  return 0;
}
void increment_counter(void) {
  static int counter = 0;
  counter++;
  printf("%d\n", counter);
}
