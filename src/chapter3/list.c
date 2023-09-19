//
// Created by Ethan on 2023/9/19.
//
#include "list.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

// 置空链表
List makeEmpty(List L){
}

// 如果链表为空，就返回 true
int is_empty(List L){
    // 如果要使用 NULL，需要引入 stddef.h
    return L->Next == NULL;
}

// 如果 P 是链表的最后一个节点，就返回 true
int is_last(Position P, List L){
    return P->Next == NULL;
}

// 查找链表中的 X，如果没有就返回 NULL
Position find(ElementType X, List L){
    Position P;
    P = L->Next;
    while (P != NULL && P->Element != X){
        P = P->Next;
    }
    return P;
}

// 找到某个节点的前驱节点
Position find_previous(ElementType X, List L){
    Position P;
    P = L->Next;
    while (P->Next != NULL && P->Next->Element != X){
        P = P->Next;
    }
    return P;
}

// 删除一个值
void delete(ElementType X, List L){
    Position P, tem_cell;
    P = find_previous(X, L);
    if(!is_last(P, L)){
        tem_cell = P->Next;
        P->Next = tem_cell->Next;
        free(tem_cell);
    }
}

// 定义一种错误
void FatalError(const char *message) {
    fprintf(stderr, "Fatal Error: %s\n", message);
    exit(EXIT_FAILURE);
}
/// 我们已经把表 L传递给 lnsert 例程和 lsLast例程，尽管它从未被使用过。 之所以
/// 这么做，是因为别的实现方法可能会需要这些信息，因此，若不传递表 L有可能使得使用
/// ADT的想法失败。
// 插入一个值
void insert(ElementType X, List L, Position P){
    // 先分配内存
    Position tem_cell;
    tem_cell = malloc(sizeof (struct Node));
    if (tem_cell == NULL){
        // 处理内存分配失败
        FatalError("Out of Space!!!");
    }
    tem_cell->Element = X;
    tem_cell->Next = P->Next;
    P->Next = tem_cell;
}

// 删除整个链表
void delete_list(List L){
    Position P, tem_cell;
    P = L->Next;
    while (P != NULL){
        tem_cell = P->Next;
        /// 因为 C 语言要自己处理垃圾回收这一序列的东西，所以使用 L->Next = NULL 的方式处理不严谨
        free(P);
        P = tem_cell;
    }
}
/// Header 通常指的是链表的头结点，它是一个特殊的节点，不包含实际数据，而只包含指向链表中第一个实际节点的指针。
/// First 通常指的是链表中的第一个实际节点，即存储实际数据的节点。与头结点不同，第一个节点包含链表的第一个数据元素。
// 返回链表的头结点
Position header(List L){
    return L;
}

// 返回链表的第一个节点
Position first(List L){
    if (L == NULL){
        return NULL;
    }
    return L->Next;
}

// 获取 P 节点的元素值
ElementType retrieve(Position P){
    if (P != NULL) {
        return P->Element; // 从链表节点中获取元素值
    } else {
        // 处理传入的位置为空的情况
        // 你可以选择返回一个默认值，或者采取其他适当的错误处理措施
        // 这里简单地返回一个默认值 0，你可以根据需要修改
        return 0;
    }
}