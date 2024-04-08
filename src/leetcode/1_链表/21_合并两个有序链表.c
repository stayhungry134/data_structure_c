/**
 * name: 21_合并两个有序链表
 * create_time: 2024/3/8 16:46
 * author: Ethan
 * 
 * Description: 
 */

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode * l1 = list1;
    struct ListNode * l2 = list2;
    struct ListNode * res = malloc(sizeof (struct ListNode));
    struct ListNode * cur = res;
    while (l1 || l2){
        if (!l1){
            res->next = l2;
            return res;
        } else if(!l2){
            res->next = l1;
            return res;
        }
        else if (l1->val > l2->val) {
            res->next = malloc(sizeof(struct ListNode));
            res->next->val = l2->val;
            l2 = l2->next;
        } else{
            res->next = malloc(sizeof(struct ListNode));
            res->next->val = l1->val;
            l1 = l1->next;
        }
        cur = cur->next;
    }
    return res;
}