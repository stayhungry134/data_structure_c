//
// Created by stayh on 2023/9/20.
//
#include "stack.h"
#include "stdlib.h"
#include "stdio.h"

// 定义一种错误
void FatalError(const char *message) {
    fprintf(stderr, "Fatal Error: %s\n", message);
    exit(EXIT_FAILURE);
}

// 判断是否为空
int is_empty(Stack S){
    return S->Next == NULL;
}

// 创建一个栈
Stack create_stack(void){
    Stack S;
    S = malloc(sizeof (struct StackNode));
    if (S == NULL){
        FatalError("Out of space!!!");
    }
    S->Next = NULL;
    make_empty(S);
    return S;
}

// 置空一个栈
void make_empty(Stack S){
    if (S == NULL){
        FatalError("Must use CreateStack first");
    } else{
        while(!is_empty(S))
            pop(S);
    }
}

// push 一个元素
void push(ElementType X, Stack S){
    PtrToNode tem_cell;
    tem_cell = malloc(sizeof (struct StackNode));
    if (tem_cell == NULL)
        FatalError("Out of space!!!");
    else{
        tem_cell->Element = X;
        tem_cell->Next = S->Next;
        S->Next = tem_cell;
    }
}

// 返回头元素
ElementType top(Stack S){
    if (!is_empty(S))
        return S->Next->Element;
    FatalError("Empty stack");
}

// pop 一个元素
void pop(Stack S){
    PtrToNode first_cell;
    if (is_empty(S))
        FatalError("Empty stack");
    else{
        first_cell = S->Next;
        S->Next = S->Next->Next;
        free(first_cell);
    }
}