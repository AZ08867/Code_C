#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void processAdd(int argc, char *argv[]);
int main(int argc, char *argv[]) {
  if (argc >= 3 && strcmp(argv[1], "-a") == 0) {
    processAdd(argc, argv);
  }
  return EXIT_SUCCESS;
}

void processAdd(int argc, char *argv[]) {
  int sum = 0;
  for (size_t i = 0; i < argc; ++i) {
    sum += atoi(argv[i]);
  }
  printf("Sum: %d\n", sum);
}