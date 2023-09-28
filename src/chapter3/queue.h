//
// Created by Ethan on 2023/9/22.
//
/// 使用数组实现一个队列
#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H
struct QueueRecord;
typedef struct QueueRecord * Queue;

typedef int ElementType;

int is_empty(Queue Q);
int is_full(Queue Q);
Queue  create_queue(int MaxElements);
void dispose_queue(Queue Q);
void make_empty(Queue Q);
void enqueue(ElementType X, Queue Q);
ElementType front(Queue Q);
void dequeue(Queue Q);
ElementType front_and_dequeue(Queue Q);
#endif //DATA_STRUCTURE_QUEUE_H

#define  MinQueueSize (5)

struct QueueRecord{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};