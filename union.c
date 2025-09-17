/// Union
#include <stdio.h>
#include <sys/types.h>
// 联合：允许在相同的位置存储不同的数据类型
// 联合体的所有成员共享一块内存空间，大小等于其最大成员的大小

typedef union {
  int int_value;
  float float_value;
  char *string_value;
} Data;

typedef enum { INT, FLOAT, STRING } DataType;

typedef struct {
  DataType type;
  Data data;
} TypeData;

void print_type(TypeData *typedata);

int main(int argc, char *argv[]) {
  TypeData data1 = {INT, {.int_value = 42}};
  TypeData data2 = {FLOAT, {.float_value = 3.14}};
  TypeData data3 = {STRING, {.string_value = "Hello Union!"}};
  print_type(&data1);
  print_type(&data2);
  print_type(&data3);
  return 0;
}

void print_type(TypeData *typedata) {
  switch (typedata->type) {
  case INT:
    printf("Integer: %d\n", typedata->data.int_value);
    break;
  case FLOAT:
    printf("Float: %.2f\n", typedata->data.float_value);
    break;
  case STRING:
    printf("String: %s\n", typedata->data.string_value);
    break;
  default:
    break;
  };
}
