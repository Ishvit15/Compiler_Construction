/* 
GROUP NO. 19
ID: 2019B3A70545P  Name: ANIMESH BHARGAVA 
ID: 2019B5A70226P  Name: ISHVIT BHASIN 
ID: 2019B2A70878P  Name: RITIK THAKUR 
ID: 2019B3A70154P  Name: SAHIL GUPTA
ID: 2019B4A70704P  Name: UTKARSH YASHVARDHAN
*/

#include "parserDef.h"
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
