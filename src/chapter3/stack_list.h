//
// Created by stayh on 2023/9/20.
//
/// 使用数组实现一个栈，如果 TopOfStack 为 -1 则为空
#ifndef DATA_STRUCTURE_STACK_LIST_H
#define DATA_STRUCTURE_STACK_LIST_H
struct StackRecord;
typedef struct StackRecord * Stack;

typedef int ElementType;

int is_empty(Stack S);  // 判断是否为空
int is_full(Stack S);   // 判断是否满了
Stack create_stack(int MaxElements);    // 创建一个栈
void dispose_stack(Stack S);    // 释放一个栈
void make_empty(Stack S);   // 栈置空
void push(ElementType X, Stack S);  // push 一个元素
ElementType top(Stack S);   // 返回栈的 top
void pop(Stack S);  // pop 一个元素
ElementType top_and_pop(Stack S);   // 返回栈的 top 并且 pop
#endif //DATA_STRUCTURE_STACK_LIST_H

#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord{
    int Capacity;   // 栈的容量
    int TopOfStack; // 栈顶
    ElementType *Array; // 栈的数组
};