#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define MAX_SIZE 100

typedef struct {
    char stack[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char element) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->stack[++s->top] = element;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[s->top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    return 0;  // Assuming '(' has the lowest precedence
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack operatorStack;
    initialize(&operatorStack);
    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        char currentChar = infix[i];

        if (isalnum(currentChar)) {
            postfix[j++] = currentChar;
        } else if (currentChar == '(') {
            push(&operatorStack, currentChar);
        } else if (currentChar == ')') {
            while (operatorStack.top != -1 && operatorStack.stack[operatorStack.top] != '(') {
                postfix[j++] = pop(&operatorStack);
            }
            if (operatorStack.top != -1 && operatorStack.stack[operatorStack.top] == '(') {
                pop(&operatorStack); // Pop '(' from stack
            } else {
                printf("Mismatched parentheses\n");
                exit(EXIT_FAILURE);
            }
        } else if (isOperator(currentChar)) {
            while (operatorStack.top != -1 && precedence(operatorStack.stack[operatorStack.top]) >= precedence(currentChar)) {
                postfix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, currentChar);
        } else {
            printf("Invalid character in infix expression: %c\n", currentChar);
            exit(EXIT_FAILURE);
        }

        i++;
    }

    // Pop any remaining operators from the stack
    while (operatorStack.top != -1) {
        if (operatorStack.stack[operatorStack.top] == '(') {
            printf("Mismatched parentheses\n");
            exit(EXIT_FAILURE);
        }
        postfix[j++] = pop(&operatorStack);
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression
}

int main() {
    char infix[100], postfix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
