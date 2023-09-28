//
// Created by Ethan on 2023/9/22.
//
#include "queue.h"
#include "stdio.h"
#include "stdlib.h"

// 判断队列是否为空
int is_empty(Queue Q){
    return Q->Size == 0;
}

// 判断队列是否已满
int is_full(Queue Q){
    return Q->Size == Q->Capacity;
}

// 释放一个队列
void dispose_queue(Queue Q){
    if(Q != NULL){
        free(Q->Array);
        free(Q);
    }
}

// 创建一个队列
Queue create_queue(int MaxElements){
    Queue Q;
    if(MaxElements < MinQueueSize){
        printf("Queue size is too small");
        exit(1);
    }
    Q = malloc(sizeof(struct QueueRecord));
    if(Q == NULL){
        printf("Out of space");
        exit(1);
    }
    Q->Array = malloc(sizeof(ElementType) * MaxElements);
    if(Q->Array == NULL){
        printf("Out of space");
        exit(1);
    }
    Q->Capacity = MaxElements;
    make_empty(Q);
    return Q;
}


// 构造空队列
void make_empty(Queue Q){
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int succ(int Value, Queue Q){
    if (++Value == Q->Capacity){
        Value = 0;
    }
    return Value;
}
// 入队
void enqueue(ElementType X, Queue Q){
    if(is_full(Q)){
        printf("Full queue");
        exit(1);
    }else{
        Q->Size++;
        Q->Rear = succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

// 返回队列的头
ElementType front(Queue Q){
    if(!is_empty(Q)){
        return Q->Array[Q->Front];
    }
    printf("Empty queue");
    exit(1);
}

// 出队
void dequeue(Queue Q){
    if(is_empty(Q)){
        printf("Empty queue");
        exit(1);
    }else{
        Q->Size--;
        Q->Front = succ(Q->Front, Q);
    }
}

// 返回队列的头并出队
ElementType front_and_dequeue(Queue Q){
    ElementType X = 0;
    if(is_empty(Q)){
        printf("Empty queue");
        exit(1);
    }else{
        Q->Size--;
        X = Q->Array[Q->Front];
        Q->Front = succ(Q->Front, Q);
    }
    return X;
}