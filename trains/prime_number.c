#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;

int main() {
  printf("This case is prime number check\n");
  u32 num;
  bool is_prime = true;
  puts("Enter a positive integer: ");
  if (scanf_s("%" SCNu32, &num) != 1 || num < 2) {
    puts("Invalid input. Please enter a positive integer greater than or equal "
         "to 2.");
    return 1;
  }

  if (num == 2) {
    is_prime = true;
  } else {
    for (u32 i = 3; i <= sqrt(num); i += 2) {
      if (num % i == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime) {
      printf("%" PRIu32 " is a prime number\n", num);
    } else {
      printf("%" PRIu32 " is not a prime number\n", num);
    }
    return 0;
  }
}