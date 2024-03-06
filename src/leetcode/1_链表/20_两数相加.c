/**
 * name: 20_两数相加
 * create_time: 2024/3/5 9:55
 * author: Ethan
 * 
 * Description: 
 */
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // 创建一个新链表
    struct ListNode * head = malloc(sizeof (struct ListNode));
    // 指示一个指针指向上面创建的链表的头结点
    struct ListNode * cur = head;
    // 定义进位
    int carry = 0;
    while(l1 || l2){
        // 计算 L1 和 L2 还有进位的和
        int sum = carry;
        if(l1){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2){
            sum += l2->val;
            l2 = l2->next;
        }
        // 求出进位还有模运算的值，最后赋值给一个新的结点，结点接在新链表的后面
        carry = sum / 10;
        cur->next = malloc(sizeof (struct ListNode));
        cur->next->val = sum % 10;
        cur = cur->next;
    }
    // 全部循环结束，如果还有 那么就要再接入一个节点
    if(carry > 0){
        cur->next = malloc(sizeof (struct ListNode));
        cur->next->val = carry;
        cur->next->next = NULL;
    } else {
        cur->next = NULL;
    }
    // 删除第一个为 NULL 的节点
    struct ListNode * temp = head;
    head = head->next;
    free(temp);
    return head;
}