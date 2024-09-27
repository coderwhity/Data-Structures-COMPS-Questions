#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to get the precedence of operators
int getPrec(char c) {
	switch(c) {
	case '^':  // Highest precedence for exponentiation
		return 3;
	case '*':  // Multiplication and Division have medium precedence
	case '/':
		return 2;
	case '+':  // Addition and Subtraction have the lowest precedence
	case '-':
		return 1;
	default:   // For any other character (like '(' or invalid operators)
		return 0;
	}
}

int main() {
	// Example infix expression
	char exp[] = "A+B*(C^D-E)^(F+G*H)-I";
	
	char stk[100];  // Stack to hold operators and parentheses
	char post[100]; // Array to hold the final postfix expression
	int top1 = -1;  // Top pointer for the stack
	int top2 = -1;  // Top pointer for the postfix array

	// Loop through each character in the infix expression
	for (int i = 0; i < strlen(exp); i++) {
		// If the character is an operand (alphabet or digit), add it to the postfix expression
		if (isalnum(exp[i])) {
			post[++top2] = exp[i];
		} 
		else {
			// If it's a left parenthesis, push it onto the stack
			if (exp[i] == '(') {
				stk[++top1] = exp[i];
			} 
			// If it's a right parenthesis, pop and output from the stack until a left parenthesis is encountered
			else if (exp[i] == ')') {
				while (stk[top1] != '(') {
					post[++top2] = stk[top1--];
				}
				top1--; // Pop the '(' from the stack (discard it)
			} 
			else {
				// While the precedence of the top of the stack is higher or equal to the current operator
				// pop operators from the stack and add them to the postfix expression
				while (top1 != -1 && getPrec(stk[top1]) >= getPrec(exp[i])) {
					post[++top2] = stk[top1--];
				}
				// Push the current operator onto the stack
				stk[++top1] = exp[i];
			}
		}
	}

	// Pop all remaining operators from the stack and add them to the postfix expression
	while (top1 != -1) {
		post[++top2] = stk[top1--];
	}

	// Output the resulting postfix expression
	printf("Postfix Expression: %s\n", post);

	return 0;
}
