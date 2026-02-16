#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char *title; // Pointer to a string (character array)
  float price;
} Book;

// 构造函数，创建一个新的 Book 实例
Book creat_book(int id, const char *title, float price) {
  Book book;
  book.id = id;
  // 为 title 分配内存并复制字符串
  book.title = (char *)malloc(strlen(title) + 1); // +1 for null terminator
  if (book.title != NULL) {
    strcpy_s(book.title, strlen(title) + 1, title);
  }
  book.price = price;
  return book;
}

void print_book(const Book *book) {
  if (book != NULL) {
    printf("Book ID: %d\n", book->id);
    printf("Book Title: %s\n", book->title);
    printf("Book Price: %.2f\n", book->price);
  }
}

void free_book(Book *book) {
  if (book != NULL) {
    free(book->title);  // 释放为 title 分配的内存
    book->title = NULL; // 避免悬空指针
  }
}

int main() {
  // 创建一个 Book 实例
  Book myBook = creat_book(1, "The C Programming Language", 10.99f);

  // 使用 myBook 的数据
  print_book(&myBook);

  // 释放为 title 分配的内存
  free_book(&myBook);

  return 0;
}