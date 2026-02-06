#include "types.h"
#include <stddef.h>
#include <stdlib.h>

/*
 * 安全分配内存
 * @params size 需要分配的内存大小, 使用size_t类型保证跨平台兼容性
 * @return 指向分配内存的指针，失败返回NULL
 */

inline void *safe_malloc(size_t size) {
  if (size == 0) {
    return NULL;
  }
  void *ptr = malloc(size);
  if (!ptr) {
    // 内存分配失败，处理错误
    return NULL;
  }
  return ptr;
}

/*
 * 安全重新分配内存
 * @params ptr 指向原内存的指针
 * @param newSize 需要重新分配的内存大小
 * @return 指向重新分配内存的指针，失败返回NULL
 */

inline void *safe_remalloc(void *ptr, size_t newSize) {
  if (ptr) {
    free(ptr);
    ptr = NULL; // 避免悬空指针
  }
  return safe_malloc(newSize);
}

/*
 * 安全释放内存
 * @params ptr 指向需要释放内存的指针
 */

inline void safe_free(void **ptr) {
  if (ptr) {
    free(ptr);
    ptr = NULL; // 避免悬空指针
  }
}