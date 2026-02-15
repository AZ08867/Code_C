#include "MemoryManagement.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// _msize_s 检查内存块的大小

#ifdef _WIN32
#include <malloc.h>
#endif

static size_t currentMemoryUsage = 0;

void *SafeMalloc(size_t size) {
  void *ptr = malloc(size);
  if (ptr) {
    currentMemoryUsage += size;
  } else {
    fprintf(stderr, "Error: Memory allocation failed for %zu bytes.\n", size);
    exit(EXIT_FAILURE);
  }
  return ptr;
}

void *SafeRealloc(void *ptr, size_t newSize) {
  size_t oldSize = 0;
  if (ptr) {
#ifdef _WIN32
    oldSize = _msize(ptr); // 特定用于windows
#else
    // 非Windows操作系统需要使用其他的方式减少currentMemoryUsage
    // TODO
#endif
  }
  void *newPtr = realloc(ptr, newSize);
  if (newPtr) {
    currentMemoryUsage += newSize - oldSize;
  } else {
    fprintf(stderr, "Error: Memory reallocation failed for %zu bytes.\n",
            newSize);
    exit(EXIT_FAILURE);
  }

  return newPtr;
}

// 安全地释放内存
void SafeFree(void **ptr) {
  if (ptr && *ptr) {
#ifdef _WIN32
    currentMemoryUsage = _msize(ptr); // 特定用于windows
#else
    // 非Windows操作系统需要使用其他的方式减少currentMemoryUsage
    // TODO
#endif
    free(*ptr);
    *ptr = NULL;
  }
}

void PrintMemoryUsage(void) {
  printf("Current memory usage: %zu bytes.\n", currentMemoryUsage);
}

// 将内存管理信息写入到文件的函数声明
void MemoryManagement_DumpToFile(const char *filename) {
  FILE *file;
  errno_t err = fopen_s(&file, filename, "w");
  if (err != 0) {
    fprintf(stderr, "Error: Unable to openfile %s for writing.\n", filename);
    return;
  }
  fprintf(file, "Current memory usage: %zu bytes\n", currentMemoryUsage);
  fclose(file);
}