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

struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head) {
    // 得到链表的长度
    int len_L = 0;
    struct ListNode *cur = head;
    while (cur){
        len_L += 1;
        cur = cur->next;
    }
    
}