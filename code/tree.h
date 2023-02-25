#include "parserDef.h"
typedef struct treeNode {
    treeNode* parent;
    treeNode* brother;
    treeNode* leftMostChild;
    treeNode* rightMostChild;
    grammarSymbol symbol;
    int childCount;
} treeNode;

treeNode* createTreeNode();
void addTreeNode(treeNode* root,  grammarSymbol symbol);