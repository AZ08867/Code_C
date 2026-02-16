#include <corecrt_search.h>
#include <stdio.h>
#include <stdlib.h>
/// 动态数据结构的管理，函数修改指向结构体的指针，轻松添加修改删除节点，
/// 不需要返回额外新的头指针
typedef struct Node {
  int data;
  struct Node *next;
} Node;
void addAtHead(Node **head, int data);
void printList(Node *head);
int main(void) {
  Node *head = NULL;

  addAtHead(&head, 1);
  addAtHead(&head, 2);
  addAtHead(&head, 3);

  printList(head);

  Node *temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
  return EXIT_SUCCESS;
}
void addAtHead(Node **head, int data) {
  Node *newNode = malloc(sizeof(Node));
  if (newNode == NULL) {
    perror("Failed to allocate memory for new node\n");
  }

  newNode->data = data;
  newNode->next = *head; // 新节点指向原头节点
  *head = newNode;       // 更新头节点为新节点
}
void printList(Node *head) {
  Node *current = head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}
