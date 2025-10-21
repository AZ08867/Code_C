#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int *taskList;
  int taskCount;

} Employee;

Employee *create_employee(const char *name, int taskCount);
void free_employee(Employee *employee);

int main(int argc, char *argv[]) {
  puts("Calloc 函数使用案例");

  Employee *developer = create_employee("Az", 6);
  if (developer == NULL)
    return EXIT_FAILURE;
  developer->taskList[0] = 101;
  printf("Assigned Task ID for %s: %d\n", developer->name,
         developer->taskList[0]);

  free(developer);
  return EXIT_SUCCESS;
}

Employee *create_employee(const char *name, int taskCount) {
  Employee *new_employee = (Employee *)malloc(sizeof(Employee));
  if (new_employee == NULL) {
    perror("Failed to allocate memory for new employee");
    return NULL;
  }

  new_employee->name = (char *)malloc(strlen(name) + 1);
  if (new_employee->name == NULL) {
    perror("Failed to allocate memory for new employee name");
    free(new_employee); // 防止内存泄露
    return NULL;
  }
  strcpy_s(new_employee->name, strlen(name) + 1, name);
  new_employee->taskCount = taskCount;
  new_employee->taskList = (int *)calloc(taskCount, sizeof(int));

  if (new_employee->taskList == NULL) {
    perror("Failed to allocate memory for taskList");
    free(new_employee->name);
    free(new_employee); // 防止内存泄露
    return NULL;
  }
  return new_employee;
}
void free_employee(Employee *employee) {
  if (employee != NULL) {
    free(employee->name);
    free(employee->taskList);
    free(employee);
  }
}
