#include <stdio.h>
#include <stdlib.h>

int main(void) {
  /* 原实现（已注释）
  #include <stddef.h>
  char buffer[512];
  size_t buffer_size = sizeof(buffer);
  errno_t err = getenv_s(&buffer_size, buffer, buffer_size, "PATH");
  if (err == 0) {
      printf("PATH: %s\n", buffer);
  } else {
      fprintf(stderr, "PATH not found or getenv_s failed\n");
      return -1;
  }
  return EXIT_SUCCESS;
  */

#ifdef _MSC_VER
  char *value = NULL;
  size_t len = 0;
  errno_t err = _dupenv_s(&value, &len, "PATH");
  if (err == 0 && value) {
    printf("PATH: %s\n", value);
    free(value);
    return EXIT_SUCCESS;
  }
  fprintf(stderr, "_dupenv_s failed or PATH not set\n");
  return EXIT_FAILURE;
#else
  /* 非 MSVC 环境回退到标准 getenv */
  char *p = getenv("PATH");
  if (p) {
    printf("PATH: %s\n", p);
    return EXIT_SUCCESS;
  }
  fprintf(stderr, "PATH not found\n");
  return EXIT_FAILURE;
#endif
}
