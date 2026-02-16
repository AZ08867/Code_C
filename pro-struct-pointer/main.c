#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char *title; // Pointer to a string (character array)
  float price;
} Book;

typedef struct {
  size_t size;     // 当前书籍数量
  size_t capacity; // 当前可容纳的最大书籍数量
  Book *books;     // 指向 Book 结构体数组的指针，用于存储图书馆中的书籍
  // Book books   // 嵌套 Nesting
} Library;

// 组合 Composition 或 包含 Containment
typedef enum {
  SUCCESS = 0,
  ERROR_MEMORY_ALLOCATION = 1,
  ERROR_INVALID_INPUT = 2,
  ERROR_DUPLICATE_BOOK_ID = 3,
  ERROR_BOOK_NOT_FOUND = 4,
} ErrorCode;

// 构造函数 Constructor
Library create_library(size_t initial_capacity, ErrorCode *error_code) {
  Library lib = {0}; // 初始化结构体成员为 0
  if (initial_capacity == 0) {
    if (error_code != NULL) {
      *error_code = ERROR_INVALID_INPUT; // 无效输入错误
    }
    return lib; // 返回一个空的图书馆实例
  }
  lib.books = (Book *)malloc(initial_capacity * sizeof(Book));
  if (lib.books == NULL) {
    if (error_code != NULL) {
      *error_code = ERROR_MEMORY_ALLOCATION;
    }
    return lib;
  }
  lib.capacity = initial_capacity;
  if (error_code != NULL) {
    *error_code = SUCCESS;
  }
  return lib;
}

ErrorCode add_book(Library *lib, int id, const char *title, float price) {
  if (lib == NULL || title == NULL || price < 0) {
    return ERROR_INVALID_INPUT;
  }
  // 检查是否有重复的书籍 ID
  for (size_t i = 0; i < lib->size; i++) {
    if (lib->books[i].id == id) {
      return ERROR_DUPLICATE_BOOK_ID;
    }
  }
  // 检查是否需要扩展容量
  if (lib->size >= lib->capacity) {
    size_t new_capacity = lib->capacity * 2;
    Book *new_books = (Book *)realloc(lib->books, new_capacity * sizeof(Book));
    if (new_books == NULL) {
      return ERROR_MEMORY_ALLOCATION;
    }
    lib->books = new_books;
    lib->capacity = new_capacity;
  }

  // 分配书名的内存并复制字符串
  char *new_title = (char *)malloc(strlen(title) + 1);
  if (!new_title) {
    return ERROR_MEMORY_ALLOCATION;
  }
  strcpy_s(new_title, strlen(title) + 1, title);

  lib->books[lib->size].id = id;           // 设置书籍 ID
  lib->books[lib->size].title = new_title; // 设置书籍标题
  lib->books[lib->size].price = price;     // 设置书籍价格
  lib->size++;                             // 增加书籍数量
  return SUCCESS;
}

Book *find_book(const Library *lib, int id, ErrorCode *error_code) {
  if (lib == NULL) {
    if (error_code != NULL) {
      *error_code = ERROR_INVALID_INPUT;
    }
    return NULL;
  }
  for (size_t i = 0; i < lib->size; i++) {
    if (lib->books[i].id == id) {
      if (error_code != NULL) {
        *error_code = SUCCESS;
      }
      return &lib->books[i]; // 返回指向找到的书籍的指针
    }
  }
  *error_code = ERROR_BOOK_NOT_FOUND; // 书籍未找到错误
  return NULL;                        // 没有找到书籍
}

void print_library(const Library *lib) {
  if (lib == NULL) {
    printf("Library is NULL\n");
    return;
  }
  printf("图书馆藏书数量: %zu\n", lib->size);
  puts("---------------------------------------------");
  for (size_t i = 0; i < lib->size; i++) {
    printf("Book %zu:\n", i + 1);
    printf("\tBook ID: %d\n", lib->books[i].id);
    printf("\tBook Title: %s\n", lib->books[i].title);
    printf("\tBook Price: %.2f\n", lib->books[i].price);
    puts("---------------------------------------------");
  }
}

// 析构函数 Destructor
void free_library(Library *lib) {
  if (lib == NULL || lib->books == NULL) {
    return;
  }
  for (size_t i = 0; i < lib->size; i++) {
    free(lib->books[i].title);
  }
  free(lib->books);
  lib->books = NULL;
  lib->size = 0;
  lib->capacity = 0;
}

int main() {
  ErrorCode error_code;
  Library lib = create_library(2, &error_code);
  if (error_code != SUCCESS) {
    fprintf(stderr, "Failed to create library: %d\n", error_code);
    return EXIT_FAILURE;
  }
  if (add_book(&lib, 1, "The C Programming Language", 10.99f) != SUCCESS) {
    fprintf(stderr, "Failed to add book\n");
    free_library(&lib);
    return EXIT_FAILURE;
  }
  if (add_book(&lib, 2, "Go Programming Language", 8.99f) != SUCCESS) {
    fprintf(stderr, "Failed to add book\n");
    free_library(&lib);
    return EXIT_FAILURE;
  }
  if (add_book(&lib, 3, "1984", 9.99f) != SUCCESS) {
    fprintf(stderr, "Failed to add book\n");
    free_library(&lib);
    return EXIT_FAILURE;
  }
  print_library(&lib);
  Book *book = find_book(&lib, 2, &error_code);
  if (error_code == SUCCESS && book != NULL) {
    printf("Found book: %s\n", book->title);
  } else {
    printf("Book not found or error occurred\n");
  }

  printf("Library capacity: %zu\n", lib.capacity);

  free_library(&lib);
  return 0;
}