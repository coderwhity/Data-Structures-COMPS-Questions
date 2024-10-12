#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Define a stack structure for characters
typedef struct {
    int top;
    int capacity;
    char *array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Stack utility functions
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char item) {
    if (!isFull(stack))
        stack->array[++stack->top] = item;
}

char pop(Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '\0';
}

char peek(Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top];
    return '\0';
}

// Function to check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to return precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to reverse a string
void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    Stack* stack = createStack(strlen(infix));
    int k = 0;
    for (int i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) {  // If the character is an operand, add it to the result
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[k++] = pop(stack);
            }
            pop(stack);  // Pop '('
        } else if (isOperator(infix[i])) {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(infix[i])) {
                postfix[k++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }
    // Pop all remaining operators in the stack
    while (!isEmpty(stack)) {
        postfix[k++] = pop(stack);
    }
    postfix[k] = '\0';
    free(stack);
}

// Function to convert infix to prefix
void infixToPrefix(char* infix, char* prefix) {
    int len = strlen(infix);
    reverse(infix);

    // Swap '(' with ')' and vice versa
    for (int i = 0; i < len; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    char postfix[len + 1];
    infixToPostfix(infix, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}

// Main function to demonstrate infix to prefix conversion
int main() {
    char infix[100], prefix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);
    return 0;
}
