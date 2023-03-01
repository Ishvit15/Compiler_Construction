#include "parseDef.h"
typedef struct treeNode {
    treeNode* parent;
    treeNode* brother;
    treeNode* leftMostChild;
    treeNode* rightMostChild;
    grammarSymbol symbol;
    int childCount;
} treeNode;

treeNode* createTreeNode(grammarSymbol symbol);
void addTreeNode(treeNode* root,  treeNode* child);