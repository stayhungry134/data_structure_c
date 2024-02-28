//
// Created by stayh on 2024/2/19.
//

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include "stdint.h"
struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

int* postorder(struct Node* root, int* returnSize) {
    // 如果根节点为空，则直接返回空指针和大小为0
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    // 初始化一个数组，用于存放遍历结果，最多10000个元素
    int *res = (int *)malloc(sizeof(int) * 10000);
    int top = 0; // 标记res数组中的下一个位置

    // 使用栈来模拟后序遍历的过程
    struct Node *stack[10000]; // 定义一个大小为10000的指针数组作为栈
    int stackTop = 0; // 标记栈顶位置
    stack[stackTop++] = root; // 将根节点入栈

    // 进行栈模拟的后序遍历
    while (stackTop > 0) { // 栈不为空时进行循环
        struct Node *node = stack[--stackTop]; // 弹出栈顶元素
        res[top++] = node->val; // 将弹出的节点值存入结果数组中

        // 将当前节点的子节点按照从左到右的顺序入栈
        for (int i = 0; i < node->numChildren; i++) {
            stack[stackTop++] = node->children[i];
        }
    }

    // 由于是后序遍历，需要将结果数组逆序处理
    int *result = (int *)malloc(sizeof(int) * top); // 初始化一个大小为top的新数组
    for (int i = 0; i < top; i++) { // 将res数组中的元素逆序存入result数组中
        result[i] = res[top - i - 1];
    }

    // 更新返回结果的大小
    *returnSize = top;
    // 返回结果数组指针
    return result;
}
