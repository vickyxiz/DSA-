#include <stdio.h>
#include <stdlib.h>
#include "stack_array.h"
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
void push(struct Stack* stack, char item)
{
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %c\n", item);
        return;
    }
    stack->array[++stack->top] = item;
    printf("%c pushed to stack\n", item);
}
char pop(struct Stack* stack)
{
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from an empty stack\n");
        return CHAR_MIN;
    }
    return stack->array[stack->top--];
}
char peek(struct Stack* stack)
{
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek\n");
        return CHAR_MIN;
    }
    return stack->array[stack->top];
}