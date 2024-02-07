//
// Created by Ethan on 2023/9/28.
//
/// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* error_reverseList(struct ListNode* head){
    // 如果链表没有元素或者只有一个元素
    if(!head || !head->next){
        return head;
    }
    struct ListNode * pre_node = head;
    struct ListNode * cur_node = head->next;
    struct ListNode * next_node = cur_node->next;
    while (next_node){
        cur_node->next = pre_node;
        pre_node = cur_node;
        cur_node = next_node;
        next_node = cur_node->next;
    }
    return pre_node;
}

/** 在你提供的代码中，反转链表的过程看起来是正确的，
 * 但是在循环结束后， 需要将原链表的最后一个节点指向 NULL，以防止出现环。这个步骤似乎被遗漏了
 * */

struct ListNode* reverseList(struct ListNode* head) {
    // 如果链表没有元素或者只有一个元素
    if (!head || !head->next) {
        return head;
    }
    struct ListNode* pre_node = head;
    struct ListNode* cur_node = head->next;
    struct ListNode* next_node = cur_node->next;
    pre_node->next = NULL; // 将原链表的头结点指向 NULL
    while (next_node) {
        cur_node->next = pre_node;
        pre_node = cur_node;
        cur_node = next_node;
        next_node = cur_node->next;
    }
    // 循环结束时，cur_node 指向最后一个节点
    cur_node->next = pre_node; // 最后一个节点指向倒数第二个节点
    return cur_node; // 返回新的头结点
}


// 力扣 优秀解法
struct ListNode* reverseListDemo(struct ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct ListNode *newNode=reverseListDemo(head->next);
    head->next->next=head;
    head->next=NULL;
    return newNode;
}