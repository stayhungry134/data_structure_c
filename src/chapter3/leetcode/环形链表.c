//
// Created by Ethan on 2023/9/27.
//
#include "stdbool.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * 给你一个链表的头节点 head ，判断链表中是否有环。
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
 * 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
 * 注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
 * 如果链表中存在环 ，则返回 true 。 否则，返回 false 。
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (!head){
        return false;
    }
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow){
            return true;
        }
    }
    return false;
}

/// 见到一个 0ms 的解法，算是钻了题目的空子，
/// 遍历到的时候把节点加一个大于题目给定范围的数，后续的遍历中把节点的值和这个大范围的数做比较，
/// 如果超过这个数，就说明之前来过，因为原始的数不会有这么大，只有可能是之前来过，然后加上了一个数
bool hasCycle1(struct ListNode *head) {
    int large = 100001;
    while (head){
        if (head->val > large){
            return true;
        }
        head->val += large;
        head = head->next;
    }
    return false;
}