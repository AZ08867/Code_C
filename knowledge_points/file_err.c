/// ferror feof clearerr
#include <stdio.h>
#include <stdlib.h>
int main(void) {
  FILE *file_ptr;
  errno_t err = fopen_s(&file_ptr, "./test.txt", "r+");

  if (err != 0 || file_ptr == NULL) {
    perror("Failed to open file.");
    return EXIT_FAILURE;
  }

  char buffer[100];
  while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
    printf("%s", buffer);
  }

  if (ferror(file_ptr)) {
    perror("Error reading file");
    clearerr(file_ptr); // Clear the error indicator
  }

  if (feof(file_ptr)) {
    printf("\nEnd of file reached.\n");
  } else {
    printf("\nNot at end of file.\n");
  }

  fclose(file_ptr);

  return 0;
}
