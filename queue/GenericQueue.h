#pragma once
#include "TypeDefinitions.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

// 泛型队列节点结构体
typedef struct GenericQueueNode {
  DataValue data;                // 存储实际的数据
  DataType type;                 // 数据类型
  struct GenericQueueNode *next; // 指向下一个节点的指针
} GenericQueueNode;

typedef struct {
  GenericQueueNode *head; // 队列头指针，指向队列的第一个元素
  GenericQueueNode *tail; // 队列尾指针，指向队列的最后一个元素
  size_t size;            // 队列中元素的数量
} GenericQueue;

// 创建一个新的队列
GenericQueue *Queue_Create(void);

// 销毁队列并释放内存
void Queue_Destroy(GenericQueue *queue);

// 将一个元素入队
// queue: 队列指针
// data: 数据值
// type: 数据类型
// 返回：如果成功入队则返回true，否则返回false
bool Queue_Enqueue(GenericQueue *queue, DataValue data, DataType type);

// 将一个元素出队
// queue: 队列指针
// data: 用于存储出队元素数据的指针
// type: 用于存储出队元素类型的指针
// 返回：如果成功出队则返回true，否则返回false
bool Queue_Dequeue(GenericQueue *queue, DataValue *data, DataType *type);

// 获取队列的大小（元素数量）
size_t Queue_Size(const GenericQueue *queue);

// 检查队列是否为空
// 返回：如果队列为空则返回true，否则返回false
bool Queue_IsEmpty(const GenericQueue *queue);