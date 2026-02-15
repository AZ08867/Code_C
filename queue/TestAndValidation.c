#include "TestAndValidation.h"
#include "GenericQueue.h"
#include "TypeDefinitions.h"
#include <stddef.h>
#include <stdio.h>

TestResult Test_GenericQueue_EnqueueDequeue(void) {
  printf("Running Test_GenericQueue_Enqueue_Dequeue ...\n");

  GenericQueue *queue = Queue_Create();
  if (!queue) {
    printf("Queue_Create failed.\n");
    return TEST_FAILURE;
  }
  int testValue = 42;
  DataValue value;
  value.ptr_value = &testValue;
  bool enqueueResult = Queue_Enqueue(queue, value, TYPE_PTR);
  if (!enqueueResult) {
    printf("Queue_Enqueue failed.\n");
    return TEST_FAILURE;
  }
  DataValue dequeuedValue;
  DataType dequeuedType;

  bool dequeueResult = Queue_Dequeue(queue, &dequeuedValue, &dequeuedType);
  if (!dequeueResult || dequeuedType != TYPE_PTR ||
      *(int *)dequeuedValue.ptr_value != testValue) {
    printf("Test failed: Dequeued data does not match expected value.\n");
    return TEST_FAILURE;
  }
  Queue_Destroy(queue);
  printf("Test_GenericQueue_Enqueue_Dequeue passed.\n");
  return TEST_SUCCESS;
}

/* TestResult Test_MemoryManagement_Allocation_Free(void); */

void RunTestSuite(const TestCase *test, size_t testCount) {
  size_t passedTests = 0;
  for (size_t i = 0; i < testCount; ++i) {
    printf("Running test: %s\n", test[i].name);
    TestResult result = test[i].testFunction();
    if (result == TEST_SUCCESS) {
      printf("Test passed: %s\n", test[i].name);
      ++passedTests;
    } else {
      printf("Test failed: %s\n", test[i].name);
    }
  }
  printf("\nTest Suite Summary: %zu/%zu tests passed.\n", passedTests,
         testCount);
}