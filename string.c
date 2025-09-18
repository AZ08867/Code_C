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

  return 0;
}
