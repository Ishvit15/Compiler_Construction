/*
GROUP NO. 19
ID: 2019B3A70545P  Name: ANIMESH BHARGAVA
ID: 2019B5A70226P  Name: ISHVIT BHASIN
ID: 2019B2A70878P  Name: RITIK THAKUR
ID: 2019B3A70154P  Name: SAHIL GUPTA
ID: 2019B4A70704P  Name: UTKARSH YASHVARDHAN
*/

#include "stack.h"

stack* createStack() {
    stack* stack = (struct stack*)malloc(sizeof(stack));
    stack->top = NULL;
    return stack;

}
void push(stack* stack, void* symbol) {
    stackNode* stackNode = (struct stackNode*)malloc(sizeof(stackNode));
    stackNode->symbol = symbol;
    stackNode->next = NULL;
    stackNode->prev = NULL;
    if(stack->top != NULL) {
        stackNode->prev = stack->top;
        stack->top = stackNode;
    }
    stack->top = stackNode;
}

void* pop(stack* stack) {
    if(stack->top == NULL) {
        printf("Stack is empty!\n");
        return NULL;
    }
    stackNode* poppedNode = stack->top;
    stack->top = stack->top->prev;
    void* symbol = poppedNode->symbol;
    free(poppedNode);
    return symbol;
}

bool isEmpty(stack* stack) {
    if(stack->top == NULL)
        return true;
    return false;
}