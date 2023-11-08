#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};
struct Stack* createStack(unsigned capacity);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, char item);
char pop(struct Stack* stack);
char peek(struct Stack* stack);
#endif