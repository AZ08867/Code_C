#include "TypeSafetyAndErrorHandling.h"
#include <stdio.h>
#include <stdlib.h>

/* Portable thread-local storage macro: MSVC vs. C11-compatible compilers */
#if defined(_MSC_VER)
#define THREAD_LOCAL __declspec(thread)
#else
#define THREAD_LOCAL _Thread_local
#endif

static THREAD_LOCAL ErrorCode s_currentErrorCode = SUCCESS;

void SetErrorCode(ErrorCode code) { s_currentErrorCode = code; }

ErrorCode GetErrorCode(void) { return s_currentErrorCode; }

const char *GetErrorMessage(ErrorCode code) {
  switch (code) {
  case SUCCESS:
    return "No Error.";
  case ERROR_MEMORY_ALLOCATION_FAILED:
    return "Memory allocation failed.";
  case ERROR_INVALID_ARGUMENT:
    return "Invalid argument.";
  case ERROR_OUT_OF_MEMORY:
    return "Out of memory.";
  case ERROR_NULL_POINTER:
    return "Null pointer error.";
  default:
    return "Unknown error.";
  }
}

ErrorCode CheckNotNull(const void *ptr) {
  if (ptr == NULL) {
    SetErrorCode(ERROR_NULL_POINTER);
    return ERROR_NULL_POINTER;
  }
  return SUCCESS;
}

void HandleError(ErrorCode code) {
  const char *message = GetErrorMessage(code);
  fprintf(stderr, "Error: %s\n", message);
  if (code != SUCCESS) {
    exit(EXIT_FAILURE);
  }
}