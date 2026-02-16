#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  puts("Stdin and Stdout");

  FILE *file_stream = NULL;
  char buffer[256];

  errno_t err = fopen_s(&file_stream, "./test.txt", "r");

  if (err != 0 || file_stream == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  while (fgets(buffer, sizeof(buffer), file_stream)) {
    printf("%s", buffer);
  }

  memset(buffer, 0, sizeof(buffer));

  // read twice
  rewind(file_stream);

  puts("\n---------------");

  int ch;
  while ((ch = fgetc(file_stream)) != EOF) {
    putchar(ch);
  };
  /* printf("%c", ch); */

  fclose(file_stream);
  return 0;
}