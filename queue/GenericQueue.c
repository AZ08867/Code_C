#include "GenericQueue.h"
#include <stdbool.h>
#include <stdlib.h>

GenericQueue *Queue_Create(void) {
  GenericQueue *queue = (GenericQueue *)malloc(sizeof(GenericQueue));
  if (queue == NULL) {
    return NULL;
  }
  queue->head = queue->tail = NULL;
  queue->size = 0;
  return queue;
}
void Queue_Destroy(GenericQueue *queue) {
  if (queue == NULL) {
    return;
  }
  GenericQueueNode *current = queue->head;
  while (current != NULL) {
    GenericQueueNode *next = current->next;
    free(current);
    current = next;
  }
  free(queue);
}
bool Queue_Enqueue(GenericQueue *queue, DataValue data, DataType type) {
  if (queue == NULL) {
    return false;
  }
  GenericQueueNode *newNode =
      (GenericQueueNode *)malloc(sizeof(GenericQueueNode));
  if (newNode == NULL) {
    return false;
  }

  newNode->data = data;
  newNode->type = type;
  newNode->next = NULL;

  if (queue->tail == NULL) {
    queue->head = queue->tail = newNode;
  } else {
    queue->tail->next = newNode;
    queue->tail = newNode;
  }
  queue->size++;
  return true;
}
bool Queue_Dequeue(GenericQueue *queue, DataValue *data, DataType *type) {
  if (queue == NULL || queue->head == NULL) {
    return false;
  }
  GenericQueueNode *nodeToRemove = queue->head;
  *data = nodeToRemove->data;
  *type = nodeToRemove->type;

  queue->head = queue->head->next;
  if (queue->head == NULL) {
    queue->tail = NULL;
  }
  free(nodeToRemove);
  queue->size--;
  return true;
}
size_t Queue_Size(const GenericQueue *queue) { return queue ? queue->size : 0; }
bool Queue_IsEmpty(const GenericQueue *queue) {
  return queue ? (queue->size == 0) : true;
}