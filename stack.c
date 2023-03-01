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