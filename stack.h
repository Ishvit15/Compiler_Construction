#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lexerDef.h"

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