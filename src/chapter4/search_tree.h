//
// Created by stayh on 2023/9/27.
//

#ifndef DATA_STRUCTURE_SEARCH_TREE_H
#define DATA_STRUCTURE_SEARCH_TREE_H
struct SearchTreeNode;
typedef struct SearchTreeNode *Position;
typedef struct SearchTreeNode *SearchTree;

typedef int ElementType;

SearchTree make_empty(SearchTree T);
Position find(ElementType X, SearchTree T);
Position find_min(SearchTree T);
Position find_max(SearchTree T);
SearchTree insert(ElementType X, SearchTree T);
SearchTree delete(ElementType X, SearchTree T);
ElementType retrieve(Position P);
#endif //DATA_STRUCTURE_SEARCH_TREE_H

struct SearchTreeNode{
    ElementType Element;
    SearchTree left;
    SearchTree Right;
};
