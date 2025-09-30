#include <corecrt.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
int main(void) {
  FILE *source_file, *target_file;
  char source_path[] = "../append.txt";
  char target_path[] = "./append_copy.txt";

  char buffer[1024];
  size_t bytes_read;

  errno_t err = fopen_s(&source_file, source_path, "rb");

  if (err != 0 || source_file == NULL) {
    perror("Failed to open source file.");
    return EXIT_FAILURE;
  }

  err = fopen_s(&target_file, target_path, "wb");
  if (err != 0 || target_file == NULL) {
    perror("Failed to open target file.");
    fclose(source_file);
    return EXIT_FAILURE;
  }

  while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
    fwrite(buffer, 1, bytes_read, target_file);
  }
  _fcloseall();
  puts("File copied successfully!");
  return 0;
}
