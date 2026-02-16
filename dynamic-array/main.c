#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// 动态数组 Dynamic Array
// 通过动态内存分配实现可变大小的数组

typedef struct {
  int *data;       // 指向动态分配的数组
  size_t size;     // 当前数组大小
  size_t capacity; // 数组容量
} DynamicArray;

// create a new dynamic array
DynamicArray *create_dynamic_array(size_t initial_capacity) {
  DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
  if (arr == NULL) {
    return NULL; // 内存分配失败
  }
  arr->data = (int *)malloc(initial_capacity * sizeof(int));
  if (arr->data == NULL) {
    free(arr);
    return NULL; // 内存分配失败
  }
  arr->size = 0;
  arr->capacity = initial_capacity;
  return arr;
}

// append
int append(DynamicArray *arr, int value) {
  if (!arr) {
    return 0;
  }
  if (arr->size >= arr->capacity) {
    size_t new_capacity = arr->capacity * 2;
    int *new_data = (int *)realloc(arr->data, new_capacity * sizeof(int));
    if (new_data == NULL) {
      return 0; // 内存分配失败
    }
    arr->data = new_data;
    arr->capacity = new_capacity;
  }
  arr->data[arr->size++] = value;
  return 1;
}

// print dynamic array
void print_array(DynamicArray *arr) {
  if (!arr) {
    return;
  }
  puts("数组元素如下:");
  for (size_t i = 0; i < arr->size; ++i) {
    printf("%d ", arr->data[i]);
  }
  printf("\n元素数量: %zu\t容量: %zu\n", arr->size, arr->capacity);
}

// free dynamic array
void free_dynamic_array(DynamicArray *arr) {
  if (arr) {
    free(arr->data);
    free(arr);
  }
}

int main(int argc, char *argv[]) {
  DynamicArray *arr = create_dynamic_array(4);

  if (!arr) {
    return EXIT_FAILURE; // 内存分配失败
  }
  append(arr, 1);
  append(arr, 2);
  append(arr, 3);
  append(arr, 4);
  append(arr, 5);

  print_array(arr);
  free_dynamic_array(arr);
  return EXIT_SUCCESS;
}