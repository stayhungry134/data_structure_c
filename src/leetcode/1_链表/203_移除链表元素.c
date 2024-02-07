//
// Created by Ethan on 2023/9/28.
//
/// 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。


struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode * tem_cell = head;
    while (tem_cell && tem_cell->next){
        if (tem_cell->next->val == val) {
            tem_cell->next = tem_cell->next->next;
        } else{
            tem_cell = tem_cell->next;
        }
    }
    // 这里这么写的原因是上面没有考虑到第一个节点的值就等于目标值的情况
    if (head && head->val == val){
        head = head->next;
    }
    return head;
}

struct ListNode* removeElements1(struct ListNode* head, int val){
    if (!head){
        return head;
    }
    // 考虑到第一个节点的值就等于目标值的情况
    while (head->val == val){
        head = head->next;
        if (!head){
            return head;
        }
    }
    struct ListNode * tem_cell = head;
    while (tem_cell->next){
        if (tem_cell->next->val == val) {
            tem_cell->next = tem_cell->next->next;
        } else{
            tem_cell = tem_cell->next;
        }
    }
    return head;
}

