#pragma once
#include "types.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * 安全分配内存
 * @params size 需要分配的内存大小, 使用size_t类型保证跨平台兼容性
 * @return 指向分配内存的指针，失败返回NULL
 */

void *safe_malloc(size_t size);

/*
 * 安全重新分配内存
 * @params ptr 指向原内存的指针
 * @param newSize 需要重新分配的内存大小
 * @return 指向重新分配内存的指针，失败返回NULL
 */

void *safe_remalloc(void *ptr, size_t newSize);

/*
 * 安全释放内存
 * @params ptr 指向需要释放内存的指针
 */

void safe_free(void **ptr);