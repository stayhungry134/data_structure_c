//
// Created by Ethan on 2023/9/28.
//
/// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* reverseList(struct ListNode* head){
    // 如果链表为空或者只有一个节点
    if (!head || !head->next){
        return head;
    }
    struct ListNode * pre_cell;
    struct ListNode * next_cell;
    struct ListNode * position = head;
    while (position){
        pre_cell = position;
        next_cell = position->next;
        position = next_cell;
        next_cell->next = pre_cell;
    }
    return pre_cell;
}