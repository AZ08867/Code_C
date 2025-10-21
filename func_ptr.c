#include <stdio.h>
// 如何声明一个指针指向函数？
// 返回类型 （*指针变量名）（参数类型）;

int (*myFunctionPointer)(int, int);
// myFunctionPointer -> int f(int num1, int num2);
int add(int a, int b);

int main(void) {
  puts("Let's start function pointer");

  myFunctionPointer = add;
  int result = myFunctionPointer(3, 42);
  printf("3 + 42 = %d", result);

  return 0;
}

int add(int a, int b) { return a + b; }