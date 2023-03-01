#include "tree.h"

treeNode* createTreeNode(grammarSymbol symbol) {
    treeNode* treeNode = (struct treeNode*)malloc(sizeof(treeNode));
    treeNode->brother = NULL;
    treeNode->childCount = 0;
    treeNode->leftMostChild = NULL;
    treeNode->parent = NULL;
    treeNode->rightMostChild = NULL;
    treeNode->symbol = symbol;
}

void addTreeNode(treeNode* root, treeNode* child) {
    if(root->childCount == 0) {
        root->leftMostChild = child;
        root->rightMostChild = child;
    }
    else {
        root->rightMostChild->brother = child;
        root->rightMostChild = child;
    }
    root->childCount++;
}