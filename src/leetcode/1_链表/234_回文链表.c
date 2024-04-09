//
// Created by EthanWhite on 2024/2/7.
// 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode * reverseList(struct ListNode * head){
    if(!head || !head->next){
        return head;
    }
    struct ListNode * newNode = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newNode;
}

bool isPalindrome(struct ListNode* head) {
    // 使用快慢指针找到链表的中点
    struct ListNode * slow = head;
    struct ListNode * fast = head;
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    // 反转后半部分的链表
    struct ListNode * rightReversed = reverseList(slow);

    // 判断反转后的后半部分链表是否与前半部分链表相同
    struct ListNode * leftPos = head;
    struct ListNode * rightPos = rightReversed;
    while (leftPos && rightPos){
        if(leftPos->val != rightPos->val){
            return false;
        }
        leftPos = leftPos->next;
        rightPos = rightPos->next;
    }
    return true;
}
