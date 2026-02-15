#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 4
#define MAX_NAME 50

typedef struct {
  char name[MAX_NAME];
  int age;
} Person;

static void print_2d_array(int rows, int cols, int arr[ROWS][COLS]);
/* void print_2d_array(int (*arr)[COLS]); */

static void modify_people(Person *people, size_t num_people);

static int compare_people(const void *a, const void *b);

static void greet(const char *name);

static void farewell(const char *name);

typedef void (*MessageFunc)(const char *);

int main(int argc, char *argv[]) {
  int matrix[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  Person people[ROWS] = {{"Alice", 35}, {"Bob", 30}, {"Charlie", 27}};
  size_t num_people = sizeof(people) / sizeof(people[0]);

  puts("Before Modification ...");
  for (size_t i = 0; i < num_people; ++i) {
    printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
  }
  puts("");
  puts("After Modification ...");

  modify_people(people, num_people);
  for (size_t i = 0; i < num_people; ++i) {
    printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
  }

  qsort(people, num_people, sizeof(Person), compare_people);

  puts("");
  puts("Sorted People:");
  for (size_t i = 0; i < num_people; ++i) {
    printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
  }

  puts("");
  puts("2D Array:");
  print_2d_array(ROWS, COLS, matrix);

  puts("");
  MessageFunc message_funcs[] = {greet, farewell};
  const char *name = "Az";
  for (size_t i = 0; i < sizeof(message_funcs) / sizeof(message_funcs[0]);
       ++i) {
    message_funcs[i](name);
  }

  return EXIT_SUCCESS;
}

static void print_2d_array(int rows, int cols, int arr[ROWS][COLS]) {
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      printf("%d ", arr[i][j]);
    }
    puts("");
  }
}
static void modify_people(Person *people, size_t num_people) {
  for (size_t i = 0; i < num_people; ++i) {
    people[i].age += 1; // Increment age by 1
  }
}

static int compare_people(const void *a, const void *b) {
  const Person *person_a = (const Person *)a;
  const Person *person_b = (const Person *)b;
  return person_a->age - person_b->age; // Sort by age
}

static void greet(const char *name) {
  printf("Hello, %s! Welcome to the C programming world!\n", name);
}

static void farewell(const char *name) {
  printf("Goodbye, %s! See you next time!\n", name);
}
