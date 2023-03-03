/* 
GROUP NO. 19
ID: 2019B3A70545P  Name: ANIMESH BHARGAVA 
ID: 2019B5A70226P  Name: ISHVIT BHASIN 
ID: 2019B2A70878P  Name: RITIK THAKUR 
ID: 2019B3A70154P  Name: SAHIL GUPTA
ID: 2019B4A70704P  Name: UTKARSH YASHVARDHAN
*/

#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"lexer.h"
#include"lexerDef.h"
#include"parseDef.h"

grammarSymbol symbolOf(char *c);
rhsOfGrammarRuleNode *sym_Insert(char arr[]);
void printGrammar(rhsOfGrammarRuleNode * n);
void populateGrammar();
void generateFirstSet();
void printFirstSet();
void createPT(rhsOfGrammarRuleNode *rules);


// CHECK IF THIS NEEDS TO BE ADDED
treeNode* parseUserSourceCode(FILE* fp);
