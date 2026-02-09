#pragma once

#include <stdbool.h>

bool is_nullptr(const void *ptr);

/*
 * 安全解引用指针
 * 如果指针为NULL，记录错误并且返回指定默认值
 * @param ptr 待解引用的指针
 * @param defaultValue 当ptr为NULL时返回的默认值
 * @return 解引用后的值或者默认值
 */

#define SAFE_DEREF(ptr, defaultValue)                                          \
  (is_nullptr(ptr)                                                             \
       ? (log_message(LOG_ERROR, "Attempted to dereference a NULL pointer"),   \
          (defaultValue))                                                      \
       : (*(ptr)))