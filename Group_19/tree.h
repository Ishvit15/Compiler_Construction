/*
GROUP NO. 19
ID: 2019B3A70545P  Name: ANIMESH BHARGAVA
ID: 2019B5A70226P  Name: ISHVIT BHASIN
ID: 2019B2A70878P  Name: RITIK THAKUR
ID: 2019B3A70154P  Name: SAHIL GUPTA
ID: 2019B4A70704P  Name: UTKARSH YASHVARDHAN
*/

#include "parseDef.h"
typedef struct treeNode
{
    struct treeNode *parent;
    struct treeNode *brother;
    struct treeNode *leftMostChild;
    struct treeNode *rightMostChild;
    grammarSymbol symbol;
    TOKEN token;
    int childCount;
} treeNode;

treeNode *createTreeNode();
void addTreeNode(treeNode *root, treeNode *child);