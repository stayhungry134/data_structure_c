//
// Created by Ethan on 2023/9/28.
//
#include "search_tree.h"
#include "stdio.h"
#include "stdlib.h"


// 二叉树置空
SearchTree make_empty(SearchTree T){
    if (T != NULL){
        make_empty(T->left);
        make_empty(T->Right);
        free(T);
    }
    return NULL;
}

// 查找元素
Position find(ElementType X, SearchTree T){
    if (T == NULL){
        return NULL;
    }
    if (X < T->Element){
        return find(X, T->left);
    } else if (X > T->Element){
        return find(X, T->Right);
    } else{
        return T;
    }
}

// 查找最小元素（递归实现
Position find_min(SearchTree T){
    if (T == NULL){
        return NULL;
    } else if (T->left == NULL){
        return T;
    } else{
        return find_min(T->left);
    }
}

// 查找最大元素（非递归实现）
Position find_max(SearchTree T){
    if (T != NULL){
        while (T->Right != NULL){
            T = T->Right;
        }
    }
    return T;
}

// 插入元素
SearchTree insert(ElementType X, SearchTree T){
    if (T == NULL){
        T = malloc(sizeof(struct SearchTreeNode));
        if (T == NULL){
            printf("Out of space");
            exit(1);
        } else{
            T->Element = X;
            T->left = T->Right = NULL;
        }
    } else if (X < T->Element){
        T->left = insert(X, T->left);
    } else if (X > T->Element){
        T->Right = insert(X, T->Right);
    }
    return T;
}

// 删除元素
/**
 * 这段代码的主要功能是删除二叉搜索树中的指定元素，并保持树的搜索树性质。
 * 如果要删除的元素存在于树中，它将被删除。
 * 如果要删除的元素有两个子节点，那么将找到右子树中的最小元素并将其值复制到当前节点，然后递归删除右子树中的最小元素。
 * 如果要删除的元素只有一个子节点或没有子节点，将直接删除该节点并用其子节点（如果有的话）替代它。
 * 最后，返回更新后的树。
 */
SearchTree delete(ElementType X, SearchTree T) {
    Position TmpCell;

    // 如果树为空，无法删除元素
    if (T == NULL) {
        printf("Element not found");
    }
        // 如果要删除的元素小于当前节点的元素值，递归到左子树继续查找并删除
    else if (X < T->Element) {
        T->left = delete(X, T->left);
    }
        // 如果要删除的元素大于当前节点的元素值，递归到右子树继续查找并删除
    else if (X > T->Element) {
        T->Right = delete(X, T->Right);
    }
        // 如果找到要删除的元素
    else if (T->left && T->Right) {
        // 找到右子树中最小的元素，并将其值复制到当前节点
        TmpCell = find_min(T->Right);
        T->Element = TmpCell->Element;
        // 在右子树中递归删除被复制的最小元素
        T->Right = delete(T->Element, T->Right);
    }
        // 如果要删除的节点只有一个子树或者没有子树
    else {
        TmpCell = T;
        if (T->left == NULL) {
            // 如果只有右子树，将当前节点替换为右子树
            T = T->Right;
        } else if (T->Right == NULL) {
            // 如果只有左子树，将当前节点替换为左子树
            T = T->left;
        }
        // 释放被删除的节点
        free(TmpCell);
    }
    // 返回更新后的树
    return T;
}

