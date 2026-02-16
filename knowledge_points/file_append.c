#include <corecrt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void append_log_safe(const char *filename, const char *msg);

int main(void) {
  puts("I am Appending file");
  const char *log_filename = "./append.txt";

  const char *msg = "select * from student";
  append_log_safe(log_filename, msg);

  return 0;
}

void append_log_safe(const char *filename, const char *msg) {
  FILE *file_ptr = NULL;
  errno_t err = fopen_s(&file_ptr, filename, "a");

  if (err != 0 || file_ptr == NULL) {
    char error_msg[256];
    strerror_s(error_msg, sizeof(error_msg), errno);

    fprintf(stderr, "Failed to open log file for appending: %s", error_msg);

    exit(EXIT_FAILURE);
  }
  fprintf(file_ptr, "%s\n", msg);
  fclose(file_ptr);
}
