#pragma once

#include <stdbool.h>

typedef enum TestResult {
  TEST_SUCCESS,
  TEST_FAILURE,
} TestResult;

typedef struct TestCase {
  const char *name;
  TestResult (*testFunction)(void);
} TestCase;

void RunTestSuite(const TestCase *test, size_t testCount);

#define VERIFY(expression)                                                     \
  do {                                                                         \
    if (!(expression)) {                                                       \
      fprintf(stderr, "Test failed: %s, at %s:%d\n", #expression, __FILE__,    \
              __LINE__);                                                       \
      return TEST_FAILURE;                                                     \
    }                                                                          \
  } while (0)

TestResult Test_GenericQueue_EnqueueDequeue(void);

// todo
// TestResult Test_MemoryManagement_Allocation_Free(void);
