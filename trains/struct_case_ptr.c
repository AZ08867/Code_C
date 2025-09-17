/// Struct Case 通过值返回结构体

#include <stdio.h>
typedef struct {
  int x;
  int y;
} Point;

/// 嵌套结构体
typedef struct {
  char street[50];
  char city[50];
  char country[50];
} Address;

typedef struct {
  char name[50];
  int age;
  Address address;
} Person;

Point get_point(void);
int main(int argc, char *argv[]) {
  Point my_point = get_point();
  printf("Point:(%d, %d)\n", my_point.x, my_point.y);

  Person person = {"Alex", 34, {"228b", "Shanghai", "China"}};
  printf("This man is %s, he has %d years old.\n", person.name, person.age);
  printf("%s lives in %s-%s-%s\n", person.name, person.address.country,
         person.address.city, person.address.street);

  Person *ptr = &person;
  printf("Name: %s", ptr->name);
  printf("Address: %s-%s-%s", ptr->address.country, ptr->address.city,
         ptr->address.street);
  return 0;
}
Point get_point(void) {
  Point p = {10, 20};
  return p;
}
