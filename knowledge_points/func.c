#include <stdio.h>
void greet(int age);
int add(int a, int b); // 这里只需要下类型匹配就可以正常调用
int main() {
  greet(24); // actual para -> age:18
  printf("sum = %d \n", add(23, 24));
  return 0;
}
void greet(int age) { // formal para: int age
  puts("Hello functions");
  printf("Your age is %d.\n", age);
}

int add(int num1, int num2) { return num1 + num2; }
