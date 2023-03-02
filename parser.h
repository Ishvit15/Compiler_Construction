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


