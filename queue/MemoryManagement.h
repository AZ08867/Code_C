#pragma once

#include <stddef.h>

// 定义内存分配和释放的安全操作接口

// 安全地分配内存，如果分配失败则终止程序
void *SafeMalloc(size_t size);

// 安全地重新分配内存，如果分配失败则终止程序
void *SafeRealloc(void *ptr, size_t newSize);

// 安全地释放内存
void SafeFree(void **ptr);

// 打印当前的内存使用情况
void PrintMemoryUsage(void);

// 将内存使用情况转储到指定的文件
void MemoryManagement_DumpToFile(const char *filename);