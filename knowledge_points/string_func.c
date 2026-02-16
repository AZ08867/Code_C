#include <stddef.h>
#include <stdio.h>
#include <string.h>
int main(void) {
  char dest[20];
  const char *src = "Hello, world\n";
  size_t max_copy = 10;
  errno_t result = strncpy_s(dest, sizeof(dest), src, max_copy);

  if (result == 0) {
    printf("Copied string: %s\n", dest);
  } else {
    printf("Error!");
  }

  /// strncat_s
  char d[20] = "Hello";
  const char *s = ", world\n";
  strncat_s(d, sizeof(d) - strlen(d) - 1, s, 3);

  printf("Catted string: %s\n", d);

  /// gets_s
  /* char buffer[100]; */
  /* printf("Enter a string: "); */
  /* if (gets_s(buffer, sizeof(buffer)) == NULL) { */
  /*   printf("Error or end of file encountered.\n"); */
  /* } else { */
  /*   printf("you entered: %s\n", buffer); */
  /* } */

  /// strtok_s
  /// 按照要求分解字符串
  char str[] = "This is a sample string";
  char delim[] = " ";
  char *token;
  char *context;

  token = strtok_s(str, delim, &context);
  while (token != NULL) {
    printf("Token: %s\n", token);
    token = strtok_s(NULL, delim, &context);
  }

  /// strcmp and strncmp

  const char *str1 = "people";
  const char *str2 = "people";
  const char *str3 = "person";

  size_t num = 2; // 比较前2个字符

  if (strncmp(str1, str3, num) == 0) {
    printf("The first %zu characters of %s and %s are equal\n", num, str1,
           str3);
  } else {
    printf("The first %zu characters of %s and %s are not equal\n", num, str1,
           str3);
  }
  if (strcmp(str1, str2) == 0) {
    printf("%s and %s are equal\n", str1, str2);
  } else {
    printf("%s and %s are not equal\n", str1, str2);
  }

  /// strchr and strrchr
  const char *st = "Hello, www.bing.com";
  char to_find = 'w';
  char *ptr_char = strchr(st, to_find);

  char *ptr_reverse_char = strrchr(st, to_find);
  if (ptr_char) {
    printf("'%c' position is %td\n", to_find, ptr_char - st + 1);
  }
  if (ptr_reverse_char) {
    printf("从后往前找---'%c' position is %td\n", to_find,
           ptr_reverse_char - st + 1);
  }

  /// strstr
  const char *text = "This is a simple example";
  const char *sub = "simple";
  char *res_strstr = strstr(text, sub);
  if (res_strstr != NULL) {
    printf("Found '%s' in \"%s\" at position:%td\n", sub, text,
           res_strstr - text + 1);
  } else {
    printf("%s is not found", sub);
  }

  /// strspn and strcspn
  const char *spn_str1 = "1234567qwerty789";
  const char *spn_str2 = "123456789";
  size_t spn_res = strspn(spn_str1, spn_str2);
  printf("%zu\n", spn_res);

  const char *c_spn_str1 = "abcd1234567qwe";
  const char *c_spn_str2 = "1234567qwe";
  size_t c_spn_res = strcspn(c_spn_str1, c_spn_str2);
  printf("%zu\n", c_spn_res);

  return 0;
}
