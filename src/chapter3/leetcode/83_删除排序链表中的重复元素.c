//
// Created by Ethan on 2023/9/27.
//
/// 给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
#include "stdio.h"

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* deleteDuplicates(struct ListNode* head){
    if (!head){
        return head;
    }
    struct ListNode * tem_cell = head;
    while (tem_cell->next){
        if (tem_cell->val == tem_cell->next->val) {
            tem_cell->next = tem_cell->next->next;
        } else{
            tem_cell = tem_cell->next;
        }
    }
    return head;
}
