#include <stdio.h>
#include <stdlib.h>

int main(void) {
  puts("Stdin and Stdout");

  FILE *file_ptr = NULL;

  errno_t err = fopen_s(&file_ptr, "./write.txt", "w");

  if (err != 0 || file_ptr == NULL) {
    perror("Failed to open file");
    return EXIT_FAILURE;
  }

  fputc('H', file_ptr);
  fputc('i', file_ptr);
  fputc('\n', file_ptr);

  fputs("This is a line written by fputs.\n", file_ptr);

  fprintf_s(file_ptr, "Numbers: %d, %.2f, %s", 42, 3.14, "Halo");

  fclose(file_ptr);

  puts("File 'write.txt' has been written successfully.");

  return 0;
}