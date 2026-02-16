#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *file_ptr;
  puts("Stdin and Stdout");
  errno_t err = fopen_s(&file_ptr, "./test.txt", "r+");

  if (err != 0 || file_ptr == NULL) {
    perror("Failed to open file.");
    return EXIT_FAILURE;
  }

  // ftell
  // fseek
  // rewind

  long position = ftell(file_ptr);
  printf("Current location: %ld\n", position);

  // start reading
  char buffer[100];
  if (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
    printf("Read line: %s", buffer);
    // get current position
    position = ftell(file_ptr);
    printf("After reading location: %ld\n", position);
  }

  // move to the beginning of the file
  fseek(file_ptr, 0, SEEK_SET);
  printf("After fseek to beginning location: %ld\n", ftell(file_ptr));

  // use rewind to move to the beginning
  rewind(file_ptr);
  printf("After rewind location: %ld\n", ftell(file_ptr));

  fclose(file_ptr);

  return 0;
}