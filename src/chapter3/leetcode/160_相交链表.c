//
// Created by Ethan on 2023/9/27.
//
#include "stdio.h"

/// 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    typedef struct ListNode * position;
    // 先找到尾结点，如果尾结点是一样的，那么就相交
    position tail_headA = headA;
    position tail_headB = headB;
    int len_a = 0, len_b = 0;
    while (tail_headA->next){
        tail_headA = tail_headA->next;
        len_a += 1;
    }
    while (tail_headB->next){
        tail_headB = tail_headB->next;
        len_b += 1;
    }
    if (tail_headA != tail_headB){
        return NULL;
    }
    // 计算两个长度之间的差值
    int diff_count = 0;
    position tem_a = headA, tem_b = headB;
    if (len_b > len_a){
        diff_count = len_b -len_a;
        while (diff_count > 0){
            tem_b = tem_b->next;
            diff_count -= 1;
        }
    } else{
        diff_count = len_a -len_b;
        while (diff_count > 0){
            tem_a = tem_a->next;
            diff_count -= 1;
        }
    }
    while (tem_a != tem_b){
        tem_a = tem_a->next;
        tem_b = tem_b->next;
    }
    return tem_b;
}

/**
 * 更简单的方法就是 两条链表一起遍历，当其中一条到达终点的时候，说明这一条是短的，可以让这一条短的重新指向另一个链表的开头
 * 当另一个比较长的链表到达链表尾的时候，就把它指向较短的那个链表，这样的话就能够保证这时候两个链表距离终点的位置是相同的。
 *
 */

struct ListNode *getIntersectionNode1(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    typedef struct ListNode *position;
    position a = headA, b = headB;
    while (a != b){
        if (!a){
            a = headB;
        } else{
            a=a->next;
        }
        if (!b){
            b = headA;
        } else{
            b=b->next;
        }
    }
    return a;
}