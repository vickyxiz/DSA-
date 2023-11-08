
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack_array.h"
#include "stack_array.c"
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
int precedence(char ch) {
    if(ch == '^') 
        return 3; 
    else if(ch == '*' || ch == '/') 
        return 2; 
    else if(ch == '+' || ch == '-') 
        return 1; 
    else
        return -1; 
}
void infixToPostfix(char* exp) {
    int i, k;
    struct Stack* stack = createStack(strlen(exp));
    if (!stack)
        return;
    for (i = 0, k = -1; exp[i]; ++i) {
        if (isalnum(exp[i]))
            exp[++k] = exp[i];
        else if (exp[i] == '( ')
            push(stack, exp[i]);
        else if (exp[i] == ')'){
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            pop(stack);  
        }else{
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }
    while (!isEmpty(stack))
        exp[++k] = pop(stack);

    exp[++k] = '\0';
    printf("Postfix: %s", exp);
}
int main(){
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    printf("Infix: %s\n", exp);
    infixToPostfix(exp);
    return 0;
}