#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

typedef enum {
  TYPE_I32,
  TYPE_U32,
  TYPE_I64,
  TYPE_U64,
  TYPE_F32,
  TYPE_F64,
  TYPE_CHAR,
  TYPE_PTR
} DataType;

typedef union {
  i32 i32_value;
  u32 u32_value;
  i64 i64_value;
  u64 u64_value;
  f32 f32_value;
  f64 f64_value;
  char char_value;
  void *ptr_value;
} DataValue;