#include <stdio.h>
int main(void) {
  puts("Hello pointer");
  int building_floors[5] = {101, 102, 103, 104, 105};
  int target_floor = 103;
  int *ptr_floor_103 =
      &building_floors[2]; // (int*)(ptr_floor_103) -->微软的规范，表明强调

  printf("ptr_floor_103的地址: \t\t%p\n", ptr_floor_103);
  printf("ptr_floor_103的地址对应的值:\t%d\n", *ptr_floor_103);

  int *ptr_new_106 = ptr_floor_103;
  *ptr_new_106 = 106;
  printf("building_floors_[2] = \t\t%d\n", *ptr_new_106);

  // !重点
  /*指针的算数运算*/
  int numbers[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
  int *ptr = numbers;

  printf("%p\n", &numbers[0]);
  printf("%p\n", ptr);

  // 计算数组的大小
  int size = sizeof(numbers) / sizeof(numbers[0]);
  printf("The size of array is %d\n", size);

  printf("Original array numbers[] = {");
  for (int i = 0; i < size; i++) {
    printf("%d ", numbers[i]);
  }
  puts("}");

  // 使用指针的加法运算访问第5个元素
  ptr += 4;
  printf("%d\n", *ptr);

  // 指针之间的减法运算
  int *start_ptr = &numbers[0];
  int *end_ptr = &numbers[size - 1];
  printf("%td\n", end_ptr - start_ptr);

  // 指针之间的比较
  if (start_ptr < end_ptr) {
    puts("start_str 指向的元素在 end_str 之前");
  }

  // 使用指针来遍历数组
  puts("数组numbers中的元素如下");
  printf("数组numbers numbers[] = {");
  for (int *p = start_ptr; p <= end_ptr; p++) {
    printf("%d ", *p);
  }
  puts("}");

  // 翻转数组
  puts("------翻转数组------");
  printf("数组numbers numbers[] = {");
  for (int *p = end_ptr; p >= start_ptr; p--) {
    printf("%d ", *p);
  }
  puts("}");
  return 0;
}
