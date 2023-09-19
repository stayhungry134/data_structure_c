//
// Created by Ethan on 2023/9/19.
//
///代码开头有一个条件编译指令 #ifndef _List_H，它用于防止多次包含（包含保护），确保头文件只被包含一次。如果 DATA_STRUCTURE_LIST_H
/// 这个宏没有被定义（即第一次包含头文件），则代码会继续执行，否则将被跳过。
/// 就是编译的时候，防止多次包含这个头文件导致的多次编译，多次编译会出错
#ifndef DATA_STRUCTURE_LIST_H
#define DATA_STRUCTURE_LIST_H
// 这里先声明一个自定义结构类型，也就是链表的节点Node，然后在后面定义这个节点类型的组成定义
struct Node;
// typedef 的意思就是，创建一个名为 PtrToNode 的新类型别名，它代表一个指向 struct Node 结构体的指针类型。
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
/// 上面代码中，struct Node* 表示的是，一个指向 自定义节点类型 Node 的指针，就是它是一个指针，而它只能指向 Node 这个类型
/// 然后给他们配置别名，这里配置了 List 和 Position 别名，是一样的结果，只是为了区分，
/// List L 表示 L 是一个指向链表的头节点的指针，可以说它代表整个链表。链表的头节点通常用来引导整个链表，通过头节点，你可以访问链表中的所有节点。
/// 而 Position P 表示的是指向链表中的某一个节点的指针，这样使用两个别名来定义更容易辨别和区分。
// 这里表示这是一个链表，ElementType 表示链表中值的类型，表示 ElementType 为int类型
typedef int ElementType;

// 置空链表
List makeEmpty(List L);
// 判断链表是否为空
int is_empty(List L);
// 判断链表是否为最后一个节点
int is_last(Position P, List L);
// 查找链表中的某个值
Position find(ElementType X, List L);
// 删除链表中的某个值
void delete(ElementType X, List L);
// 找到某个节点的前驱节点
Position find_previous(ElementType X, List L);
// 插入一个值
void insert(ElementType X, List L, Position P);
// 删除整个链表
void delete_list(List L);
// 返回链表的头节点
Position header(List L);
// 返回链表的第一个节点
Position first(List L);
// 获取 P 节点的元素值
ElementType retrieve(Position P);
#endif //DATA_STRUCTURE_LIST_H

// 这里定义了一个链表的节点，包含了一个值和一个指向下一个节点的指针
struct Node{
    ElementType  Element;
    Position Next;
};

