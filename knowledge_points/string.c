#include <stdio.h>
#include <string.h>

int main(void) {
  puts("Welcome string!");

  const char arr[] = {"Hello"};
  // 'H' 'e' 'l' 'l' 'o' '\0'
  printf("%s\n", arr);

  /// strcpy_s usage
  const char src[] = {"halo"};
  char dest[50];
  strcpy_s(dest, sizeof(dest), src);
  printf("%s\n", dest);

  /// strlen usage
  char str[] = {"String"};
  printf("%zd\n", strlen(str));

  /// strcat_s usage
  char first[50] = "nihao";
  const char *two = ", world\n";
  rsize_t dest_size = sizeof(first) - strlen(first) - 1;
  strcat_s(first, dest_size, two);
  printf("%s", first);

  /// sprintf_s usage
  char buffer[50] = {0};
  int number = 3;
  double pi = 3.14159265354;
  int ret = sprintf_s(buffer, sizeof(buffer), "Integer: %d, Double: %.5f",
                      number, pi);
  if (ret > 0) {
    printf("Formatted string: %s\n", buffer);
  } else {
    printf("Error Formatting string");
  }

  return 0;
}
