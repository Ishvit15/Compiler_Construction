/* 
GROUP NO. 19
ID: 2019B3A70545P  Name: ANIMESH BHARGAVA 
ID: 2019B5A70226P  Name: ISHVIT BHASIN 
ID: 2019B2A70878P  Name: RITIK THAKUR 
ID: 2019B3A70154P  Name: SAHIL GUPTA
ID: 2019B4A70704P  Name: UTKARSH YASHVARDHAN
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// #include "lexerDef.h"

typedef struct stackNode {
    void* symbol;
    struct stackNode* next;
    struct stackNode* prev;
} stackNode;

typedef struct stack {
    stackNode* top;
} stack;

stack* createStack();
void push(stack* stack, void* symbol);
void* pop(stack* stack);
bool isEmpty(stack* stack);
