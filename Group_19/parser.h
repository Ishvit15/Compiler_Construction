/*
GROUP NO. 19
ID: 2019B3A70545P  Name: ANIMESH BHARGAVA
ID: 2019B5A70226P  Name: ISHVIT BHASIN
ID: 2019B2A70878P  Name: RITIK THAKUR
ID: 2019B3A70154P  Name: SAHIL GUPTA
ID: 2019B4A70704P  Name: UTKARSH YASHVARDHAN
*/
#include "parseDef.h"
#include "tree.h"


grammarSymbol symbolOf(char *c);
rhsOfGrammarRuleNode *sym_Insert(char arr[]);
void printGrammar(rhsOfGrammarRuleNode *n);
void populateGrammar();
void firstSetOfRule(rhsOfGrammarRuleNode *rhs1, bool *fs);
void generateFirstSets();
void printFirstSets();
void generateFollowSet();
void printFollowSet(int i);
void createPT();
treeNode *parseUserSourceCode(FILE *fp);
void printParseTreeNode(treeNode *rootTreeNode);
void printParseTree(treeNode *rootTreeNode);
void initParser(FILE *fp, int len, char* fn);