/**
 * name: 19_删除链表的倒数第 N 个节点
 * create_time: 2024/2/27 9:15
 * author: Ethan
 * 
 * Description: 
 */
#include <stddef.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // 创建一个虚拟头节点，以处理删除头节点的情况
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    // diff 表示现在的节点和后面跟着的节点之间相差的距离
    int diff = 0;
    struct ListNode * cur_node = dummy;
    struct ListNode * tail_node = dummy;
    while (cur_node->next != NULL){
        cur_node = cur_node->next;
        if (diff < n){
            diff ++;
        } else{
            tail_node = tail_node->next;
        }
    }
    // 删除倒数第 N 个节点
    tail_node->next = tail_node->next->next;

    // 释放虚拟头节点，并返回正确的头节点
    struct ListNode* new_head = dummy->next;
    free(dummy);

    return new_head;
}