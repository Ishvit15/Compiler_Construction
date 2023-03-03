/* 
GROUP NO. 19
ID: 2019B3A70545P  Name: ANIMESH BHARGAVA 
ID: 2019B5A70226P  Name: ISHVIT BHASIN 
ID: 2019B2A70878P  Name: RITIK THAKUR 
ID: 2019B3A70154P  Name: SAHIL GUPTA
ID: 2019B4A70704P  Name: UTKARSH YASHVARDHAN
*/

#include "parser.h";
#include "parseDef.h"
#include "tree.h"
#include "stack.h"
#include "lexer.h"

treeNode* parseUserSourceCode(FILE* fp) {
    bool errorOccured = false;
    stack* stack = createStack();
    struct stack* auxStack = createStack();
    grammarSymbol eofSymbol;
    eofSymbol.isTerminal = true;
    eofSymbol.tno = END_OF_FILE;
    grammarSymbol startSymbol;
    startSymbol.isTerminal = false;
    startSymbol.ntno = program;
    treeNode* rootTreeNode = createTreeNode(startSymbol);
    treeNode* eofTreeNode = createTreeNode(eofSymbol);
    push(stack, eofTreeNode);
    push(stack, rootTreeNode);
    TOKEN token = getNextToken(fp);
    while(token.TK == COMMENTMARK)
        token = getNextToken(fp);
    while(stack->top != NULL) {
        treeNode* stackTop = pop(stack);
        if(stackTop->symbol.isTerminal == false) {
            int grammarRuleNo = parseTable[stackTop->symbol.ntno][token.TK];
            if(grammarRule == NO_MATCH) {
                if(findElementInSet(firstSet[stackTop->symbol.ntno], EPSILON) == false) {
                    errorOccured = true;
                    printf("Error: Stack Top is %s and Token encountered is ", enumToNonTerminal[stackTop->symbol.ntno]);
                    if(token.TK == NUM)
                        printf("%d", token.value_if_int);
                    else if(token.TK == RNUM)
                        printf("%f", token.value_if_float);
                    else
                        printf("%s", token.lexeme);
                    printf(" (Line no. - %d)\n", token.line_no);
                }
                while(findElementInSet(followSet[stackTop->symbol.ntno], EPSILON) == false) {
                    if(token.TK == LEXICAL_ERROR_1)
                        printf("Identifier length is greater than 20 (Line No. - %d)\n", token.line_no);
                    else if(token.TK == LEXICAL_ERROR_2)
                        printf("Unidentified token found :- %s (Line No. - %d)", token.lexeme, token.line_no);
                    else {
                        printf("Error: Stack Top is %s and Token encountered is ", enumToNonTerminal[stackTop->symbol.ntno]);
                        if(token.TK == NUM)
                            printf("%d", token.value_if_int);
                        else if(token.TK == RNUM)
                            printf("%f", token.value_if_float);
                        else
                            printf("%s", token.lexeme);
                        printf(" (Line no. - %d)\n", token.line_no);
                    }
                    token = getNextToken(fp);
                    while(token.TK == COMMENTMARK)
                        token = getNextToken(fp);
                    if(token.TK == END_OF_FILE) {
                        printf("End of Parser along with errors\n");
                        return rootTreeNode;
                    }
                }
            }
            else {
                grammarRule gRule = grammar[grammarRuleNo];
                rhsOfGrammarRuleNode* node = gRule.head;
                while(node != NULL) {
                    treeNode* treeNode = createTreeNode(gRule.head->symbol);
                    addTreeNode(stackTop, treeNode);
                    if(!treeNode->symbol.isTerminal || treeNode->symbol.tno == EPSILON)
                        push(auxStack, treeNode);
                    node = node->next;
                }
                while(auxStack->top != NULL) {
                    push(stack, auxStack->top);
                    pop(auxStack);
                }
            }
        }
    }

}
