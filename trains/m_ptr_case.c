/// 字符串无限添加的应用
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addString(char ***array, int *size, char *str);
void printString(char **array, int size);
int main(void) {
  char **strArray = NULL;

  int size = 0;
  addString(&strArray, &size, "Hello");
  addString(&strArray, &size, "World");

  printString(strArray, size);

  for (size_t i = 0; i < size; i++) {
    free(strArray[i]);
  }
  free(strArray);
  return EXIT_SUCCESS;
};

void addString(char ***array, int *size, char *str) {
  char **temp = realloc(*array, (*size + 1) * sizeof(char *));

  if (temp == NULL) {
    printf("Failed to allocate memory");
    return;
  }

  *array = temp;
  (*array)[*size] = (char *)malloc(strlen(str) + 1);
  if ((*array)[*size] != NULL) {
    strcpy_s((*array)[*size], strlen(str) + 1, str);
    (*size)++;
  } else {
    fprintf(stderr, "Error!\n");
  }
}

void printString(char **array, int size) {
  for (size_t i = 0; i < size; ++i) {
    printf("%s\n", array[i]);
  }
}
