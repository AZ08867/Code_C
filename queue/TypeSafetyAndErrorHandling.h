#pragma once
#include <errno.h>
#include <stddef.h>

typedef enum {
  SUCCESS = 0,                    // 无错误
  ERROR_NULL_POINTER,             // 空指针错误
  ERROR_MEMORY_ALLOCATION_FAILED, // 内存分配失败错误
  ERROR_OUT_OF_MEMORY,            // 内存不足错误
  ERROR_INVALID_ARGUMENT,         // 无效参数错误
} ErrorCode;

/// 错误处理函数声明
// 设置当前的错误代码
void SetErrorCode(ErrorCode code);

// 获取当前的错误代码
ErrorCode GetErrorCode(void);

// 获取错误代码对应的错误消息
const char *GetErrorMessage(ErrorCode code);

// 检查指针是否为NULL，如果是则设置错误代码并返回错误代码
// 使用 const 指针签名以明确不会修改被检查的对象
ErrorCode CheckNotNull(const void *ptr);

// 错误处理函数声明
void HandleError(ErrorCode code);