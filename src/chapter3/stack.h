//
// Created by stayh on 2023/9/20.
//
/// 实现一个栈。可以使用数组实现栈，也可以使用指针实现栈，如果使用好的编程原则，那么调用例程不必知道使用的是哪种方式
/// 这里使用链表实现一个栈
#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H
struct StackNode;
typedef struct StackNode * PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;


// 判断是否为空
int is_empty(Stack S);
// 创建一个栈
Stack create_stack(void);
//
void dispose_stack(Stack S);
// 栈置空
void make_empty(Stack S);
// push 一个元素
void push(ElementType X, Stack S);
// 返回栈的 top
ElementType top(Stack S);
// pop 一个元素
void pop(Stack S);
#endif //DATA_STRUCTURE_STACK_H

struct StackNode{
    ElementType Element;
    PtrToNode Next;
};