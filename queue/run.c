#include "TestAndValidation.h"
#include <stdio.h>
#include <stdlib.h>

extern TestResult Test_GenericQueue_EnqueueDequeue(void);

TestCase testCases[] = {
    {"Test_GenericQueue_EnqueueDequeue", Test_GenericQueue_EnqueueDequeue},
    // {"Test_MemoryManagement_Allocation_Free",
    // Test_MemoryManagement_Allocation_Free},
};

// 返回一个结构体
int main(int argc, char *argv[]) {
  puts("Running Test Suite for Generic Queue Implementation...");
  RunTestSuite(testCases, sizeof(testCases) / sizeof(testCases[0]));
  // 泛型
  return EXIT_SUCCESS;
}