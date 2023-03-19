/*
GROUP NO. 19
ID: 2019B3A70545P  Name: ANIMESH BHARGAVA
ID: 2019B5A70226P  Name: ISHVIT BHASIN
ID: 2019B2A70878P  Name: RITIK THAKUR
ID: 2019B3A70154P  Name: SAHIL GUPTA
ID: 2019B4A70704P  Name: UTKARSH YASHVARDHAN
*/

#include "tree.h"
#include <stdlib.h>

treeNode *createTreeNode(grammarSymbol symbol)
{
    treeNode *treeNode = (struct treeNode *)malloc(sizeof(struct treeNode));
    treeNode->brother = NULL;
    treeNode->childCount = 0;
    treeNode->leftMostChild = NULL;
    treeNode->parent = NULL;
    treeNode->rightMostChild = NULL;
    treeNode->symbol = symbol;
    treeNode->token.line_no = -1;
    treeNode->token.TK = DUMMY;
}

void addTreeNode(treeNode *root, treeNode *child)
{
    if (root->childCount == 0)
    {
        root->leftMostChild = child;
        root->rightMostChild = child;
    }
    else
    {
        root->rightMostChild->brother = child;
        root->rightMostChild = child;
    }
    root->childCount++;
}