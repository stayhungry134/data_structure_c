//
// Created by stayh on 2023/9/20.
//
/// 使用数组实现一个栈，如果 TopOfStack 为 -1 则为空
#ifndef DATA_STRUCTURE_STACK_LIST_H
#define DATA_STRUCTURE_STACK_LIST_H
struct StackRecord;
typedef struct StackRecord * Stack;

typedef int ElementType;


// 判断是否为空
int is_empty(Stack S);
// 判断是否满了
int is_full(Stack S);
// 创建一个栈
Stack create_stack(int MaxElements);
// 释放一个栈
void dispose_stack(Stack S);
// 栈置空
void make_empty(Stack S);
// push 一个元素
void push(ElementType X, Stack S);
// 返回栈的 top
ElementType top(Stack S);
// pop 一个元素
void pop(Stack S);
// 返回栈的 top 并且 pop
ElementType top_and_pop(Stack S);

#endif //DATA_STRUCTURE_STACK_LIST_H
//
#define EmptyTOS (-1)
//
#define MinStackSize (5)

struct StackRecord{
    // 栈的容量
    int Capacity;
    // 栈顶
    int TopOfStack;
    // 栈的数组
    ElementType *Array;
};