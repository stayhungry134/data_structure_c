//
// Created by stayh on 2023/9/20.
//
#include "stack_list.h"
#include <stdio.h>
#include <stdlib.h>

// 定义一种错误
void FatalError(const char *message) {
    fprintf(stderr, "Fatal Error: %s\n", message);
    exit(EXIT_FAILURE);
}

// 判断是否为空
int is_empty(Stack S) {
    return S->TopOfStack == EmptyTOS;
}

// 判断是否满了
int is_full(Stack S) {
    return S->TopOfStack == S->Capacity - 1;
}

Stack create_stack(int Max_Elements) {
    Stack S;
    if (Max_Elements < MinStackSize) {
        FatalError("Stack size is too small");
    }
    S = malloc(sizeof(struct StackRecord));
    if (S == NULL) {
        FatalError("Out of space!!!");
    }
    S->Array = malloc(sizeof(ElementType) * Max_Elements);
    if (S->Array == NULL) {
        FatalError("Out of space!!!");
    }
    S->Capacity = Max_Elements;
    make_empty(S);

    return S;
}

// 释放一个栈
void dispose_stack(Stack S) {
    if (S != NULL) {
        free(S->Array);
        free(S);
    }
}

// 栈置空
void make_empty(Stack S) {
    S->TopOfStack = EmptyTOS;
}

// push 一个元素
void push(ElementType X, Stack S) {
    if (is_full(S)) {
        FatalError("Full stack");
    } else {
        S->Array[++S->TopOfStack] = X;
    }
}

// 返回栈的 top
ElementType top(Stack S) {
    if (!is_empty(S)) {
        return S->Array[S->TopOfStack];
    }
    FatalError("Empty stack");
}

// pop 一个元素
void pop(Stack S) {
    if (is_empty(S)) {
        FatalError("Empty stack");
    } else {
        S->TopOfStack--;
    }
}

// 返回栈的 top 并且 pop
ElementType top_and_pop(Stack S) {
    if (!is_empty(S)) {
        return S->Array[S->TopOfStack--];
    }
    FatalError("Empty stack");
}