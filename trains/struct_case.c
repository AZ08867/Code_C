/// Struct Case

#include <stdio.h>

// 匿名结构体
typedef struct {
  char name[50];
  int id;
  float score;
} Student;

void print_info(Student stu);
void update_score(Student *stu, float new_score);

int main(int argc, char *argv[]) {
  Student stu = {"John", 123, 92.5};
  puts("Before Update");

  print_info(stu);

  update_score(&stu, 89.5);
  print_info(stu);
  return 0;
}
void print_info(Student stu) {
  printf("Student Name:%s, Student id: %d, Student score:%.2f\n", stu.name,
         stu.id, stu.score);
}
void update_score(Student *stu, float new_score) { stu->score = new_score; }
